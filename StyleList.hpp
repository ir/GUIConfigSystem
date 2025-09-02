#ifndef __STYLELIST_HPP
#define __STYLELIST_HPP
#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"

namespace StyleList {
    void ModernDark(ImGuiStyle* dst);
    void DarkRed(ImGuiStyle* dst);
    void ModernFlat(ImGuiStyle* dst);
    void ClassicSteam(ImGuiStyle* dst);
    void ModernNord(ImGuiStyle* dst);
    void Vullmad(ImGuiStyle* dst);
}

#endif