#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

class Quads :public DirectDraw, public TransformableFigure {
public:
	Quads(std::vector <glm::vec4> readData);
	void drawDirect(int index);
	void changeFirstPoint(std::vector <glm::vec4> firstPoint);
	void changeSecondPoint(std::vector <glm::vec4> secondPoint);
	void changeThirdPoint(std::vector <glm::vec4> thirdPoint);
	void changeFourthPoint(std::vector <glm::vec4> fourthPoint);
	std::vector <glm::vec4> getFirstPoint();
	std::vector <glm::vec4> getSecondPoint();
	std::vector <glm::vec4> getThirdPoint();
	std::vector <glm::vec4> getFourthPoint();
};