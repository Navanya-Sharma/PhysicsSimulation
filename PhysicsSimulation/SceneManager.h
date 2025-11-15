#pragma once
#include "Scene.h"
#include "Base.h"
#include <unordered_map>
#include <functional>
using namespace std;

class SceneManager
{
public:
	static SceneManager* get() { return &gSceneManager; };
	
	void ChangeScene() {
		if (NextScene == NULL) return;

		CurrentScene->Exit();
		CurrentScene = move(NextScene);
		CurrentScene->Init();
		NextScene = NULL;
	}
	~SceneManager() {
		CurrentScene->Exit();
		CurrentScene->~Scene();
	};

	void ImGuiInit(GLFWwindow* window);
	void ImGuiUpdate();
	void ImGuiRender();

	std::unique_ptr<Scene> CurrentScene = NULL;
	std::unique_ptr<Scene> NextScene = NULL;
	float color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
	

private:
	SceneManager() {
		CurrentScene = std::make_unique<Base>();
	};
	static SceneManager gSceneManager;
	static unordered_map<string, function<unique_ptr<Scene>()>> NameAndScenePointer;

	bool showDemoWindow = false;
	std::string selected = "";
	/*unordered_map<string, function<Scene* ()>> NameAndScenePointer2 = {
	{"Base",  []() -> Scene* { return new Base(); }},
	{"Base1", []() -> Scene* { return new Base(); }},
	{"Base2", []() -> Scene* { return new Base(); }}
	};*/
	
	//Function Pointers
};

