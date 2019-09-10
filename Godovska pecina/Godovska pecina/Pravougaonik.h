#pragma once
#include "GameObject.h"
class Pravougaonik: public GameObject
{
public:
	Pravougaonik(Transform transform = Transform(), std::string nazivTeksture = "");
	void draw();
	void render();
};

