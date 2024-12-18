#pragma once
#include "Figures.h"

std::vector <glm::vec4> Figures::getData() {
	return data;
}

void Figures::setData(std::vector <glm::vec4> readData) {
	data = readData;
	callForRefresh = true;
}

int Figures::getDataCount() {
	return (int)data.size() / 3;
}

void Figures::changePoint(std::vector <glm::vec4> point, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data[realIndex] = point[0];
	data[realIndex + 1] = point[1];
	data[realIndex + 2] = point[2];
	callForRefresh = true;
}

std::vector<glm::vec4> Figures::getPoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return {};
	std::vector <glm::vec4> realData;
	realData.push_back(data[realIndex]);
	realData.push_back(data[realIndex + 1]);
	realData.push_back(data[realIndex + 2]);
	return realData;
}

void Figures::setTextured(bool readVal) {
	isTextured = readVal;
}

bool Figures::getTextured() {
	return isTextured;
}