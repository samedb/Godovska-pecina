#include "Sunce.h"

Sunce::Sunce(Transform transform)
	:GameObject(transform)
{
	// Ovo ce sve lepo ovde da strpam

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	// Light property vectors.
	float lightAmb[] = { 0.2, 0.2, 0.2, 1.0 };
	float lightDif[] = { 1, 1, 1, 1.0 };
	float lightSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float lightPos[] = { 0, 5, 0, 1.0 };
	float globAmb[] = { 0.0, 0.0, 0.0, 1.0 };

	// Light properties.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.001);
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);

	glEnable(GL_LIGHT0); // Enable particular light source.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // Enable two-sided lighting.
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.


	// Postaljvanje osobina materijala
	// Material property vectors.
	float matAmbAndDif1[] = { 1, 1, 1, 1.0 };
	float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float matShine[] = { 50.0 };

	// Material properties of the box.
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
}

void Sunce::render()
{
	// ukljuci emisiju nacrtaj sunce i onda iskljuci, tako da samo sunce "emituje svetlost" da deluje da je puno svetlije od ostatka
	glColor3f(1, 1, 0);
	float poz[] = { transform.position.x, transform.position.y, transform.position.z };
	glLightfv(GL_LIGHT0, GL_POSITION, poz);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, svetlo);
	glutSolidSphere(2, 20, 20);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, tamno);

}
