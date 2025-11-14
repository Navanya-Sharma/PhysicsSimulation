#include "SceneManager.h"

#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_glfw.h"
#include "ImGui\imgui_impl_opengl3.h"


SceneManager SceneManager::gSceneManager;

void SceneManager::ImGuiInit(GLFWwindow* window) {
    //IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 130");

    

    // Option A: Just scale everything
    io.FontGlobalScale = 1.5f;
}

void SceneManager::ImGuiUpdate()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(350, 1000), ImGuiCond_Always);
    ImGui::SetNextWindowBgAlpha(0.5f);

    ImGui::Begin("Your Options", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar
        | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

    ImGui::SeparatorText("This is PHYSICS!");
    for (auto it = NameAndScenePointer.begin(); it != NameAndScenePointer.end(); it++) {
        if (ImGui::Selectable(it->first.c_str(), selected == it->first, ImGuiSelectableFlags_AllowDoubleClick))
            if (ImGui::IsMouseDoubleClicked(0)) {
                selected = it->first;
                NextScene=move( it->second());
            }
    }
    
    ImGui::SeparatorText("Accessibility");

    ImGui::ColorEdit3("clear color", color, ImGuiColorEditFlags_NoInputs); // Edit 3 floats representing a color
    ;
    //ImGui::SameLine(0, 0);
    ImGui::Checkbox("Show Demo Window", &showDemoWindow);
    if (showDemoWindow) {
        ImGui::ShowDemoWindow(&showDemoWindow);
    }

    ImGui::Text("Avg Framerate %.1f FPS", ImGui::GetIO().Framerate);

}

void SceneManager::ImGuiRender()
{
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
