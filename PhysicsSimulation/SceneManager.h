#pragma once
#include "Scene.h"
#include "Base.h"

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
		delete(CurrentScene);
		delete(NextScene);
	};
	Scene* NextScene = NULL;

private:
	SceneManager() {
		CurrentScene = Base::get();
	};
	static SceneManager gSceneManager;
	Scene* CurrentScene = NULL;
	

};

SceneManager SceneManager::gSceneManager;
