#include "GameObject.h"

GameObject::GameObject(Transform t)
{
	transform = t;
}

void GameObject::update()
{
}

void GameObject::draw()
{
	glPushMatrix();
	glTranslatef(transform.position.x, transform.position.y, transform.position.z);
	glRotatef(transform.rotation.x, 1, 0, 0);
	glRotatef(transform.rotation.y, 0, 1, 0);
	glRotatef(transform.rotation.z, 0, 0, 1);
	glScaled(transform.scale.x, transform.scale.y, transform.scale.y);
	render();
	glPopMatrix();
}

void GameObject::render()
{
	glColor3f(1, 0.5, 1);
	glutSolidCube(1);
	glColor3f(0, 0, 0);
	glutWireCube(1);
}
