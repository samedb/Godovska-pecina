#pragma once
#include "GameObject.h"
#include <cmath>
class Kamera :
	public GameObject
{
public:
	float brzinaKretanja;
	float mouseSensitivity;
	bool napred, nazad, levo, desno;

	Kamera(Transform transform = Transform());
	void draw();
	void reshapeFunc(int w, int h);
	void passiveMotionFunc(int x, int y);
	void update();
};

