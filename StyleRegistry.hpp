#ifndef __STYLE_REGISTRY_H
#define __STYLE_REGISTRY_H

#include "ImGui/imgui.h"
#include <queue>
#include <memory>
#include <functional>
#include <mutex>

class StyleRegistry {
public:
    // Singleton pattern for global access to the registry
    static StyleRegistry& get_instance() {
        static StyleRegistry instance;
        return instance;
    }

    // Style queue to store pending styles
    void queue_style(std::function<void()> apply_style_function) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (imgui_initialized) {
            // Apply style immediately if ImGui is initialized
            apply_style_function();
        }
        else {
            // Otherwise, queue the style for later
            style_queue.push(apply_style_function);
        }
    }

    // Mark ImGui as initialized and apply all queued styles
    void on_imgui_initialized() {
        std::lock_guard<std::mutex> lock(m_mutex);
        imgui_initialized = true;

        // Apply all queued styles
        while (!style_queue.empty()) {
            style_queue.front()();  // Call the stored function to apply the style
            style_queue.pop();
        }
    }

private:
    StyleRegistry() : imgui_initialized(false) {}

    bool imgui_initialized;
    std::queue<std::function<void()>> style_queue;
    std::mutex m_mutex;

    // Prevent copy and assignment
    StyleRegistry(const StyleRegistry&) = delete;
    StyleRegistry& operator=(const StyleRegistry&) = delete;
};

#endif // __STYLE_REGISTRY_H
