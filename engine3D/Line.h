#pragma once
#include "DirectDraw.h"
#include "Resizable.h"

class Line :public DirectDraw, public Resizable {
public:
	Line(std::vector <glm::vec4> readData, float readSize);
	void drawDirect(int index);
	void changeFirstPoint(std::vector <glm::vec4> firstPoint);
	void changeSecondPoint(std::vector <glm::vec4> secondPoint);
	std::vector <glm::vec4> getFirstPoint();
	std::vector <glm::vec4> getSecondPoint();
};