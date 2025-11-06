#pragma once
#include "Scene.h"
#include "Base.h"
#include <unordered_map>
using namespace std;

class SceneManager
{
public:
	static SceneManager* get() { return &gSceneManager; };
	
	void ChangeScene() {
		if (NextScene == NULL) return;

		CurrentScene->Exit();
		CurrentScene = NextScene;
		CurrentScene->Init();
		NextScene = NULL;
	}
	~SceneManager() {
		CurrentScene->Exit();
		CurrentScene->~Scene();
	};

	void ImGuiInit(GLFWwindow* window);
	void ImGuiUpdate();

	Scene* CurrentScene = NULL;
	Scene* NextScene = NULL;
	float color[4] = { 0.45f, 0.55f, 0.60f, 1.00f };
	

private:
	SceneManager() {
		CurrentScene = Base::get();
	};
	static SceneManager gSceneManager;

	bool showDemoWindow = false;
	std::string selected = "";
	unordered_map<string, Scene* > NameAndScenePointer =
	{ {"Base",Base::get()}, {"Base1",Base::get()} ,{"Base2",Base::get()} };
	

};

