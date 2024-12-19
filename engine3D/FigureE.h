#pragma once
#include "IndiceDraw.h"

class FigureE: public IndiceDraw {
public:
	FigureE(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors);
};