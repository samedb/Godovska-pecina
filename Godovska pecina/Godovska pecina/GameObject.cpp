#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(Transform t)
{
	transform = t;
}

void GameObject::update()
{
}

void GameObject::draw()
{
	if (tekstura != "")
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, TextureManager::getInstance()->UzmiTeksturu(tekstura));
	}
	glPushMatrix();
	glTranslatef(transform.position.x, transform.position.y, transform.position.z);
	glRotatef(transform.rotation.x, 1, 0, 0);
	glRotatef(transform.rotation.y, 0, 1, 0);
	glRotatef(transform.rotation.z, 0, 0, 1);
	glScaled(transform.scale.x, transform.scale.y, transform.scale.z);
	render();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void GameObject::render()
{
	glColor3f(1, 0.75, 0.8);
	glutSolidCube(1);
	glColor3f(0, 0, 0);
	glutWireCube(1);
}
