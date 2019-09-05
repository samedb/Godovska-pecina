#pragma once
#include "GameObject.h"
class Sunce :
	public GameObject
{
public:
	Sunce(Transform transform = Transform());
	void render();
};

