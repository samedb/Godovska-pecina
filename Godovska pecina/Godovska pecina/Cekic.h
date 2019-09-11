#pragma once
#include "GameObject.h"
class Cekic: public GameObject
{
public:
	Cekic(Transform transform = Transform());
	void render();
	void update();
private:
	float rotacijaZ = 2; // koliko se rotira po z osi u svakom frejmu
};

