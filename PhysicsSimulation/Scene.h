#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Scene
{
public:
	virtual void Init()=0; //Pure Virtual Function. No implementation in the base class, must be overidden, cant be instantiate, total abstract 
	virtual void Exit() {}; // Virtual function with default implementation

	virtual void Update()=0;
	virtual void Render()=0;

	virtual void UpdateImGui() {};
	virtual void HandleEvents(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	};

	virtual ~Scene() = default;
};

