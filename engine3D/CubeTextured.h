#pragma once
#include "Cube.h"
#include "Textured.h"

class CubeTextured : public Cube, public Textured {
public:
	CubeTextured(float rSideLength, float rx, float ry, float rz);
};