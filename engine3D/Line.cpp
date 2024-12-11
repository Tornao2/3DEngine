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
	data[2] = firstPoint[2];
	callForRefresh = true;
}

void Line::changeSecondPoint(std::vector <glm::vec4> secondPoint) {
	data[3] = secondPoint[0];
	data[4] = secondPoint[1];
	data[5] = secondPoint[2];
	callForRefresh = true;
}

std::vector <glm::vec4> Line::getFirstPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[0]);
	returnData.push_back(data[1]);
	returnData.push_back(data[2]);
	return returnData;
}

std::vector <glm::vec4> Line::getSecondPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[3]);
	returnData.push_back(data[4]);
	returnData.push_back(data[5]);
	return returnData;
}