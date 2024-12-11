#pragma once
#include "Primitive.h"

class TriangleFan :public Primitive {
public:
	TriangleFan(std::vector <glm::vec4> readData);
	void drawFigure(int index);
	void changePoint(std::vector <glm::vec4> point, int index);
	void addPoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
	void removePoint(int index);
};
