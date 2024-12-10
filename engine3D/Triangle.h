#pragma once
#include "Primitive.h"

class Triangle :public Primitive {
public:
	Triangle(std::vector <glm::vec4> readData);
	void drawFigure(int index);
	void changeFirstPoint(std::vector <glm::vec4> firstPoint);
	void changeSecondPoint(std::vector <glm::vec4> secondPoint);
	void changeThirdPoint(std::vector <glm::vec4> thirdPoint);
	std::vector <glm::vec4> getFirstPoint();
	std::vector <glm::vec4> getSecondPoint();
	std::vector <glm::vec4> getThirdPoint();
};