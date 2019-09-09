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

using namespace std;

#pragma region Scena

Scena scena1;
Kamera kamera = Kamera(Vektor3f(0, 2, 0));

void postaviScenu()
{
	scena1.dodaj(&kamera);
	// dodaj sneskove? oko terena
	for (int i = -4; i < 5; i++)
		for (int j = -4; j < 5; j++)
			if (i == -4 || i == 4 || j == -4 || j ==4)
				scena1.dodaj(new Snesko(Vektor3f(i * 10, -1, j * 10)));
	// jedan veliki snesko u sredini
	scena1.dodaj(new Snesko(Transform(Vektor3f(-10, -1, -10), Vektor3f(), Vektor3f(10, 10, 10))));
	scena1.dodaj(new Snesko(Transform(Vektor3f(-15, -1, -15), Vektor3f(), Vektor3f(10, 10, 10))));
	scena1.dodaj(new Teren());

	// dodaj gameobjecte (kocke) sa random pozicijama
	for (int i = 0; i < 10; i++)
	{
		float x = -5 * (rand() % 5 + 5);
		float z = -5 * (rand() % 5 + 5);
		scena1.dodaj(new GameObject(Vektor3f(x, 0, z)));
	}


	// iskorpiraj sve to u scenu2 i onda pomeri poziciju
	Scena *scena2 = new Scena(scena1);
	scena2->elementiScene[0] = scena2->elementiScene[2];
	scena2->transform.position.z -= 120;
	scena2->transform.rotation.y += 90;
	scena1.dodaj(scena2);

	Scena *scena3 = new Scena(scena1);
	scena3->elementiScene[0] = scena3->elementiScene[2];
	scena3->transform.position.x -= 120;
	scena3->transform.rotation.y -= 90;
	scena1.dodaj(scena3);

	Scena *scena4 = new Scena(scena1);
	scena4->elementiScene[0] = scena3->elementiScene[2];
	scena4->transform.position.z -= 120;
	scena4->transform.position.x -= 120;
	scena4->transform.rotation.y += 180;
	scena1.dodaj(scena4);
	
	scena1.dodaj(new Sunce(Vektor3f(0, 30, 0)));
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

	scena1.update();
	scena1.draw();

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
