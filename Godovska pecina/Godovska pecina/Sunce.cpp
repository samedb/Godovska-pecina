#include "Sunce.h"

Sunce::Sunce(Transform transform)
	:GameObject(transform)
{
}

void Sunce::render()
{
	glColor3f(1, 1, 0);
	//glutSolidSphere(5, 20, 20);
	float poz[] = { transform.position.x, transform.position.y, transform.position.z };
	glLightfv(GL_LIGHT0, GL_POSITION, poz);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, svetlo);
	glutSolidSphere(2, 20, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, tamno);

}
