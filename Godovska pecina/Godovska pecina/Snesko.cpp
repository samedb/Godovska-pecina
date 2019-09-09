#include "Snesko.h"

Snesko::Snesko(Transform transform)
	:GameObject(transform)
{

}

void Snesko::render()
{
	// prekopirano iz onog primera sa moodla

	// Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
	glColor3f(1.0, 1.0, 1.0); // set drawing color to white
	glPushMatrix();
	glTranslatef(0.0, 0.75, 0.0);
	glutSolidSphere(0.75, 10, 10);
	glPopMatrix();

	// Draw the head (a sphere of radius 0.25 at height 1.75)
	glPushMatrix();
	glTranslatef(0.0, 1.75, 0.0); // position head
	glutSolidSphere(0.25, 10, 10); // head sphere

	// Draw Eyes (two small black spheres)
	glColor3f(0.0, 0.0, 0.0); // eyes are black
	glPushMatrix();
	glTranslatef(0.0, 0.10, -0.18); // lift eyes to final position
	glPushMatrix();
	glTranslatef(-0.05, 0.0, 0.0);
	glutSolidSphere(0.05, 5, 5); // right eye
	glPopMatrix();
	glPushMatrix();
	glTranslatef(+0.05, 0.0, 0.0);
	glutSolidSphere(0.05, 5, 5); // left eye
	glPopMatrix();
	glPopMatrix();

	// Draw Nose (the nose is an orange cone)
	glColor3f(1.0, 0.5, 0.5); // nose is orange
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0); // rotate to point along -y
	glutSolidCone(0.08, 0.5, 10, 2); // draw cone
	glPopMatrix();
	glPopMatrix();

	//// Draw a faux shadow beneath snow man (dark green circle)
	//glColor3f(0.0, 0.5, 0.0);
	//glPushMatrix();
	//glTranslatef(0.2, 0.001, 0.2);	// translate to just above ground
	//glScalef(1.0, 00, 1.0); // scale sphere into a flat pancake
	//glutSolidSphere(0.75, 10, 10); // shadow same size as body
	//glPopMatrix();
}

void Snesko::update()
{
	transform.rotation.y++;
}
