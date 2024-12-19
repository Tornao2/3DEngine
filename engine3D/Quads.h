#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class Quads :public DirectDraw, public TransformableFigure {
public:
	Quads(std::vector <glm::vec4> readData);
	void drawDirect(int index);
};