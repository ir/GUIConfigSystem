#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <filesystem>
#include <algorithm>

#ifdef _WIN32
#include <direct.h>
#include <stdlib.h>  // for _dupenv_s
#endif

namespace fs = std::filesystem;

// --- LogLevel Enum ---
enum class LogLevel { Info, Warning, Error };

inline std::string to_string(LogLevel level) {
    switch (level) {
    case LogLevel::Info:    return "INFO";
    case LogLevel::Warning: return "WARNING";
    case LogLevel::Error:   return "ERROR";
    default:                return "UNKNOWN";
    }
}

// --- LogEntry Struct ---
struct LogEntry {
    LogLevel level = LogLevel::Error;
    std::string message; // Already formatted with timestamp & level
};

// --- Logger Class ---
class logger {
public:
    // Get the singleton instance.
    static logger& get_instance() {
        static logger instance;
        return instance;
    }

    // Public interface that enqueues log messages.
    void log(LogLevel level, const std::string& message) {
        // Build the formatted message (timestamp + level + message)
        std::string formatted = format_log_message(level, message);
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            message_queue_.push(LogEntry{ level, formatted });
        }
        queue_cv_.notify_one();

        // If the log level is Error, also output to std::cerr immediately.
        if (level == LogLevel::Error) {
            std::cerr << formatted << std::endl;
        }
    }

    // Convenience functions.
    void info(const std::string& message) { log(LogLevel::Info, message); }
    void warning(const std::string& message) { log(LogLevel::Warning, message); }
    void error(const std::string& message) { log(LogLevel::Error, message); }

    // Delete copy and move constructors.
    logger(const logger&) = delete;
    logger& operator=(const logger&) = delete;

private:
    // --- Configuration ---
    const std::size_t max_file_size_ = 10 * 512;  // 0.5 MB per file (example)
    const std::size_t max_log_files_ = 10;         // Maximum number of log files to keep

    // --- Members ---
    std::ofstream log_file_;
    std::string log_file_path_;
    std::mutex file_mutex_; // Guards log file rotation and writing

    // For asynchronous logging.
    std::queue<LogEntry> message_queue_;
    std::mutex queue_mutex_;
    std::condition_variable queue_cv_;
    bool exit_flag_ = false;
    std::thread worker_thread_;

    // Track the current log file size.
    std::size_t current_file_size_ = 0;

    // --- Constructor/Destructor ---
    logger() {
        create_log_directory();
        open_new_log_file();
        // Start the worker thread.
        worker_thread_ = std::thread(&logger::process_queue, this);
    }

    ~logger() {
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            exit_flag_ = true;
        }
        queue_cv_.notify_all();
        if (worker_thread_.joinable()) {
            worker_thread_.join();
        }
        if (log_file_.is_open()) {
            log_file_.flush();
            log_file_.close();
        }
    }

    // --- Helper Functions for Time Formatting ---
    // Returns a formatted string for the current time given a format string.
    std::string get_formatted_time(const char* format) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // Use thread-safe localtime if available.
#ifdef _WIN32
        tm timeInfo;
        localtime_s(&timeInfo, &now_time);
        std::ostringstream oss;
        oss << std::put_time(&timeInfo, format);
        return oss.str();
#else
        tm* timeInfo = std::localtime(&now_time);
        std::ostringstream oss;
        oss << std::put_time(timeInfo, format);
        return oss.str();
#endif
    }

    // Returns current timestamp for log messages.
    std::string current_time() {
        return get_formatted_time("%Y-%m-%d %H:%M:%S");
    }

    // Returns a timestamp used for log file naming.
    std::string get_timestamp() {
        return get_formatted_time("%Y%m%d_%H%M%S");
    }

    // Formats a log message with timestamp and level.
    std::string format_log_message(LogLevel level, const std::string& message) {
        std::ostringstream oss;
        oss << "[" << current_time() << "] "
            << "[" << to_string(level) << "] "
            << message;
        return oss.str();
    }

    std::string get_log_directory() {
        char* appdata_path = nullptr;
        size_t buffer_size = 0;

        if (_dupenv_s(&appdata_path, &buffer_size, "APPDATA") == 0 && appdata_path != nullptr) {
            std::string log_dir = std::string(appdata_path) + "/brasilhook/logs";
            free(appdata_path);

            // Ensure the log directory exists
            try {
                fs::create_directories(log_dir);
            }
            catch (const std::exception& e) {
                std::cerr << "[ERROR] Failed to create log directory: " << e.what() << std::endl;
            }

            return log_dir;
        }

        std::cerr << "[ERROR] Failed to retrieve %APPDATA% environment variable." << std::endl;
        return "";
    }

    void create_log_directory() {
        std::string dir = get_log_directory();
        if (!fs::exists(dir)) {
            fs::create_directories(dir);
        }
    }

    // Open a new log file (for example, when rotating).
    void open_new_log_file() {
        std::lock_guard<std::mutex> lock(file_mutex_);
        if (log_file_.is_open()) {
            log_file_.flush();
            log_file_.close();
        }
        // Before opening a new file, manage log files.
        manage_log_files();

        log_file_path_ = get_log_directory() + "\\log_" + get_timestamp() + ".txt";
        log_file_.open(log_file_path_, std::ios::out | std::ios::app);
        current_file_size_ = fs::exists(log_file_path_) ? fs::file_size(log_file_path_) : 0;
    }

    // Remove old log files, keeping only the latest max_log_files_.
    // This version sorts files in ascending order (oldest first)
    // and deletes files until fewer than max_log_files_ remain.
    void manage_log_files() {
        std::string log_dir = get_log_directory();
        std::vector<fs::directory_entry> log_files;

        try {
            // Gather all .txt log files in the log directory.
            for (const auto& entry : fs::directory_iterator(log_dir)) {
                if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                    log_files.push_back(entry);
                }
            }

            // Sort in ascending order so that the oldest file comes first.
            std::sort(log_files.begin(), log_files.end(), [](const fs::directory_entry& a, const fs::directory_entry& b) {
                return fs::last_write_time(a) < fs::last_write_time(b);
                });

            // While there are max_log_files_ or more, remove the oldest.
            while (log_files.size() >= max_log_files_) {
                try {
                    fs::remove(log_files.front().path());
                    log_files.erase(log_files.begin());
                }
                catch (const std::exception& e) {
                    std::cerr << "[" << current_time() << "] [ERROR] Failed to remove old log file: " << e.what() << std::endl;
                    break;
                }
            }
        }
        catch (const std::exception& e) {
            // In case of error, output to std::cerr.
            std::cerr << "[" << current_time() << "] [ERROR] Log rotation error: " << e.what() << std::endl;
        }
    }

    // --- Asynchronous Logging Worker ---
    void process_queue() {
        while (true) {
            LogEntry entry;
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                queue_cv_.wait(lock, [this] { return exit_flag_ || !message_queue_.empty(); });
                if (exit_flag_ && message_queue_.empty())
                    break;
                entry = message_queue_.front();
                message_queue_.pop();
            }

            // Write the log entry to file.
            write_to_file(entry.message);

            // Check if the file should be rotated.
            if (current_file_size_ >= max_file_size_) {
                open_new_log_file();
            }
        }
    }

    // Writes a message to the log file. Called only from the worker thread.
    void write_to_file(const std::string& text) {
        std::lock_guard<std::mutex> lock(file_mutex_);
        if (log_file_.is_open()) {
            log_file_ << text << std::endl;
            log_file_.flush();
            current_file_size_ += text.size() + 1; // +1 for newline
        }
        else {
            // If for some reason the file is not open, output an error.
            std::cerr << "[" << current_time() << "] [ERROR] Log file not open: " << log_file_path_ << std::endl;
        }
    }
};

#endif // LOGGER_H
