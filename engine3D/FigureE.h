#pragma once
#include "IndiceDraw.h"

class FigureE: public IndiceDraw {
public:
	FigureE(float sideLength, float x, float y, float z, std::vector<glm::vec4> colors);
	FigureE();
};