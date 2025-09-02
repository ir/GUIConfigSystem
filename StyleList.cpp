#include "StyleList.hpp"

void StyleList::ModernNord(ImGuiStyle* dst)
{
    // Nord/Nordic GTK [Improvised]
    // https://github.com/EliverLara/Nordic
    ImGuiStyle& style = ImGui::GetStyle();
    
    style.Colors[ImGuiCol_Text] = ImVec4(0.85f, 0.87f, 0.91f, 0.88f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.49f, 0.50f, 0.53f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.17f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.09f, 0.09f, 0.09f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.56f, 0.74f, 0.73f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.53f, 0.75f, 0.82f, 1.00f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.23f, 0.26f, 0.32f, 0.60f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.63f, 0.76f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.51f, 0.63f, 0.76f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.51f, 0.63f, 0.76f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.53f, 0.75f, 0.82f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.56f, 0.74f, 0.73f, 1.00f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.53f, 0.75f, 0.82f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.53f, 0.75f, 0.82f, 0.86f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.61f, 0.74f, 0.87f, 1.00f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.20f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.22f, 0.24f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.26f, 0.32f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.13f, 0.15f, 0.18f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.17f, 0.19f, 0.23f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.56f, 0.74f, 0.73f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.53f, 0.75f, 0.82f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.37f, 0.51f, 0.67f, 1.00f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.53f, 0.75f, 0.82f, 0.86f);

    style.WindowBorderSize = 1.00f;
    style.ChildBorderSize = 1.00f;
    style.PopupBorderSize = 1.00f;
    style.FrameBorderSize = 1.00f;
}

void StyleList::ModernFlat(ImGuiStyle* dst)
{
    // Material Flat style by ImJC1C from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.5f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 0.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Left;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.8313725590705872f, 0.8470588326454163f, 0.8784313797950745f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.8313725590705872f, 0.8470588326454163f, 0.8784313797950745f, 0.501960813999176f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1725490242242813f, 0.1921568661928177f, 0.2352941185235977f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.1587982773780823f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1725490242242813f, 0.1921568661928177f, 0.2352941185235977f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 0.501960813999176f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 0.250980406999588f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.5333333611488342f, 0.5333333611488342f, 0.5333333611488342f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.3333333432674408f, 0.3333333432674408f, 0.3333333432674408f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.6000000238418579f, 0.6000000238418579f, 0.6000000238418579f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.239215686917305f, 0.5215686559677124f, 0.8784313797950745f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9803921580314636f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 0.501960813999176f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 0.250980406999588f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 0.7799999713897705f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 0.250980406999588f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 0.250980406999588f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1529411822557449f, 0.1725490242242813f, 0.2117647081613541f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.3098039329051971f, 0.6235294342041016f, 0.9333333373069763f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 0.5021458864212036f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.03862661123275757f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.2039215713739395f, 0.2313725501298904f, 0.2823529541492462f, 0.7529411911964417f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 0.7529411911964417f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.105882354080677f, 0.1137254908680916f, 0.1372549086809158f, 0.7529411911964417f);
}

void StyleList::ClassicSteam(ImGuiStyle* dst)
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 0.0f;
    style.FrameBorderSize = 1.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.2862745225429535f, 0.3372549116611481f, 0.2588235437870026f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2862745225429535f, 0.3372549116611481f, 0.2588235437870026f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.239215686917305f, 0.2666666805744171f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 0.5f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.1372549086809158f, 0.1568627506494522f, 0.1098039224743843f, 0.5199999809265137f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.239215686917305f, 0.2666666805744171f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2666666805744171f, 0.2980392277240753f, 0.2274509817361832f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2980392277240753f, 0.3372549116611481f, 0.2588235437870026f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.239215686917305f, 0.2666666805744171f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.2862745225429535f, 0.3372549116611481f, 0.2588235437870026f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.239215686917305f, 0.2666666805744171f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2784313857555389f, 0.3176470696926117f, 0.239215686917305f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2470588237047195f, 0.2980392277240753f, 0.2196078449487686f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.2274509817361832f, 0.2666666805744171f, 0.2078431397676468f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 0.5f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.2862745225429535f, 0.3372549116611481f, 0.2588235437870026f, 0.4000000059604645f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 0.5f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 0.6000000238418579f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 0.5f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.1372549086809158f, 0.1568627506494522f, 0.1098039224743843f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.1882352977991104f, 0.2274509817361832f, 0.1764705926179886f, 0.0f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.5372549295425415f, 0.5686274766921997f, 0.5098039507865906f, 0.7799999713897705f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.239215686917305f, 0.2666666805744171f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.3490196168422699f, 0.4196078479290009f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.0f, 0.7764706015586853f, 0.2784313857555389f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.729411780834198f, 0.6666666865348816f, 0.239215686917305f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.5882353186607361f, 0.5372549295425415f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

void StyleList::ModernDark(ImGuiStyle* dst)
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(0.9490196108818054f, 0.95686274766922f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.3568627536296844f, 0.4196078479290009f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1098039224743843f, 0.1490196138620377f, 0.168627455830574f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.1490196138620377f, 0.1764705926179886f, 0.2196078449487686f, 1.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.0784313753247261f, 0.09803921729326248f, 0.1176470592617989f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1176470592617989f, 0.2000000029802322f, 0.2784313857555389f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.08627451211214066f, 0.1176470592617989f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08627451211214066f, 0.1176470592617989f, 0.1372549086809158f, 0.6499999761581421f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.0784313753247261f, 0.09803921729326248f, 0.1176470592617989f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.5099999904632568f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1490196138620377f, 0.1764705926179886f, 0.2196078449487686f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.3899999856948853f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.1764705926179886f, 0.2196078449487686f, 0.2470588237047195f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.08627451211214066f, 0.2078431397676468f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.2784313857555389f, 0.5568627715110779f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.2784313857555389f, 0.5568627715110779f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.3686274588108063f, 0.6078431606292725f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.2784313857555389f, 0.5568627715110779f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.05882352963089943f, 0.529411792755127f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 0.550000011920929f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.800000011920929f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 0.7799999713897705f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.09803921729326248f, 0.4000000059604645f, 0.7490196228027344f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.25f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.6700000166893005f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.949999988079071f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.1098039224743843f, 0.1490196138620377f, 0.168627455830574f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.800000011920929f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.2000000029802322f, 0.2470588237047195f, 0.2862745225429535f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.1098039224743843f, 0.1490196138620377f, 0.168627455830574f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1098039224743843f, 0.1490196138620377f, 0.168627455830574f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.3499999940395355f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

void StyleList::DarkRed(ImGuiStyle* dst)
{
    // Sonic Riders style by Sewer56 from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 0.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 0.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 0.0f;
    style.PopupBorderSize = 0.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.729411780834198f, 0.7490196228027344f, 0.7372549176216125f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.08627451211214066f, 0.08627451211214066f, 0.08627451211214066f, 0.9399999976158142f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.0784313753247261f, 0.0784313753247261f, 0.0784313753247261f, 0.9399999976158142f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 0.5f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.4000000059604645f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6700000166893005f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.4666666686534882f, 0.2196078449487686f, 0.2196078449487686f, 0.6700000166893005f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.4666666686534882f, 0.2196078449487686f, 0.2196078449487686f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.4666666686534882f, 0.2196078449487686f, 0.2196078449487686f, 0.6700000166893005f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.3372549116611481f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.01960784383118153f, 0.01960784383118153f, 0.01960784383118153f, 0.5299999713897705f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5098039507865906f, 0.5098039507865906f, 0.5098039507865906f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.4666666686534882f, 0.2196078449487686f, 0.2196078449487686f, 0.6499999761581421f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.6499999761581421f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 0.5f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6499999761581421f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.4274509847164154f, 0.4274509847164154f, 0.4980392158031464f, 0.5f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6600000262260437f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6600000262260437f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.7098039388656616f, 0.3882353007793427f, 0.3882353007793427f, 0.5400000214576721f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6600000262260437f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.8392156958580017f, 0.658823549747467f, 0.658823549747467f, 0.6600000262260437f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.06666667014360428f, 0.09803921729326248f, 0.1490196138620377f, 0.9700000286102295f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1372549086809158f, 0.2588235437870026f, 0.4196078479290009f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.6078431606292725f, 0.6078431606292725f, 0.6078431606292725f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.4274509847164154f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.8980392217636108f, 0.6980392336845398f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.6000000238418579f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2588235437870026f, 0.5882353186607361f, 0.9764705896377563f, 0.3499999940395355f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 1.0f, 0.0f, 0.8999999761581421f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.407843142747879f, 0.407843142747879f, 0.407843142747879f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 1.0f, 1.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800000011920929f, 0.800000011920929f, 0.800000011920929f, 0.3499999940395355f);
}

void StyleList::Vullmad(ImGuiStyle* dst)
{
    // Use the provided style pointer if available, otherwise use the current ImGui style.
    ImGuiStyle& style = dst ? *dst : ImGui::GetStyle();

    //==============================================================
    // Layout & Sizing
    //==============================================================
    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6f;
    style.WindowPadding = ImVec2(8.0f, 8.0f);
    style.WindowRounding = 4.0f;
    style.WindowBorderSize = 0.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 4.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 4.0f;
    style.PopupBorderSize = 0.0f;
    style.FramePadding = ImVec2(4.0f, 3.0f);
    style.FrameRounding = 4.0f;
    style.FrameBorderSize = 0.0f;
    style.ItemSpacing = ImVec2(8.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 2.0f);
    style.IndentSpacing = 21.0f;
    style.ColumnsMinSpacing = 6.0f;
    style.ScrollbarSize = 14.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 4.0f;
    style.TabRounding = 4.0f;
    style.TabBorderSize = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    //==============================================================
    // Color Palette
    //==============================================================
    // Base colors from the Mullvad theme design:
    const ImVec4 col_white = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);  // For text
    const ImVec4 col_gray = ImVec4(0.63f, 0.66f, 0.71f, 1.00f);  // Disabled text, etc.
    const ImVec4 col_darkBlue = ImVec4(0.07f, 0.13f, 0.20f, 1.00f);  // Deep background
    const ImVec4 col_darkBlueT = ImVec4(0.07f, 0.13f, 0.20f, 0.94f);  // Slightly transparent dark blue
    const ImVec4 col_mediumBlue = ImVec4(0.11f, 0.18f, 0.29f, 1.00f);  // Borders and separators
    const ImVec4 col_mediumBlueT = ImVec4(0.11f, 0.18f, 0.29f, 0.54f);  // Faded for selected text background
    const ImVec4 col_lightBlue = ImVec4(0.235f, 0.431f, 0.682f, 1.00f); // Hover states, grabs, etc.
    const ImVec4 col_buttonN = ImVec4(0.10f, 0.25f, 0.50f, 1.00f);  // Button normal state (flat deep blue)
    const ImVec4 col_buttonH = ImVec4(0.20f, 0.45f, 0.80f, 1.00f);  // Button hovered state (brighter blue)
    const ImVec4 col_buttonA = ImVec4(0.15f, 0.35f, 0.70f, 1.00f);  // Button active state
    const ImVec4 col_green = ImVec4(0.21f, 0.66f, 0.32f, 1.00f);  // For active elements (e.g. title active, check marks)
    const ImVec4 col_greenSemi = ImVec4(0.21f, 0.66f, 0.32f, 0.31f);  // Semi-transparent green for headers
    // The red color is reserved for specific actions like disconnect buttons:
    const ImVec4 col_red = ImVec4(0.84f, 0.23f, 0.24f, 1.00f);

    //==============================================================
    // Color Assignments
    //==============================================================
    style.Colors[ImGuiCol_Text] = col_white;
    style.Colors[ImGuiCol_TextDisabled] = col_gray;
    style.Colors[ImGuiCol_WindowBg] = col_darkBlueT;
    style.Colors[ImGuiCol_ChildBg] = col_darkBlue;
    style.Colors[ImGuiCol_PopupBg] = col_darkBlueT;
    style.Colors[ImGuiCol_Border] = col_mediumBlue;
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0, 0, 0, 0);
    style.Colors[ImGuiCol_FrameBg] = col_buttonN;
    style.Colors[ImGuiCol_FrameBgHovered] = col_buttonH;
    style.Colors[ImGuiCol_FrameBgActive] = col_buttonA;
    style.Colors[ImGuiCol_TitleBg] = col_darkBlue;
    style.Colors[ImGuiCol_TitleBgActive] = col_green;
    style.Colors[ImGuiCol_TitleBgCollapsed] = col_darkBlueT;
    style.Colors[ImGuiCol_MenuBarBg] = col_darkBlue;
    style.Colors[ImGuiCol_ScrollbarBg] = col_darkBlueT;
    style.Colors[ImGuiCol_ScrollbarGrab] = col_mediumBlue;
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = col_lightBlue;
    style.Colors[ImGuiCol_ScrollbarGrabActive] = col_lightBlue;
    style.Colors[ImGuiCol_CheckMark] = col_green;   // Checkboxes and switches (green for enabled)
    style.Colors[ImGuiCol_SliderGrab] = col_lightBlue;
    style.Colors[ImGuiCol_SliderGrabActive] = col_lightBlue;
    style.Colors[ImGuiCol_Button] = col_buttonN;
    style.Colors[ImGuiCol_ButtonHovered] = col_buttonH;
    style.Colors[ImGuiCol_ButtonActive] = col_buttonA;
    style.Colors[ImGuiCol_Header] = col_greenSemi;  // For tree nodes and collapsing headers
    style.Colors[ImGuiCol_HeaderHovered] = col_green;
    style.Colors[ImGuiCol_HeaderActive] = col_green;
    style.Colors[ImGuiCol_Separator] = col_mediumBlue;
    style.Colors[ImGuiCol_SeparatorHovered] = col_lightBlue;
    style.Colors[ImGuiCol_SeparatorActive] = col_lightBlue;
    style.Colors[ImGuiCol_ResizeGrip] = col_lightBlue;
    style.Colors[ImGuiCol_ResizeGripHovered] = col_lightBlue;
    style.Colors[ImGuiCol_ResizeGripActive] = col_lightBlue;
    style.Colors[ImGuiCol_Tab] = col_darkBlue;
    style.Colors[ImGuiCol_TabHovered] = col_lightBlue;
    style.Colors[ImGuiCol_TabActive] = col_green;
    style.Colors[ImGuiCol_TabUnfocused] = col_darkBlue;
    style.Colors[ImGuiCol_TabUnfocusedActive] = col_green;
    style.Colors[ImGuiCol_DockingPreview] = col_greenSemi;
    style.Colors[ImGuiCol_DockingEmptyBg] = col_darkBlue;
    style.Colors[ImGuiCol_PlotLines] = col_lightBlue;
    style.Colors[ImGuiCol_PlotLinesHovered] = col_green;
    style.Colors[ImGuiCol_PlotHistogram] = col_green;
    style.Colors[ImGuiCol_PlotHistogramHovered] = col_green;
    style.Colors[ImGuiCol_TableHeaderBg] = col_darkBlue;
    style.Colors[ImGuiCol_TableBorderStrong] = col_mediumBlue;
    style.Colors[ImGuiCol_TableBorderLight] = col_mediumBlue;
    style.Colors[ImGuiCol_TableRowBg] = col_darkBlue;
    style.Colors[ImGuiCol_TableRowBgAlt] = col_darkBlueT;
    style.Colors[ImGuiCol_TextSelectedBg] = col_mediumBlueT;
    style.Colors[ImGuiCol_DragDropTarget] = col_lightBlue;
    style.Colors[ImGuiCol_NavHighlight] = col_green;
    style.Colors[ImGuiCol_NavWindowingHighlight] = col_white;
    style.Colors[ImGuiCol_NavWindowingDimBg] = col_darkBlueT;
    style.Colors[ImGuiCol_ModalWindowDimBg] = col_darkBlueT;
}
