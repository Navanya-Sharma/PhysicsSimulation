#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

#include "ImGui\imgui.h"
#include "ImGui\imgui_impl_glfw.h"
#include "ImGui\imgui_impl_opengl3.h"

class Scene
{
public:
	virtual void Init()=0; //Pure Virtual Function. No implementation in the base class, must be overidden, cant be instantiate, total abstract 
	virtual void Exit() {}; // Virtual function with default implementation

	virtual void Update()=0;
	virtual void Render()=0;

	virtual void UpdateImGui() {
		ImGui::SetNextWindowPos(ImVec2(725, 700), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Always);
		ImGui::SetNextWindowBgAlpha(0.5f);

		ImGui::Begin("Inputs", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
	};
	virtual void HandleEvents(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	};

	virtual ~Scene() = default;
private:
	
};

