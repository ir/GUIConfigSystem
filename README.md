# ImGUIConfigSystem

JSON configuration manager for applications (C++17, Windows).

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
#include "Config_manager.h"
#include "StyleManager.h"   // Needed for style applying
#include <iostream>

int main()
{
    // Initialize ImGui and style registry (must happen after ImGui context is created)
    config_manager::get_instance().on_imgui_initialized();

    // Get the singleton manager
    auto& mgr = config_manager::get_instance();

    // 1) Create a new config
    if (mgr.create_config("styled_profile")) {
        std::cout << "Config created: styled_profile\n";
    }

    // 2) Modify settings (enable aimbot, change FOV, select style index.
    // Ideally this would be accessed through ImGUI with e.g. sliders, user input, toggles, etc)
    cheat_settings* s = mgr.get_current_settings();
    if (s) {
        s->b_aimbot = true;
        s->i_aimfov = 60;
        s->style_idx = 2; // e.g., Dark Theme or custom index
        mgr.save_config(mgr.get_cur_config_name());
        std::cout << "Updated styled_profile with aimbot and style_idx = 2\n";
    }

    // 3) Load a config (applies stored style automatically)
    if (mgr.load_config("styled_profile")) {
        std::cout << "Loaded styled_profile and applied its style.\n";
    }

    // 4) Switch active config (does not reload from file, but changes current pointer)
    if (mgr.set_active_config("styled_profile")) {
        std::cout << "Switched active config to styled_profile\n";
    }

    // 5) Apply style manually (Also ideally accessed from ImGUI in for example, a dropbox containing the styles)
    if (auto* current = mgr.get_current_settings()) {
        mgr.apply_style(*current);
        std::cout << "Manually applied style for active config.\n";
    }

    // 6) Export to clipboard (easier sharing among friends)
    if (auto* current = mgr.get_current_settings()) {
        mgr.copy_to_clipboard(*current);
        std::cout << "Exported config to clipboard.\n";
    }

    // 7) Import from clipboard and create a new config (easy importing)
    if (mgr.import_from_clipboard_and_create_new_config()) {
        std::cout << "Imported new config from clipboard and applied style.\n";
    }

    // 8) Delete a config
    mgr.delete_config("styled_profile");

    return 0;
}

```

---
TODO:
- Integrate keybinds for increased accessibility
- Version migration
- Unit tests
