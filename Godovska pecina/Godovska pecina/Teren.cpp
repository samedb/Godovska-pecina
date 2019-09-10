#include "Teren.h"

TextureManager teksture;

Teren::Teren(Transform transform)
	:GameObject(transform)
{
	teksture.UcitajTeksture();
}

void pravougaonik(int x, int z) 
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, teksture["pod2"]);
	for (int i = - x / 2; i <= x / 2; i += 2)
		for (int j = -z / 2; j <= z / 2; j += 2)
		{
			glPushMatrix();
			glTranslated(i, 0, j);
			glBegin(GL_QUADS);
			glNormal3f(0, -1, 0);
			glTexCoord2d(0.0, 0.0); glVertex3f(-1, 0, -1);
			glTexCoord2d( 1 , 0.0); glVertex3f( 1, 0, -1);
			glTexCoord2d(1 , 1 ); glVertex3f( 1, 0,  1);
			glTexCoord2d(0.0, 1); glVertex3f(-1, 0,  1);
			glEnd();
			glPopMatrix();
		}
	glDisable(GL_TEXTURE_2D);
}

void Teren::render()
{

	// Ovo moram malo bolje da uredim

	// zelena podloga
	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, -2, 0);
	pravougaonik(100, 100);
	glPopMatrix();

	// Ovako bi trebalo da se uradi i za zid

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
	glTranslatef(-51, 0, 30);
	glRotatef(90, 0, 0, 1);
	pravougaonik(4, 39);
	glutSolidCube(1);
	glPopMatrix();

	// podloga izlaza
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0, -2, -60);
	pravougaonik(20, 20);
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
