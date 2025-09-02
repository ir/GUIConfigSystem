# GUIConfigSystem

Feature-rich, Includes:

- Versioning and Migration support (TODO) (version field + migrate_config() placeholder).

- Config validation (checks settings exists, checks version).

- Automatic default config creation (init_base_config()).

- Import/export (copy/paste configs as JSON, includes clipboard handling).

- Renaming configs (with file rename and JSON updates).

- Refresh config list from filesystem (dynamic sync).

- Style application hook for ImGui themes.

- Logging with logger::get_instance().

- Safe file handling with exceptions and rollback.
