#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

class Line :public DirectDraw, public Resizable, public TransformableFigure {
public:
	Line(std::vector <glm::vec4> readData, float readSize);
	void drawDirect(int index);
};