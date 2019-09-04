#pragma once

#include "Transform.h"
#include "GL/glut.h"
#include "GL/gl.h"

class GameObject
{
public:
	Transform transform;

	GameObject(Transform transform = Transform());
	void draw();
	virtual void render(); // ovu funkciju preklapaju klase koje nasledjuju ovu, definise kako se GameObject crta
};

