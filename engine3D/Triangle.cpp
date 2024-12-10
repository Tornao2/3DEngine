#include "Triangle.h"

Triangle::Triangle(std::vector <glm::vec4> readData) {
	data = readData;
}

void Triangle::drawFigure(int index) {
	glDrawArrays(GL_TRIANGLES, index, 3);
}

void Triangle::changeFirstPoint(std::vector <glm::vec4> firstPoint) {
	data[0] = firstPoint[0];
	data[1] = firstPoint[1];
	callForRefresh = true;
}

void Triangle::changeSecondPoint(std::vector <glm::vec4> secondPoint) {
	data[2] = secondPoint[0];
	data[3] = secondPoint[1];
	callForRefresh = true;
}

void Triangle::changeThirdPoint(std::vector <glm::vec4> thirdPoint) {
	data[4] = thirdPoint[0];
	data[5] = thirdPoint[1];
	callForRefresh = true;
}

std::vector <glm::vec4> Triangle::getFirstPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[0]);
	returnData.push_back(data[1]);
	return returnData;
}

std::vector <glm::vec4> Triangle::getSecondPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[2]);
	returnData.push_back(data[3]);
	return returnData;
}

std::vector <glm::vec4> Triangle::getThirdPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[4]);
	returnData.push_back(data[5]);
	return returnData;
}