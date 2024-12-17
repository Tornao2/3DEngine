#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

class Point :public DirectDraw, public Resizable, public TransformableFigure {
public:
	Point(std::vector <glm::vec4> readData, float readSize);
	void drawDirect(int index);
};