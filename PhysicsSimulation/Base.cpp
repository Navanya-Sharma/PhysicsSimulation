#include "Base.h"

#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_glfw.h"
#include "ImGui\imgui_impl_opengl3.h"



void Base::Init() {
	printf("inti base");
}

void Base::Update() {
	//printf("Update base");
}

void Base::UpdateImGui() {
	//ImGui::NewFrame();
	ImGui::Begin("Hey");
	ImGui::Text("Hello, ImGui!");
	ImGui::End();
	
}

void Base::Render() {
	//printf("Render base");
}
