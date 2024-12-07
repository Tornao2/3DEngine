#pragma once
#include "Primitive.h"

class Point :public Primitive {
private:
	int size;
public:
	Point(float point[3], float color[3], int readSize);
	void drawFigure();
	int getSize();
	void setSize(int readSize);
};