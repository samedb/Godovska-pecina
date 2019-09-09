#include "Kamera.h"

Kamera::Kamera(Transform transform)
	:GameObject(transform)
{
	brzinaKretanja = 0.5;
	mouseSensitivity = 0.1;
	napred = nazad = levo = desno = false;
}

void Kamera::draw()
{
	glRotatef(transform.rotation.x , 1.0, 0.0, 0.0);  //rotate our camera on teh x - axis(left and right)
	glRotatef(transform.rotation.y, 0.0, 1.0, 0.0);  //rotate our camera on the	y - axis(up and down)
	glTranslated(-transform.position.x, -transform.position.y, -transform.position.z); //translate the screen to the position of our camera																		// gde je gore, po y osi je	


	// Za neki drugi put 
	// Da uradim kameru preko gluLookAt
	//
	//Vektor3f centar; // tacka u koju kamera gleda
	//centar.x = transform.position.x + cos(transform.rotation.y * 3.14159 / 180);
	//centar.z = transform.position.z + sin(transform.rotation.y * 3.14159 / 180);
	//centar.y = transform.position.y + tan(transform.rotation.x * 3.14150 / 180) * sqrt(centar.x * centar.x + centar.z * centar.z);

	//gluLookAt(transform.position.x, transform.position.y, transform.position.z,			// pozicija kamere
	//		  centar.x, centar.y, centar.z,
	//		  0, -1, 0);
}

void Kamera::reshapeFunc(int w, int h)
{
	glViewport(0, 0, w, h); //set the viewport	to the current window specifications
	glMatrixMode(GL_PROJECTION); //set the matrix to projection

	glLoadIdentity();
	gluPerspective(60, (float)w / h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , 	depth)
	glMatrixMode(GL_MODELVIEW); //set the matrix back to model
}

void Kamera::passiveMotionFunc(int x, int y)
{
	float mouseSensitivity = 0.1;

	transform.rotation.y += (x - 400) * mouseSensitivity;

	int delta = y - 300;
	if (delta > 0 && transform.rotation.x <= 90 || delta < 0 && transform.rotation.x >= -90) // postavljam gornju i donju granicu za rotaciju po x osi
		transform.rotation.x += delta * 0.1;

	glutWarpPointer(400, 300); // postavi mouse pointer na poziciju (400, 300)

}

void Kamera::update()
{
	float x1 = desno - levo, z1 = nazad - napred; // (x1, z1) predstavlju vektor koliko treba pomeriti igraca ali pre rotacije

	float ugao = transform.rotation.y * 3.1415 / 180; // ugao u radijanima koliko je kamera okrenuta po y osi, 

	// vektor (x1, z1) rotiram za ugao po formuli za rotaciju 2d vektora i dobijam novi vektor (x2, z2);
	float x2 = x1 * cos(ugao) - z1 * sin(ugao);
	float z2 = x1 * sin(ugao) + z1 * cos(ugao);

	movement.x = x2 * brzinaKretanja;
	movement.z = z2 *brzinaKretanja;

	if (letenje)
		movement.y = (gore - dole) * brzinaKretanja;
	else
	{
		if (transform.position.y > 2) // ako se nalazi u vazduhu onda gravitacija utice na njega
			movement.y -= gravitacija;
		else
			movement.y = 0;

		// skok
		if (gore && transform.position.y <= 2) {
			movement.y = brzinaSkoka;
		}
		// cucanj
		else if (dole)
			transform.position.y = 1;
		else if (transform.position.y == 1) // ako nije cucanj
			transform.position.y = 2; // normalna pozicija

	}

	move(); // updateuj poziciju za vektor movement
}

void Kamera::move()
{
	transform.position.x += movement.x;
	transform.position.y += movement.y;
	transform.position.z += movement.z;
}
