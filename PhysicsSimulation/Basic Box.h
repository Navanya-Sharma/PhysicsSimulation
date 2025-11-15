#pragma once
#include "Scene.h"

class BasicBox : public Scene
{
public:
	
	void UpdateImGui();
	void Init() override;
	void Update() override;
	void Render() override;

private:
	

};



