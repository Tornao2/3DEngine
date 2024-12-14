#pragma once
#include "IndiceDraw.h"

class Cube :public IndiceDraw {
public:
	Cube(float sideLength, float x, float y, float z, std::vector <glm::vec4> colors);
};
 