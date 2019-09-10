#include "TestScena1.h"


TestScena1::TestScena1(Transform transform)
	:Scena(transform)
{
	glColor3f(1, 1, 1);
	dodaj(new Pravougaonik(Transform(Vektor3f(120, 0, 120), Vektor3f(), Vektor3f(100, 1, 100)), "zid"));
	// dodaj sneskove? oko terena
	for (int i = -4; i < 5; i++)
		for (int j = -4; j < 5; j++)
			if (i == -4 || i == 4 || j == -4 || j == 4)
				dodaj(new Snesko(Vektor3f(i * 10, -1, j * 10)));
	// jedan veliki snesko u sredini
	dodaj(new Snesko(Transform(Vektor3f(-10, -1, -10), Vektor3f(), Vektor3f(10, 10, 10))));
	dodaj(new Snesko(Transform(Vektor3f(-15, -1, -15), Vektor3f(), Vektor3f(10, 10, 10))));
	dodaj(new Teren());

	// dodaj gameobjecte (kocke) sa random pozicijama
	for (int i = 0; i < 10; i++)
	{
		float x = -5 * (rand() % 5 + 5);
		float z = -5 * (rand() % 5 + 5);
		dodaj(new GameObject(Vektor3f(x, 0, z)));
	}


	// iskorpiraj sve to u scenu2 i onda pomeri poziciju
	Scena* scena2 = new Scena(*this);
	scena2->elementiScene[0] = scena2->elementiScene[2];
	scena2->transform.position.z -= 120;
	scena2->transform.rotation.y += 90;
	dodaj(scena2);

	Scena* scena3 = new Scena(*this);
	scena3->elementiScene[0] = scena3->elementiScene[2];
	scena3->transform.position.x -= 120;
	scena3->transform.rotation.y -= 90;
	dodaj(scena3);

	Scena* scena4 = new Scena(*this);
	scena4->elementiScene[0] = scena3->elementiScene[2];
	scena4->transform.position.z -= 120;
	scena4->transform.position.x -= 120;
	scena4->transform.rotation.y += 180;
	dodaj(scena4);


	dodaj(new Sunce(Vektor3f(0, 30, 0)));
}
