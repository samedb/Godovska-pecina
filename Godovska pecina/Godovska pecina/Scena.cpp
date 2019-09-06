#include "Scena.h"

Scena::Scena(Transform transform)
	:GameObject(transform)
{
}

Scena::Scena(const Scena& s)
	:GameObject(s.transform)
{
	for (GameObject* go : s.elementiScene)
		elementiScene.push_back(go);
}

void Scena::dodaj(GameObject* go)
{
	elementiScene.push_back(go);
}

void Scena::render()
{
	for (GameObject* go : elementiScene)
		go->draw();
}

void Scena::update()
{
	for (GameObject* go : elementiScene)
		go->update();
}
