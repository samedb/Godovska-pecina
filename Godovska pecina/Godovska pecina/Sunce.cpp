#include "Sunce.h"

Sunce::Sunce(Transform transform)
	:GameObject(transform)
{
}

void Sunce::render()
{
	glColor3f(1, 1, 0);
	glutSolidSphere(5, 20, 20);
}
