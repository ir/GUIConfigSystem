#ifndef __STYLEMANAGER_HPP
#define __STYLEMANAGER_HPP

#include "ImGui/imgui.h"
#include "StyleList.hpp"  
#include <string>
#include <vector>

class StyleManager {
public:
    struct StyleItem {
        std::string name;
        // Function pointer: takes an ImGuiStyle pointer and applies a style.
        void (*applyFunc)(ImGuiStyle*);
    };

    // Returns a reference to the static vector of available styles.
    static const std::vector<StyleItem>& GetStyles() {
        // Use a function-static variable so the vector is initialized only once.
        static const std::vector<StyleItem> styles = {
            { "Modern", SetModernStyle },
            { "Dark Red", SetDarkStyle },
            { "Retro", SetClassicStyle },
            { "Flat", SetComfyDarkStyle },
            { "Nord", SetModernNord },
            { "Vullmad", SetVullmad }
        };
        return styles;
    }

    // Applies the style corresponding to the given index.
    static void ApplyStyle(int style_idx) {
        const auto& styles = GetStyles();
        // Ensure a valid index (default to 0 if out-of-range)
        if (style_idx < 0 || style_idx >= static_cast<int>(styles.size()))
            style_idx = 0;
        styles[style_idx].applyFunc(&ImGui::GetStyle());
    }

private:
    // Apply functions for each style.
    static void SetModernStyle(ImGuiStyle* style) {
        StyleList::ModernDark(style);
    }

    static void SetDarkStyle(ImGuiStyle* style) {
        StyleList::DarkRed(style);
    }

    static void SetClassicStyle(ImGuiStyle* style) {
        StyleList::ClassicSteam(style);
    }

    static void SetComfyDarkStyle(ImGuiStyle* style) {
        StyleList::ModernFlat(style);
    }
    static void SetModernNord(ImGuiStyle* style) {
        StyleList::ModernNord(style);
    }
    static void SetVullmad(ImGuiStyle* style) {
        StyleList::Vullmad(style);
    }
};

#endif // __STYLEMANAGER_HPP
