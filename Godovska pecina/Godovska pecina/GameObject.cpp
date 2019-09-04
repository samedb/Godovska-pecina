#include "GameObject.h"

GameObject::GameObject(Transform t)
{
	transform = t;
}

void GameObject::draw()
{
	glPushMatrix();
	glTranslatef(transform.position.x, transform.position.y, transform.position.z);
	glScaled(transform.scale.x, transform.scale.y, transform.scale.y);
	glRotatef(transform.rotation.x, 1, 0, 0);
	glRotatef(transform.rotation.y, 0, 1, 0);
	glRotatef(transform.rotation.z, 0, 0, 1);
	render();
	glPopMatrix();
}

void GameObject::render()
{
	glutSolidCube(1);
}
