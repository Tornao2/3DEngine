#include "Quads.h"

Quads::Quads(std::vector <glm::vec4> readData) {
	data = readData;
}

void Quads::drawFigure(int index) {
	glDrawArrays(GL_QUADS, index, 4);
}

void Quads::changeFirstPoint(std::vector <glm::vec4> firstPoint) {
	data[0] = firstPoint[0];
	data[1] = firstPoint[1];
	data[2] = firstPoint[2];
	callForRefresh = true;
}

void Quads::changeSecondPoint(std::vector <glm::vec4> secondPoint) {
	data[3] = secondPoint[0];
	data[4] = secondPoint[1];
	data[5] = secondPoint[2];
	callForRefresh = true;
}

void Quads::changeThirdPoint(std::vector <glm::vec4> thirdPoint) {
	data[6] = thirdPoint[0];
	data[7] = thirdPoint[1];
	data[8] = thirdPoint[2];
	callForRefresh = true;
}

void Quads::changeFourthPoint(std::vector <glm::vec4> fourthPoint) {
	data[9] = fourthPoint[0];
	data[10] = fourthPoint[1];
	data[11] = fourthPoint[2];
	callForRefresh = true;
}

std::vector <glm::vec4> Quads::getFirstPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[0]);
	returnData.push_back(data[1]);
	returnData.push_back(data[2]);
	return returnData;
}

std::vector <glm::vec4> Quads::getSecondPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[3]);
	returnData.push_back(data[4]);
	returnData.push_back(data[5]);
	return returnData;
}

std::vector <glm::vec4> Quads::getThirdPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[6]);
	returnData.push_back(data[7]);
	returnData.push_back(data[8]);
	return returnData;
}

std::vector <glm::vec4> Quads::getFourthPoint() {
	std::vector <glm::vec4> returnData;
	returnData.push_back(data[9]);
	returnData.push_back(data[10]);
	returnData.push_back(data[11]);
	return returnData;
}