#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <GL/glut.h>

using namespace std;

// Ova klasa koristi singleton design patter, jer moram veoma cesto da je koristim
// a mucno mi je da je prosledjujem uvek ili iznova da je kreiram

class TextureManager
{
private:

	static TextureManager* instance;

	std::map<string, GLuint> teksture;
	GLuint LoadTexture(string path, int width, int height);
	TextureManager();
	~TextureManager();

public:
	static TextureManager* getInstance();

	void DodajTeksturu(string nazivTeksture, string path, int width, int height);
	GLuint UzmiTeksturu(string nazivTeksture);
	void UcitajTeksture();
	GLuint& operator[](const string key);
};

