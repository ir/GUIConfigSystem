// config_manager.cpp

#include "config_manager.hpp"

#include <Windows.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <direct.h>
#include <sys/stat.h>
#include <cstdlib>
#include <unordered_map>
#include <filesystem>

//---------------------------------------------------------------------
// cheat_settings Implementation
//---------------------------------------------------------------------
nlohmann::json cheat_settings::toJson() const {
    nlohmann::json j;
    j["version"] = CONFIG_VERSION;
    j["config_name"] = config_name;
    j["b_aimbot"] = b_aimbot;
    j["i_aimfov"] = i_aimfov;
    j["f_smoothing"] = f_smoothing;
    j["b_esp"] = b_esp;
    j["b_espbox"] = b_espbox;
    j["style_idx"] = style_idx;
    return j;
}

void cheat_settings::fromJson(const nlohmann::json& j) {
    // Version can be used later for migration purposes.
    float vers = j.value("version", 0.0f);
    if (j.contains("config_name"))
        config_name = j["config_name"].get<std::string>();
    if (j.contains("b_aimbot"))
        b_aimbot = j["b_aimbot"].get<bool>();
    if (j.contains("i_aimfov"))
        i_aimfov = j["i_aimfov"].get<int>();
    if (j.contains("f_smoothing"))
        f_smoothing = j["f_smoothing"].get<float>();
    if (j.contains("b_esp"))
        b_esp = j["b_esp"].get<bool>();
    if (j.contains("b_espbox"))
        b_espbox = j["b_espbox"].get<bool>();
    if (j.contains("style_idx"))
        style_idx = j["style_idx"].get<int>();
}

std::string cheat_settings::toExportString() const {
    nlohmann::json j;
    j["settings"] = toJson();
    return j.dump(4);
}

void cheat_settings::migrate_config(nlohmann::json& j, float old_version) {
    // TODO: Implement config migration if needed.
    // For example:
    // if (old_version < 1.1f) { j["new_field"] = j["old_field"]; }
}

//---------------------------------------------------------------------
// config_manager Implementation
//---------------------------------------------------------------------
config_manager& config_manager::get_instance() {
    static config_manager instance;
    return instance;
}

cheat_settings* config_manager::_get_config_settings() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (current_config_name.empty())
        return nullptr;
    return &config_list[current_config_name];
}

cheat_settings* config_manager::get_current_settings() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (current_config_name.empty()) {
        logger::get_instance().error("Current config is empty");
        return nullptr;
    }
    return &config_list[current_config_name];
}

void config_manager::init_base_config() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string default_file_path = get_file_path("default");

    if (!std::filesystem::exists(default_file_path)) {
        cheat_settings default_config;  // default settings
        nlohmann::json j;
        j["settings"] = default_config.toJson();

        std::ofstream file(default_file_path);
        if (!file.is_open()) {
            logger::get_instance().error("Failed to open file for writing: " + default_file_path);
            return;
        }
        file << j.dump(4);
        if (!file.good()) {
            logger::get_instance().error("Failed to write to file: " + default_file_path);
            return;
        }
        logger::get_instance().info("Created default.json with default settings");
    }
}

bool config_manager::create_config(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string new_config_name = config_name;
    int count = 1;

    // Ensure the config name is unique.
    while (config_list.find(new_config_name) != config_list.end()) {
        size_t pos = new_config_name.find_last_not_of("0123456789");
        if (pos != std::string::npos && pos != new_config_name.length() - 1) {
            std::string base_name = new_config_name.substr(0, pos + 1);
            std::string num_str = new_config_name.substr(pos + 1);
            try {
                count = std::stoi(num_str) + 1;
            }
            catch (const std::invalid_argument&) {
                count = 1;
            }
            new_config_name = base_name + std::to_string(count);
        }
        else {
            new_config_name = config_name + std::to_string(count);
        }
        count++;
    }

    // Create the config.
    config_list[new_config_name] = cheat_settings();
    config_list[new_config_name].config_name = new_config_name;

    create_base_dir();
    std::string file_path = get_file_path(new_config_name);
    std::ofstream file(file_path);
    if (!file.is_open()) {
        logger::get_instance().error("Failed to create file for config: " + new_config_name);
        return false;
    }
    nlohmann::json j;
    j["settings"] = config_list[new_config_name].toJson();
    try {
        file << j.dump(4);
    }
    catch (const std::ofstream::failure& e) {
        logger::get_instance().error("Failed to write to config file: " + std::string(e.what()));
        return false;
    }
    logger::get_instance().info("Created config and saved to file: " + new_config_name);
    return true;
}

bool config_manager::delete_config(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (config_name == "default") {
        logger::get_instance().warning("Cannot delete the default config.");
        return false;
    }
    auto it = config_list.find(config_name);
    if (it == config_list.end()) {
        logger::get_instance().error("Config '" + config_name + "' not found.");
        return false;
    }
    std::string file_path = get_file_path(config_name);
    if (std::remove(file_path.c_str()) != 0) {
        logger::get_instance().error("Failed to delete config file: " + file_path);
        return false;
    }
    config_list.erase(it);

    // If the deleted config was active, choose a new active config.
    if (current_config_name == config_name) {
        if (!config_list.empty()) {
            // Choose the first available config (could default to a new empty config).
            current_config_name = config_list.begin()->first;
        }
        else {
            // Fallback (ideally default always exists)
            current_config_name = "default";
        }
        // Immediately apply the style from the new active config.
        cheat_settings* newActive = get_config_by_name(current_config_name);
        if (newActive) {
            apply_style(*newActive);
        }
        logger::get_instance().info("Switched to config: " + current_config_name + " after deletion.");
    }

    logger::get_instance().info("Deleted config: " + config_name);
    return true;
}



bool config_manager::load_config(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (config_list.find(config_name) == config_list.end()) {
        logger::get_instance().error("Config not found: " + config_name);
        return false;
    }
    std::string file_path = get_file_path(config_name);
    if (!std::filesystem::exists(file_path)) {
        logger::get_instance().error("Config file does not exist: " + file_path);
        return false;
    }
    std::ifstream file(file_path);
    if (!file.is_open()) {
        logger::get_instance().error("Failed to open config file: " + file_path);
        return false;
    }
    nlohmann::json j;
    try {
        file >> j;
    }
    catch (const nlohmann::json::exception& e) {
        logger::get_instance().error("Error reading JSON from config file: " + std::string(e.what()));
        return false;
    }
    if (!j.contains("settings")) {
        logger::get_instance().error("Config file missing 'settings' field: " + file_path);
        return false;
    }

    // (Todo) Check version and migrate if needed.
    float version = j["settings"].value("version", 0.0f);
    if (version < CONFIG_VERSION) {
        logger::get_instance().error("Invalid version detected");
        // Implement migration if required.
    }
    try {
        cheat_settings settings;
        settings.fromJson(j["settings"]);
        config_list[config_name] = settings;
        last_loaded_settings = settings;
        current_config_name = config_name;
        apply_style(settings);
        logger::get_instance().info("Successfully loaded config: " + config_name);
        return true;
    }
    catch (const std::exception& e) {
        logger::get_instance().error("Failed to parse 'settings' from config file: " + std::string(e.what()));
        return false;
    }
}

bool config_manager::save_config(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!dir_exists(get_base_dir())) {
        create_base_dir();
        logger::get_instance().warning("Creating base dir");
    }
    auto it = config_list.find(config_name);
    if (it == config_list.end()) {
        logger::get_instance().error("Config not found in the list: " + config_name);
        return false;
    }
    std::string file_path = get_file_path(config_name);
    std::ofstream file(file_path, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        logger::get_instance().error("Failed to open config file for saving: " + file_path);
        return false;
    }
    nlohmann::json j;
    nlohmann::json settings_json = it->second.toJson();
    settings_json["config_name"] = config_name;
    j["settings"] = settings_json;
    try {
        file << j.dump(4);
    }
    catch (const std::ofstream::failure& e) {
        logger::get_instance().error("Failed to write to config file: " + std::string(e.what()));
        return false;
    }
    logger::get_instance().info("Successfully saved config: " + config_name);
    return true;
}



bool config_manager::set_active_config(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (config_list.find(config_name) == config_list.end())
        return false;
    current_config_name = config_name;
    logger::get_instance().info("Switched to config: " + config_name);
    return true;
}

void config_manager::refresh_config_list() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string previous_current_config = current_config_name;
    cheat_settings previous_settings = last_loaded_settings;
    std::string base_dir = get_base_dir();
    if (!dir_exists(base_dir)) {
        logger::get_instance().error("Config directory does not exist: " + base_dir);
        return;
    }
    std::unordered_map<std::string, cheat_settings> new_config_list;
    try {
        for (const auto& entry : std::filesystem::directory_iterator(base_dir)) {
            if (entry.is_regular_file() && entry.path().extension() == ".json") {
                std::string config_name = entry.path().stem().string();
                std::ifstream file(entry.path());
                if (file.is_open()) {
                    nlohmann::json j;
                    file >> j;
                    if (j.contains("settings")) {
                        cheat_settings settings;
                        settings.fromJson(j["settings"]);
                        new_config_list[config_name] = settings;
                    }
                }
            }
        }
    }
    catch (const std::exception& e) {
        logger::get_instance().error("Error refreshing config list: " + std::string(e.what()));
        return;
    }
    // Update and remove outdated configs.
    for (const auto& [name, settings] : new_config_list) {
        if (config_list.find(name) == config_list.end() || config_list[name].config_name != settings.config_name) {
            config_list[name] = settings;
        }
    }
    auto it = config_list.begin();
    while (it != config_list.end()) {
        if (new_config_list.find(it->first) == new_config_list.end())
            it = config_list.erase(it);
        else
            ++it;
    }
    if (config_list.find(previous_current_config) != config_list.end()) {
        current_config_name = previous_current_config;
        last_loaded_settings = previous_settings;
    }
}

std::map<std::string, cheat_settings>& config_manager::get_config_list() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return config_list;
}

cheat_settings* config_manager::get_config_by_name(const std::string& config_name) {
    //std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& c : config_list) {
        if (c.first == config_name)
            return &c.second;
    }
    return nullptr;
}

bool config_manager::config_exists(const std::string& config_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    return config_list.find(config_name) != config_list.end();
}

std::string config_manager::get_cur_config_name() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return current_config_name;
}

bool config_manager::import_from_clipboard_and_create_new_config() {
    if (!OpenClipboard(nullptr)) {
        logger::get_instance().error("Failed to open clipboard.");
        return false;
    }
    struct ClipboardRAII {
        ~ClipboardRAII() { CloseClipboard(); }
    } clipboardGuard;

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (!hData) {
        logger::get_instance().error("Clipboard data is null.");
        return false;
    }
    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (!pszText) {
        logger::get_instance().error("Failed to lock clipboard data.");
        return false;
    }
    std::string clipboardData(pszText);
    GlobalUnlock(hData);

    if (clipboardData.empty()) {
        logger::get_instance().error("Clipboard is empty.");
        return false;
    }
    try {
        nlohmann::json j = nlohmann::json::parse(clipboardData);
        if (!j.contains("settings")) {
            logger::get_instance().error("Invalid clipboard format: missing 'settings' field.");
            return false;
        }
        cheat_settings settings;
        settings.fromJson(j["settings"]);
        std::string importedName = settings.config_name.empty() ? "default" : settings.config_name;
        std::string newConfigName = importedName;
        if (config_list.find(newConfigName) != config_list.end()) {
            std::string baseName = importedName;
            int count = 1;
            size_t pos = importedName.find_last_not_of("0123456789");
            if (pos != std::string::npos && pos + 1 < importedName.size()) {
                baseName = importedName.substr(0, pos + 1);
                try {
                    count = std::stoi(importedName.substr(pos + 1)) + 1;
                }
                catch (const std::exception&) {
                    count = 1;
                }
            }
            newConfigName = baseName + std::to_string(count);
            while (config_list.find(newConfigName) != config_list.end()) {
                ++count;
                newConfigName = baseName + std::to_string(count);
            }
        }
        settings.config_name = newConfigName;
        config_list[newConfigName] = settings;

        std::string file_path = get_file_path(newConfigName);
        std::ofstream file(file_path);
        if (!file.is_open()) {
            logger::get_instance().error("Failed to create file for config: " + newConfigName);
            return false;
        }
        nlohmann::json j_settings;
        j_settings["settings"] = settings.toJson();
        file << j_settings.dump(4);
        file.close();

        current_config_name = newConfigName;
        apply_style(settings);
        logger::get_instance().info("Successfully imported settings and created new config: " + newConfigName);
        return true;
    }
    catch (const nlohmann::json::exception& e) {
        logger::get_instance().error("Failed to parse clipboard data as JSON: " + std::string(e.what()));
        return false;
    }
    catch (const std::exception& e) {
        logger::get_instance().error("Exception during clipboard import: " + std::string(e.what()));
        return false;
    }
}

bool config_manager::import_from_clipboard() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (!OpenClipboard(nullptr)) {
        logger::get_instance().error("Failed to open clipboard.");
        return false;
    }
    struct ClipboardRAII {
        ~ClipboardRAII() { CloseClipboard(); }
    } clipboardGuard;

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (!hData) {
        logger::get_instance().error("Clipboard data is null.");
        return false;
    }
    char* pszText = static_cast<char*>(GlobalLock(hData));
    if (!pszText) {
        logger::get_instance().error("Failed to lock clipboard data.");
        return false;
    }
    std::string clipboardData(pszText);
    GlobalUnlock(hData);

    if (clipboardData.empty()) {
        logger::get_instance().error("Clipboard is empty.");
        return false;
    }
    try {
        nlohmann::json j = nlohmann::json::parse(clipboardData);
        if (!j.contains("settings")) {
            logger::get_instance().error("Invalid clipboard format: missing 'settings' field.");
            return false;
        }
        cheat_settings temp_settings;
        temp_settings.fromJson(j["settings"]);
        if (current_config_name.empty()) {
            logger::get_instance().error("No active configuration to update.");
            return false;
        }
        temp_settings.config_name = current_config_name;
        config_list[current_config_name] = temp_settings;
        apply_style(temp_settings);
        logger::get_instance().info("Successfully imported settings while preserving the current config name: " + current_config_name);
        return true;
    }
    catch (const nlohmann::json::exception& e) {
        logger::get_instance().error("Failed to parse clipboard data as JSON: " + std::string(e.what()));
    }
    catch (const std::exception& e) {
        logger::get_instance().error("Exception during clipboard import: " + std::string(e.what()));
    }
    return false;
}

void config_manager::copy_to_clipboard(const cheat_settings& settings) {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string s_settings = settings.toExportString();
    if (OpenClipboard(nullptr)) {
        EmptyClipboard();
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, s_settings.size() + 1);
        if (hMem) {
            char* pMem = (char*)GlobalLock(hMem);
            if (pMem) {
                memcpy(pMem, s_settings.c_str(), s_settings.size() + 1);
                GlobalUnlock(hMem);
                SetClipboardData(CF_TEXT, hMem);
                logger::get_instance().info("Successfully copied " + settings.config_name + " to clipboard");
            }
        }
        CloseClipboard();
    }
    else {
        logger::get_instance().error("Failed to open clipboard");
    }
}

bool config_manager::rename_config(const std::string& old_name, const std::string& new_name) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (old_name == "default") {
        logger::get_instance().info("Tried to rename default config");
        return false;
    }
    if (old_name == new_name) {
        logger::get_instance().info("Cannot rename to same name");
        return false;
    }
    auto it = config_list.find(old_name);
    if (it == config_list.end()) {
        logger::get_instance().error("Config '" + old_name + "' not found");
        return false;
    }
    if (config_list.find(new_name) != config_list.end()) {
        logger::get_instance().error("Config '" + new_name + "' already exists.");
        return false;
    }
    cheat_settings temp = it->second;
    config_list.erase(it);
    std::string old_file_path = get_file_path(old_name);
    std::string new_file_path = get_file_path(new_name);
    try {
        std::rename(old_file_path.c_str(), new_file_path.c_str());

        std::ifstream json_file(new_file_path);
        nlohmann::json json_data;
        json_file >> json_data;
        json_file.close();

        if (json_data.contains("settings")) {
            json_data["settings"]["config_name"] = new_name;
        }
        else {
            logger::get_instance().error("Missing 'settings' field");
            return false;
        }
        std::ofstream updated_json_file(new_file_path);
        updated_json_file << json_data.dump(4);
        updated_json_file.close();

        temp.config_name = new_name;
        config_list[new_name] = temp;

        if (current_config_name != old_name) {
            config_list[current_config_name] = last_loaded_settings;
        }
        else {
            current_config_name = new_name;
        }
        logger::get_instance().info("Renamed " + old_name + " to " + new_name);
        return true;
    }
    catch (const std::exception& e) {
        config_list[old_name] = temp;
        logger::get_instance().error("Rename failed: " + std::string(e.what()));
        return false;
    }
}

void config_manager::apply_style(const cheat_settings& settings) {
    StyleRegistry::get_instance().queue_style([settings]() {
        StyleManager::ApplyStyle(settings.style_idx);
    });
}

void config_manager::on_imgui_initialized() {
    StyleRegistry::get_instance().on_imgui_initialized();
    //logger::get_instance().log(LogLevel::Info,"successfully")
}

//---------------------------------------------------------------------
// Private Helper Functions
//---------------------------------------------------------------------
bool config_manager::dir_exists(const std::string& dir_path) const {
    struct _stat info;
    return (_stat(dir_path.c_str(), &info) == 0 && (info.st_mode & _S_IFDIR));
}

void config_manager::create_base_dir() const {
    std::string base_dir = get_base_dir();
    if (!dir_exists(base_dir)) {
        _mkdir(base_dir.c_str());
        logger::get_instance().info("Created config directory: " + base_dir);
    }
}

std::string config_manager::get_base_dir() const {
    char* appdata_path = nullptr;
    size_t buffer_size = 0;
    if (_dupenv_s(&appdata_path, &buffer_size, "APPDATA") == 0 && appdata_path != nullptr) {
        std::string base_dir = appdata_path;
        free(appdata_path);
        return base_dir + "\\brasilhook";
    }
    return ".\\brasilhook";
}

std::string config_manager::get_file_path(const std::string& config_name) const {
    return get_base_dir() + "\\" + config_name + ".json";
}
