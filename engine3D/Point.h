#pragma once
#include "Primitive.h"

class Point :public Primitive {
private:
	int size;
public:
	Point(float point[6], int readSize);
	void drawFigure(Shader* shader);
};