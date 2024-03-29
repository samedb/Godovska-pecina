#include "TextureManager.h"

TextureManager* TextureManager::instance = 0;

GLuint TextureManager::LoadTexture(string path, int width, int height)
{
	GLuint texture = 0;
	char* data = nullptr;

	ifstream fin;
	fin.open(path, ios::binary);

	if (fin.is_open()) {
		data = new char[width * height * 4];
		fin.ignore(54, '\n');
		fin.read(data, width * height * 4);
		fin.close();
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	delete[] data;
	return texture;
}

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	teksture.clear();
}

TextureManager* TextureManager::getInstance()
{
	if (instance == 0) {
		instance = new TextureManager();
		instance->UcitajTeksture();
	}
	return instance;
}

void TextureManager::DodajTeksturu(string nazivTeksture, string path, int width, int height)
{
	GLuint tex = LoadTexture(path, width, height);
	teksture.insert(pair<string, GLuint>(nazivTeksture, tex));
}

GLuint TextureManager::UzmiTeksturu(string nazivTeksture)
{
	return teksture[nazivTeksture];
}

void TextureManager::UcitajTeksture()
{
	DodajTeksturu("pod", "texture.raw", 256, 256);
	DodajTeksturu("zid", "texture1.raw", 256, 256);
	DodajTeksturu("plafon", "texture2.raw", 256, 256);
	DodajTeksturu("pod2", "pixelart.bmp", 16, 16);
	DodajTeksturu("pack", "texture pack.bmp", 512, 512);
	DodajTeksturu("grass", "grass.bmp", 800, 800);
}

GLuint& TextureManager::operator[](const string key)
{
	return teksture[key];
}
