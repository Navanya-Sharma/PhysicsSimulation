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
}

void SceneManager::ImGuiUpdate()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Your Options");

    ImGui::ColorEdit3("clear color", color, ImGuiColorEditFlags_NoInputs); // Edit 3 floats representing a color

    
    for (auto it = NameAndScenePointer.begin(); it != NameAndScenePointer.end(); it++) {

        if (ImGui::Selectable(it->first.c_str(), selected == it->first, ImGuiSelectableFlags_AllowDoubleClick))
            if (ImGui::IsMouseDoubleClicked(0)) {
                selected = it->first;
                NextScene=move( it->second());
            }
    }


    // ImGui::Text("Application average %.1f FPS (%.3f ms/frame) ", io.Framerate, 1000.0f / io.Framerate);
    ImGui::Checkbox("Show Demo Window", &showDemoWindow);
    if (showDemoWindow) {
        ImGui::ShowDemoWindow(&showDemoWindow);
    }

    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
