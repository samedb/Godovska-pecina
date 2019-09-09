#include "TextureManager.h"

GLuint TextureManager::LoadTexture(string path, int width, int height)
{
	GLuint texture = 0;
	char* data = nullptr;

	ifstream fin;
	fin.open(path, ios::binary);

	if (fin.is_open()) {
		data = new char[width * height * 3];
		fin.read(data, width * height * 3);
		fin.close();
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
}

GLuint& TextureManager::operator[](const string key)
{
	return teksture[key];
}
