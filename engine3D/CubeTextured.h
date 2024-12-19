#pragma once
#include "Cube.h"
#include "Textured.h"

class CubeTextured : public Cube, public Textured {
public:
	CubeTextured(float readSideLength, float readX, float readY, float readZ);
};