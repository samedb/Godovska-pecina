#pragma once
#include "GameObject.h"
class Sunce :
	public GameObject
{
public:
	Sunce(Transform transform = Transform());
	void render();
private:
	float tamno[3] = { 0, 0, 0 }, svetlo[3] = { 0.8, 0.8, 0.8 };
};

