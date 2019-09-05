#pragma once
#include "GameObject.h"
class Teren :
	public GameObject
{
public:
	Teren(Transform transform = Transform());
	void render();
};

