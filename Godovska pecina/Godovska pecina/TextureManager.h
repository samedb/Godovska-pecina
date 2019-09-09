#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <GL/glut.h>

using namespace std;

class TextureManager
{
private:
	std::map<string, GLuint> teksture;
	GLuint LoadTexture(string path, int width, int height);
public:
	TextureManager();
	~TextureManager();

	void DodajTeksturu(string nazivTeksture, string path, int width, int height);
	GLuint UzmiTeksturu(string nazivTeksture);
	void UcitajTeksture();
	GLuint& operator[](const string key);
};

