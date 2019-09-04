#pragma once

#include "Vektor3f.h"
class Transform
{
public:
	Vektor3f position;
	Vektor3f rotation;
	Vektor3f scale;

	Transform(Vektor3f position = Vektor3f(), Vektor3f rotation = Vektor3f(), Vektor3f scale = Vektor3f());
};

