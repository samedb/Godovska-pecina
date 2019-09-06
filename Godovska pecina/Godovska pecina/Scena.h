#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;

class Scena :
	public GameObject
{
public:
	vector<GameObject*> elementiScene;
	Scena(Transform transform = Transform());
	Scena(const Scena& s);
	void dodaj(GameObject* go);
	void render();
	void update();
};

