#pragma once
#include "IndiceDraw.h"
#include "TransformableFigure.h"

class Cube :public IndiceDraw, public TransformableFigure {
protected:
	float sideLength, x, y, z;
public:
	Cube(float readSideLength, float readX, float readY, float readZ, std::vector <glm::vec4> readColors = std::vector <glm::vec4> ());
};
 