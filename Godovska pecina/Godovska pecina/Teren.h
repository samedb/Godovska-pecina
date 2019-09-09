#pragma once
#include "GameObject.h"
#include "TextureManager.h"
class Teren : public GameObject
{
public:
	Teren(Transform transform = Transform());
	void render();
};

