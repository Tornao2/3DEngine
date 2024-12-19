#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class TriangleFan :public DirectDraw, public TransformableFigure {
public:
	TriangleFan(std::vector <glm::vec4> readData);
	void drawDirect(int index);
	void addPoint(std::vector <glm::vec4> readPoint, int index);
	void removePoint(int index);
};
