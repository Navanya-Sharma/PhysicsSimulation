#pragma once
#include "Scene.h"

class Base : public Scene
{
public:
	static Base* get() { return &gBase; }

	void Init();
	void Update();
	void Render();


private:
	static Base gBase;

};



