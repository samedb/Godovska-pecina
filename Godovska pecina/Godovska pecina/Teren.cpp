#include "Teren.h"

Teren::Teren(Transform transform)
	:GameObject(transform)
{
}

void Teren::render()
{

	// Ovo moram malo bolje da uredim

	// zelena podloga
	glColor3f(0.0, 1, 0.0);

	glPushMatrix();
	glTranslatef(0, -2, 0);
	glScalef(100, 1, 100);
	glutSolidCube(1);
	glPopMatrix();

	// crveni zid
	glColor3f(1, 0, 0);

	// pun zid
	glPushMatrix();
	glTranslatef(50.5, 0, 0);
	glScalef(1, 4, 100);
	glutSolidCube(1);
	glPopMatrix();




	// zid sa otvorom
	glPushMatrix();
	glTranslatef(-50.5, 0, 30);
	glScalef(1, 4, 40);
	glutSolidCube(1);
	glPopMatrix();

	// podloga izlaza
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(0, -2, -60);
	glScalef(20, 1, 20);
	glutSolidCube(1);
	glPopMatrix();

	//zidovi ilaza

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-10.5, 0, -60);
	glScalef(1, 4, 20);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(10.5, 0, -60);
	glScalef(1, 4, 20);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-50.5, 0, -30);
	glScalef(1, 4, 40);
	glutSolidCube(1);
	glPopMatrix();




	// zid sa otvorom
	glPushMatrix();
	glTranslatef(30, 0, -50.5);
	glScalef(40, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
	
	// podloga izlaza
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(-60, -2, 0);
	glScalef(20, 1, 20);
	glutSolidCube(1);
	glPopMatrix();

	//zidovi ilaza

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-60, 0, 10.5);
	glScalef(20, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(-60, 0, -10.5);
	glScalef(20, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, 0, -50.5);
	glScalef(40, 4, 1);
	glutSolidCube(1);
	glPopMatrix();




	// pun zid
	glPushMatrix();
	glTranslatef(0, 0, 50.5);
	glScalef(100, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
}
