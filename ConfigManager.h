#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H
#pragma once

#include <string>
#include <map>
#include <mutex>
#include "json.hpp"         // For nlohmann::json
#include "logger.hpp"       // For logging
#include "StyleManager.hpp" // For style application
#include "StyleRegistry.hpp"

const float CONFIG_VERSION = 1.0f;

struct cheat_settings {
    // ----- CONFIG -----
    std::string config_name = "default";
    // ----- INTERFACE -----
    int style_idx = 0; // UI style index
    // ----- AIMBOT -----
    bool b_aimbot = false;
    int i_aimfov = 30;
    float f_smoothing = 0.0f; // 0.0 -> 1.0
    // ----- ESP -----
    bool b_esp = false;
    bool b_espbox = false;
    

    /*
    * TODO 
    * KEYBINDS
    */

    // Convert settings to JSON format.
    nlohmann::json toJson() const;

    // Load settings from JSON.
    void fromJson(const nlohmann::json& j);

    // Export settings as a pretty-printed string.
    std::string toExportString() const;

    // (Optional) Migrate an older version of the config.
    void migrate_config(nlohmann::json& j, float old_version);
};

class config_manager {
public:
    // Singleton access.
    static config_manager& get_instance();


    // Configuration operations.
    std::map<std::string, cheat_settings>& get_config_list();
    cheat_settings* _get_config_settings(); // retarded
    cheat_settings* get_current_settings();
    cheat_settings* get_config_by_name(const std::string& config_name);

    void init_base_config();
    bool create_config(const std::string& config_name);
    bool delete_config(const std::string& config_name);
    bool load_config(const std::string& config_name);
    bool save_config(const std::string& config_name);
    bool set_active_config(const std::string& config_name);
    void refresh_config_list();
    bool config_exists(const std::string& config_name);
    std::string get_cur_config_name();

    // Clipboard operations.
    bool import_from_clipboard_and_create_new_config();
    bool import_from_clipboard();
    void copy_to_clipboard(const cheat_settings& settings); // export

    // Rename a config.
    bool rename_config(const std::string& old_name, const std::string& new_name);

    // UI style management.
    void apply_style(const cheat_settings& settings);
    void on_imgui_initialized();

private:
    // le singleton
    config_manager() = default;
    config_manager(const config_manager&) = delete;
    config_manager& operator=(const config_manager&) = delete;

    // Private members for storing state.
    cheat_settings last_loaded_settings;
    std::map<std::string, cheat_settings> config_list;
    std::string current_config_name;
    std::mutex m_mutex;

    // Filesystem helper functions.
    bool dir_exists(const std::string& dir_path) const;
    void create_base_dir() const;
    std::string get_base_dir() const;
    std::string get_file_path(const std::string& config_name) const;
};

#endif // CONFIG_MANAGER_H
