#pragma once
#include "Scene.h"

class Base : public Scene
{
public:
	
	void UpdateImGui();
	void Init() override;
	void Update() override;
	void Render() override;


private:
	

};



