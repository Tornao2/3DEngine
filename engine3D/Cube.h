#pragma once
#include "Figure.h"

class Cube :public Figure {
public:
	Cube(std::vector <glm::vec4> posData, std::vector<float> readIndices);
	void drawFigure();
};
