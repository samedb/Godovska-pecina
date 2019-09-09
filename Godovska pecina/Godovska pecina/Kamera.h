#pragma once
#include "GameObject.h"
#include <iostream>
#include <cmath>
class Kamera :
	public GameObject
{
public:
	bool napred, nazad, levo, desno, gore, dole;
	bool letenje = false;
	Vektor3f movement;

	Kamera(Transform transform = Transform());
	void draw();
	void reshapeFunc(int w, int h);
	void passiveMotionFunc(int x, int y);
	void update();
private:
	const float gravitacija = 0.1;
	const float brzinaSkoka = 1.5;
	float brzinaKretanja;
	float mouseSensitivity;
	float yMovement;

	void move();
};

