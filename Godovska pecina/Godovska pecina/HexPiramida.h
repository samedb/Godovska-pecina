#pragma once
#include "GameObject.h"
#include <cmath>
class HexPiramida :
	public GameObject
{
public:
	float visina;
	HexPiramida(Transform transform = Transform(), float visina = 5);
	HexPiramida(Vektor3f centarBaze, Vektor3f vrhPiramide);
	void render();
};

