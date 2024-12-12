#pragma once
#include "Figure.h"

class Cube :public Figure {
public:
	Cube(float sideLength, float x, float y, float z, std::vector <glm::vec4> colors);
};
 