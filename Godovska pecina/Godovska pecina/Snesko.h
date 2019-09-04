#pragma once

#include "GameObject.h"

class Snesko: public GameObject
{
public:
	Snesko(Transform transform = Transform());
	void render();
};

