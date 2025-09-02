# GUIConfigSystem

JSON configuration manager for ImGui applications (C++17, Windows).

## Features
- Save / load config files (JSON).
- Versioned config files with a migration hook (TODO).
- Automatic default config creation.
- Import / export configs via clipboard.
- Rename, delete, refresh configs from the filesystem.
- Thread-safe access to config data (uses `std::mutex`).
- Style application hook for ImGui themes.
- Logging for operations and errors (`logger::get_instance()`).
- Custom styling & themes (includes Vullmad, my Mullvad VPN inspired theme)

## Files
- `ConfigManager.h` / `ConfigManager.cpp` - main config manager and `cheat_settings` serialization. (cheat_settings is an example in this case and only acts as a template)
- `StyleList.hpp` / `StyleList.cpp` - style definitions.
- `StyleRegistry.hpp` - style registration / queuing for ImGui.
- `StyleManager.hpp` - links styles and handles applying
- `logger.hpp` — logging helper (used extensively by manager).
- `json.hpp` — bundled single-header nlohmann::json.

## Dependencies
- C++17 (or newer recommended).
- `nlohmann::json` (header already included as `json.hpp`).
- Windows API (clipboard, `Windows.h`, environment APIs). The current code uses Windows-specific APIs.
- Standard library: `<filesystem>`, `<mutex>`, `<fstream>`, etc.

## Very Simply Usage Guide (API overview)
```cpp
#include "config_manager.hpp"
#include <iostream>

int main()
{
    // Get singleton manager
    auto &mgr = config_manager::get_instance();

    // 1) Create a new config (creates file under %APPDATA%\brasilhook\<name>.json)
    mgr.create_config("my_profile");

    // 2) Get pointer to current settings and modify them
    cheat_settings* s = mgr.get_current_settings();
    if (s) {
        s->b_aimbot = true;
        s->i_aimfov = 45;
        // Persist changes to disk
        mgr.save_config(mgr.get_cur_config_name());
    }

    // 3) Load an existing config from disk into memory
    mgr.load_config("my_profile");
        
    // 4) Switch active config (without loading from disk)
    mgr.set_active_config("my_profile");

    // 5) Export current settings to clipboard (JSON)
    mgr.copy_to_clipboard(*cur);

    // 6) Import a config from clipboard and create a new config from it
    //    (parses JSON from clipboard and creates unique name if needed)
    mgr.import_from_clipboard_and_create_new_config();
        
    // 7) Delete a config (removes file and entry)
    mgr.delete_config("my_profile");

    return 0;
}
```
