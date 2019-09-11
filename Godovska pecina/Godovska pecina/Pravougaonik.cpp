#include "Pravougaonik.h"
#include "TextureManager.h"

Pravougaonik::Pravougaonik(Transform transform, std::string nazivTeksture)
	:GameObject(transform)
{
	tekstura = nazivTeksture;
}

void Pravougaonik::draw()
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
	render();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Pravougaonik::render()
{
	// Sta ako pravougaonih nema jednake stranice onda ce slike da se razvuce

	// sirina i visina pojedinih praougaonika na koje se deli veliki pravougaonik
	float sirina = 1.0 / transform.scale.x;
	float visina = 1.0 / transform.scale.z;

	int texX, texZ;

	for (int x = -transform.scale.x / 2; x <= transform.scale.x / 2; x += 2)
		for (int z = -transform.scale.z / 2; z <= transform.scale.z / 2; z += 2)
		{
			texX = x + transform.scale.x / 2;
			texZ = z + transform.scale.z / 2;
			glPushMatrix();
			glTranslatef(x, 0, z);
			glBegin(GL_TRIANGLE_STRIP);
			glNormal3f(0, 1, 0);
			glTexCoord2d((texX + 2) * sirina,	texZ * visina);					glVertex3f( 1.0, 0, -1.0);
			glTexCoord2d( texX * sirina,		texZ * visina);					glVertex3f(-1.0, 0, -1.0);
			glTexCoord2d((texX + 2) * sirina,  (texZ + 2) * visina);			glVertex3f( 1.0, 0, 1.0);
			glTexCoord2d( texX * sirina,       (texZ + 2) * visina);			glVertex3f(-1.0, 0, 1.0);
			glEnd();
			glPopMatrix();
		}
}
