#include "Line.h"

Line::Line(std::vector <glm::vec4> readData, int readSize) {
	data = readData;
	size = readSize;
}

void Line::drawFigure(int index) {
	glLineWidth(size);
	glDrawArrays(GL_LINES, index, 2);
}

void Line::changeFirstPoint(std::vector <glm::vec4> firstPoint) {
	data[0] = firstPoint[0];
	data[1] = firstPoint[1];
	callForRefresh = true;
}

void Line::changeSecondPoint(std::vector <glm::vec4> secondPoint) {
	data[2] = secondPoint[0];
	data[3] = secondPoint[1];
	callForRefresh = true;
}

std::vector <glm::vec4> Line::getFirstPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[0]);
	returnData.push_back(data[1]);
	return returnData;
}

std::vector <glm::vec4> Line::getSecondPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[2]);
	returnData.push_back(data[3]);
	return returnData;
}