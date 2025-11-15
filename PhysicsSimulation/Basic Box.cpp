#include "Basic Box.h"

#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_glfw.h"
#include "ImGui\imgui_impl_opengl3.h"



void BasicBox::Init() {
	printf("inti Basic Box");
}

void BasicBox::Update() {
	//printf("Update Basic Box");
}

void BasicBox::UpdateImGui() {
	

	Scene::UpdateImGui();
	ImGui::Text("Hello, Basic Box");
	ImGui::End();
	
}

void BasicBox::Render() {
	//printf("Render Basic Box");
}
