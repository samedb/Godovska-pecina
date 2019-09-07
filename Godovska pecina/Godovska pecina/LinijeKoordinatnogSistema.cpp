#include "LinijeKoordinatnogSistema.h"

LinijeKoordinatnogSistema::LinijeKoordinatnogSistema(Transform transform)
	:GameObject(transform)
{
}

void LinijeKoordinatnogSistema::render()
{
	glColor3f(1, 1, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 100, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
