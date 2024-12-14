#pragma once
#include "DirectDraw.h"
#include "Resizable.h"

class Point :public DirectDraw, public Resizable {
public:
	Point(std::vector <glm::vec4> readData, float readSize);
	void drawFigure(int index);
};