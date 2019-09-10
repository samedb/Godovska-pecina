#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include <vector>

#include "Vektor3f.h"
#include "Snesko.h"
#include "Transform.h"
#include "Kamera.h"
#include "Sunce.h"
#include "Teren.h"
#include "Scena.h"
#include "HexPiramida.h"
#include "LinijeKoordinatnogSistema.h"
#include "TestScena1.h"

using namespace std;

#pragma region Scena

Scena scena;
Kamera kamera = Kamera(Vektor3f(0, 2, 0));

void postaviScenu()
{
	scena.dodaj(&kamera);
	scena.dodaj(new TestScena1());
}		  

#pragma endregion

int animationPeriod = 16;

// rekurzivna funkcija koja vrsi PostRedisplay posle nekog perioda animationPeriod
// tako da igra uvek ima isti broj fps-a
// nije savrseno ali sluzi svrsi
void animate(int value) {
	glutPostRedisplay();
	glutTimerFunc(animationPeriod, animate, 1);
}

void setup(void) 
{
	glClearColor(0.0, 0.7, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST); //enable the depth testing
	glEnable(GLUT_MULTISAMPLE); // msaa anti aliasing
	glEnable(GL_NORMALIZE); // resava probleme sa skaliranjem i osvetljenjem
	glutIgnoreKeyRepeat(1); // iskljucuje key repeat
	glShadeModel(GL_SMOOTH); //set the shader to smooth shader

	postaviScenu();
	animate(1);
}

// ovo je korisno ako hocu vise izvora svetlosti
//It is always the case that GL_LIGHTi = GL_LIGHT0 + i .

// Vrsi renderovanje svih elemenata jedne scene i poziva update za njih
void display(void) 
{
	ShowCursor(false);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
	glLoadIdentity();

	scena.update();
	scena.draw();

	glutSwapBuffers(); //swap the buffers
}

#pragma region Input

void keyboardDown(unsigned char key, int x, int y) 
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'w':
		kamera.napred = true;
		break;
	case 's':
		kamera.nazad = true;
		break;
	case 'a':
		kamera.levo = true;
		break;
	case 'd':
		kamera.desno = true;
		break;
	case ' ':
		kamera.gore = true;
		break;
	case 'c':
		kamera.dole = true;
		break;
	case 'l':
		kamera.letenje = !kamera.letenje;
		break;
	}
}

void keyboardUp(unsigned char key, int x, int y) 
{
	switch (key) 
	{
	case 'w':
		kamera.napred = false;
		break;
	case 's':
		kamera.nazad = false;
		break;
	case 'a':
		kamera.levo = false;
		break;
	case 'd':
		kamera.desno = false;
		break;
	case ' ':
		kamera.gore = false;
		break;
	case 'c':
		kamera.dole = false;
		break;
	}
}

void mouseMovement(int x, int y) 
{
	kamera.passiveMotionFunc(x, y);
}

void reshape(int w, int h) 
{
	kamera.reshapeFunc(w, h);
}

#pragma endregion

void instrukcije()
{
	cout << "Kretanje na wasd i na misa" << endl
		<< "skakanje na space i cucanj na c" << endl
		<< "l za ukljucivanje i iskljucivanje letenja" << endl
		<< "kad je ukljuceno letenje gore se ide na space a dole na c" << endl;
}

int main(int argc, char** argv) 
{
	instrukcije();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Godovska pecina");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMovement); //check for mouse movement
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);

	setup();

	glutMainLoop();
	return 0;
}
