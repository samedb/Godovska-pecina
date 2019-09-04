#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "Vektor3f.h"
#include "Snesko.h"
#include "Transform.h"

using namespace std;


//angle of rotation
float xpos = 0, ypos = 2, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;


int windowWidth, windowHeight; // za crosshair mi treba, posto on treba da ide na sredinu prozora


Vektor3f pozicijeKocki[10];
Snesko go(Transform(Vektor3f(-10, 0, -10)));

void cubepositions(void) { //set the positions of the cubes

	for (int i = 0; i < 10; i++)
	{
		pozicijeKocki[i].x = rand() % 5 + 5;
		pozicijeKocki[i].z = rand() % 5 + 5;
	}
}

//draw the cube
void cube(void) {
	glColor3f(0, 1, 1);
	for (int i = 0; i < 10; i++)
	{
		glPushMatrix();
		glTranslated(-pozicijeKocki[i + 1].x * 10, 0, -pozicijeKocki[i + 1].z * 10); //translate the cube
		glutSolidCube(2); //draw the cube
		glPopMatrix();
	}
}

void init(void) {
	cubepositions();
}

void enable(void) {
	glEnable(GL_DEPTH_TEST); //enable the depth testing
	//glEnable(GL_LIGHTING); //enable the lighting
	//glEnable(GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	//glShadeModel(GL_SMOOTH); //set the shader to smooth shader
	ShowCursor(false);
}

void camera() {
	glRotatef(xrot, 1.0, 0.0, 0.0);  //rotate our camera on teh x - axis(left and right)
	glRotatef(yrot, 0.0, 1.0, 0.0);  //rotate our camera on the	y - axis(up and down)
	glTranslated(-xpos, -ypos, -zpos); //translate the screen to the position of our camera
}

void podloga() {
	glColor3f(0.0, 1, 0.0);
	glPushMatrix();
	glTranslatef(-40, -2, -40);
	glScalef(100, 1, 100);
	glutSolidCube(1);
	glPopMatrix();
}

void zid() {
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(10.5, 0, -40);
	glScalef(1, 4, 100);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-90.5, 0, -40);
	glScalef(1, 4, 100);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 0, -90.5);
	glScalef(100, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 0, 10.5);
	glScalef(100, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void koordinate() {
	glColor3f(0, 0, 1);
	for (int i = -10; i < 5; i++)
	{
		glPushMatrix();
		glTranslatef(i * 10, 0, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, i * 10, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, i * 10);
		glutSolidCube(1);
		glPopMatrix();
	}
}


void sunce() {
	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(0, 20, 0);
	glutSolidSphere(5, 10, 10);
	glPopMatrix();
}

void drawCroshair()
{
	glLoadIdentity();
	glColor3f(1, 0, 0);
	glRectf(windowWidth / 2 - 1, windowHeight / 2 - 1, windowWidth / 2 + 1, windowHeight / 2 + 1);
}

void display(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0); //clear the screen to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
	glLoadIdentity();

	camera();
	enable();

	go.transform.rotation.y++;
	go.draw();

	koordinate();
	zid();
	podloga();
	sunce();
	cube(); //call the cube drawing function

	glutSwapBuffers(); //swap the buffers
	angle++; //increase the angle
}

void reshape(int w, int h) {
	windowWidth = w;
	windowHeight = h;
	glViewport(0, 0, w, h); //set the viewport	to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection

	glLoadIdentity();
	gluPerspective(60, (float)w / h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , 	depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model

}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'q')
	{
		xrot += 1;
		if (xrot > 360) xrot -= 360;
	}

	if (key == 'z')
	{
		xrot -= 1;
		if (xrot < -360) xrot += 360;
	}

	if (key == 'w')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos += float(sin(yrotrad));
		zpos -= float(cos(yrotrad));
		//ypos -= float(sin(xrotrad));
	}

	if (key == 's')
	{
		float xrotrad, yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);
		xpos -= float(sin(yrotrad));
		zpos += float(cos(yrotrad));
		//ypos += float(sin(xrotrad));
	}

	if (key == 'd')
	{
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * 0.2;
		zpos += float(sin(yrotrad)) * 0.2;
	}

	if (key == 'a')
	{
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * 0.2;
		zpos -= float(sin(yrotrad)) * 0.2;
	}

	if (key == 27)
	{
		exit(0);
	}
}

void mouseMovement(int x, int y) {
	yrot += (x - 400) * 0.1;
	int deltaY = y - 300;
	if (deltaY > 0 && xrot <= 90 || deltaY < 0 && xrot >= -90)
		xrot += deltaY * 0.1;

	glutWarpPointer(400, 300);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	windowWidth = 1280;
	windowHeight = 720;
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("A basic OpenGL Window");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	glutPassiveMotionFunc(mouseMovement); //check for mouse movement

	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
