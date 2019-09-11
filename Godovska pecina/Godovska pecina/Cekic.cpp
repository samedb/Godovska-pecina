#include "Cekic.h"

Cekic::Cekic(Transform transform)
	:GameObject(transform)
{
}

void Cekic::render()
{
	glColor3f(0.38, 0.2, 0.07); // braon
	glTranslatef(0, -4, 0);
	glPushMatrix();
	glScalef(0.5, 8, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -5, 0);
	glPushMatrix();
	glScalef(3, 2, 2);
	glutSolidCube(1);
	glPopMatrix();
}

void Cekic::update()
{
	if (transform.rotation.z == 50 || transform.rotation.z == -50)
		rotacijaZ *= -1;
	transform.rotation.z += rotacijaZ;
}
