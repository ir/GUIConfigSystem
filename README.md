# GUIConfigSystem

Feature-rich, Includes:

- Versioning and Migration support (TODO) (version field + migrate_config() placeholder).

- Clipboard import/export (copy/paste configs as JSON).

- Automatic default config creation (init_base_config()).

- Renaming configs (with file rename and JSON updates).

- Importing configs with unique name handling.

- Refresh config list from filesystem (dynamic sync).

- Style application hook for ImGui themes.

- Logging with logger::get_instance().

- Config validation (checks settings exists, checks version).

- Safe file handling with exceptions and rollback.
