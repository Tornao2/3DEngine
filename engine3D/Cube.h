#pragma once
#include "IndiceDraw.h"
#include "TransformableFigure.h"

class Cube :public IndiceDraw, public TransformableFigure {
protected:
	float sideLength, x, y, z;
public:
	Cube(float rSideLength, float rx, float ry, float rz, std::vector <glm::vec4> colors);
	Cube();
};
 