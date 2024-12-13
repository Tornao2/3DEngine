#pragma once
#include "Figure.h"

class FigureE: public Figure {
public:
	FigureE(float sideLength, float x, float y, float z, std::vector<glm::vec4> colors);
};