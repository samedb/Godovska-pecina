#include "Teren.h"

Teren::Teren(Transform transform)
	:GameObject(transform)
{
}

void Teren::render()
{
	// zelena podloga
	glColor3f(0.0, 1, 0.0);

	glPushMatrix();
	glTranslatef(-40, -2, -40);
	glScalef(100, 1, 100);
	glutSolidCube(1);
	glPopMatrix();

	// crveni zid
	glColor3f(1, 0, 0);

	glPushMatrix();
	glTranslatef(10.5, 0, -40);
	glScalef(1, 4, 100);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90.5, 0, -40);
	glScalef(1, 4, 100);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 0, -90.5);
	glScalef(100, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 0, 10.5);
	glScalef(100, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
}
