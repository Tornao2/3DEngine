#pragma once
#include "Primitive.h"

class Point :public Primitive {
public:
	Point(std::vector <glm::vec4> readData, int readSize);
	void drawFigure(int index);
};