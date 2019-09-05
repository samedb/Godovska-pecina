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

using namespace std;

vector<GameObject*> elementiScene;
Kamera kamera = Kamera(Vektor3f(0, 2, 0));

void postaviScenu()
{
	elementiScene.push_back(&kamera);
	/*elementiScene.push_back(new Snesko(Vektor3f(-10, 0, -10)));
	elementiScene.push_back(new Snesko(Vektor3f(-20, 0, -10)));
	elementiScene.push_back(new Snesko(Vektor3f(-10, 0, -20)));*/
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (i == 0 || i == 8 || j == 0 || j ==8)
				elementiScene.push_back(new Snesko(Vektor3f(i * -10, -1, j * -10)));
	elementiScene.push_back(new Snesko(Transform(Vektor3f(-40, -1, -40), Vektor3f(), Vektor3f(10, 10, 10))));
	elementiScene.push_back(new Sunce(Vektor3f(0, 20, 0)));
	elementiScene.push_back(new Teren());

	for (int i = 0; i < 10; i++)
	{
		float x = -10 * (rand() % 5 + 5);
		float z = -10 * (rand() % 5 + 5);
		elementiScene.push_back(new GameObject(Vektor3f(x, 0, z)));
	}
}


void enable(void) 
{
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	//glEnable(GL_LIGHTING); //enable the lighting
	//glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	//glShadeModel(GL_SMOOTH); //set the shader to smooth shader
	ShowCursor(false);
}


void display(void) 
{
	glClearColor(0.0, 0.7, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
	glLoadIdentity();
	enable();

	for (GameObject* go : elementiScene) {
		go->update();
		go->draw();
	}

	glutSwapBuffers(); //swap the buffers
}

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

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Godovska pecina");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMovement); //check for mouse movement

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);

	postaviScenu();
	glutMainLoop();
	return 0;
}
