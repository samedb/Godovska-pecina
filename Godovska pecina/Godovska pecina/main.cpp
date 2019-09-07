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

Scena scena1, scena2, scena3, scena4;
Scena hexa;
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
	scena1.dodaj(new Sunce(Vektor3f(0, 20, 0)));
	scena1.dodaj(new Teren());

	// dodaj gameobjecte (kocke) sa random pozicijama
	for (int i = 0; i < 10; i++)
	{
		float x = -5 * (rand() % 5 + 5);
		float z = -5 * (rand() % 5 + 5);
		scena1.dodaj(new GameObject(Vektor3f(x, 0, z)));
	}


	// iskorpiraj sve to u scenu2 i onda pomeri poziciju
	scena2 = scena1;
	scena2.elementiScene[0] = scena2.elementiScene[2];
	scena2.transform.position.z -= 120;
	scena2.transform.rotation.y += 90;
	scena1.dodaj(&scena2);

	scena3 = scena1;
	scena3.elementiScene[0] = scena3.elementiScene[2];
	scena3.transform.position.x -= 120;
	scena3.transform.rotation.y -= 90;
	scena1.dodaj(&scena3);

	scena4 = scena1;
	scena4.elementiScene[0] = scena3.elementiScene[2];
	scena4.transform.position.z -= 120;
	scena4.transform.position.x -= 120;
	scena4.transform.rotation.y += 180;
	scena1.dodaj(&scena4);

	hexa.dodaj(&kamera);
	hexa.dodaj(new LinijeKoordinatnogSistema());
	hexa.dodaj(new HexPiramida(Transform(Vektor3f(1, 0, 0), Vektor3f(40.7, 30.5, 0), Vektor3f(1, 1, 1)), 13.2)); // 13.2 je intenzitet vektora (5, 10, 7)
	//hexa.dodaj(new GameObject(Transform(Vektor3f(5, 10, 7), Vektor3f(), Vektor3f(1, 1, 1)))); // kocka na poziciji(5, 10, 7)
}

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
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	//glEnable(GL_LIGHTING); //enable the lighting
	//glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	glEnable(GLUT_MULTISAMPLE); // msaa 
	animate(1);

	//glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING);

	//// Light property vectors.
	//float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
	//float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	//float lightPos[] = { 0.0, 10, 0, 1.0 };
	//float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

	//// Light properties.
	//glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//glEnable(GL_LIGHT0); // Enable particular light source.
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // Enable two-sided lighting.
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.
	//glShadeModel(GL_SMOOTH); //set the shader to smooth shader
}

// Vrsi renderovanje svih elemenata jedne scene i poziva update za njih
void display(void) 
{
	ShowCursor(false);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
	glLoadIdentity();




	hexa.update();
	hexa.draw();

	//// Material property vectors.
	//float matAmbAndDif1[] = { 0.9, 0.0, 0.0, 1.0 };
	//float matAmbAndDif2[] = { 0.0, 0.9, 0.0, 1.0 };
	//float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	//float matShine[] = { 50.0 };

	//// Material properties of the box.
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif1);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);

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
	case 'i':
		hexa.elementiScene[2]->transform.rotation.x += 3;
		break;
	case 'k':
		hexa.elementiScene[2]->transform.rotation.x -= 3;
		break;
	case 'j':
		hexa.elementiScene[2]->transform.rotation.z += 3;
		break;
	case 'l':
		hexa.elementiScene[2]->transform.rotation.z -= 3;
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Godovska pecina");
	glutDisplayFunc(display);
	//glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMovement); //check for mouse movement

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);

	postaviScenu();
	setup();
	glutMainLoop();
	return 0;
}
