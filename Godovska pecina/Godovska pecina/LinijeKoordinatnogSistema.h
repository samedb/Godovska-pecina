#pragma once
#include "GameObject.h"
class LinijeKoordinatnogSistema :
	public GameObject
{
public:
	LinijeKoordinatnogSistema(Transform transform = Transform());
	void render();
};

