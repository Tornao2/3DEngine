#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class TriangleStrip :public DirectDraw, public TransformableFigure {
public:
	TriangleStrip(std::vector <glm::vec4> readData);
	void drawDirect(int index);
	void changePoint(std::vector <glm::vec4> point, int index);
	void addPoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
	void removePoint(int index);
};