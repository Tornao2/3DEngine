#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class TriangleStrip :public DirectDraw, public TransformableFigure {
public:
	TriangleStrip(std::vector <glm::vec4> readData);
	void drawDirect(int index);
	void addPoint(std::vector <glm::vec4> readPoint, int index);
	void removePoint(int index);
};