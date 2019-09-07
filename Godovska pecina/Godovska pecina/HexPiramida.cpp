#include "HexPiramida.h"

HexPiramida::HexPiramida(Transform transform, float visina)
	:GameObject(transform)
{
	this->visina = visina;
}

HexPiramida::HexPiramida(Vektor3f centarBaze, Vektor3f vrhPiramide)
{
	transform.position = centarBaze;
	visina = sqrt(pow(centarBaze.x - vrhPiramide.x, 2) + pow(centarBaze.y - vrhPiramide.y, 2) + pow(centarBaze.z - vrhPiramide.z, 2));
	/*transform.rotation = Vektor3f( atan2(sqrt(vrhPiramide.y * vrhPiramide.y + vrhPiramide.z * vrhPiramide.z), vrhPiramide.x) * 180 / 3.14159,
								   atan2(sqrt(vrhPiramide.x * vrhPiramide.x + vrhPiramide.z * vrhPiramide.z), vrhPiramide.y) * 180 / 3.14159,
								   atan2(sqrt(vrhPiramide.y * vrhPiramide.y + vrhPiramide.x * vrhPiramide.x), vrhPiramide.z) * 180 / 3.14159);
	*/
	transform.rotation = Vektor3f(0, 
		atan(vrhPiramide.z / vrhPiramide.x) * 180 / 3.14159,
		atan(vrhPiramide.y / sqrt(vrhPiramide.x * vrhPiramide.x + vrhPiramide.z * vrhPiramide.z)) * 180 / 3.14159);
	transform.scale = Vektor3f(1, 1, 1);

	// Mozda bolje ovako
	//HexPiramida(Transform(poz, rot, scale), visina);

}

void HexPiramida::render()
{
	glColor3f(1, 1, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, visina, 0);
		glVertex3f(2 * sqrt(3) / 3, 0, 0);
		glVertex3f(sqrt(3) / 3, 0, 1);
		glVertex3f(-sqrt(3) / 3, 0, 1);
		glVertex3f(-2 * sqrt(3) / 3, 0, 0);
		glVertex3f(-sqrt(3) / 3, 0, -1);
		glVertex3f(sqrt(3) / 3, 0, -1);
		glVertex3f(2 * sqrt(3) / 3, 0, 0);
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
