#pragma once

#include "Transform.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include <iostream>

class GameObject
{
public:
	Transform transform;
	std::string tekstura; // naziv pod kojim je tekstura ucitana u TextureManager

	GameObject(Transform transform = Transform());
	virtual void update(); // update posle svakog frejma
	// moze da ima i update sa delta time
	virtual void draw(); // ako zeli jos vecu kontrolu nad crtanjem onda se preklapa ova, kao npr kod Kamere
	virtual void render(); // ovu funkciju preklapaju klase koje nasledjuju ovu, definise kako se GameObject crta
};

