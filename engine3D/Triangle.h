#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class Triangle :public DirectDraw, public TransformableFigure {
public:
	Triangle(std::vector <glm::vec4> readData);
	void drawDirect(int index);
};