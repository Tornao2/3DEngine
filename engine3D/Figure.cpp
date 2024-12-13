#include "Figure.h"

std::vector<unsigned short int> Figure::getIndices() {
	return indices;
}

void Figure::setIndices(std::vector<unsigned short int> readIndices) {
	indices = readIndices;
}

std::vector <glm::vec4> Figure::getData() {
	return data;
}

void Figure::setData(std::vector <glm::vec4> readData) {
	data = readData;
	callForRefresh = true;
}

int Figure::getDataCount() {
	return data.size();
}

void Figure::updateIndiceCount(unsigned short int& index) {
	index += data.size()/3;
}

bool Figure::getIfRefresh() {
	return callForRefresh;
}

void Figure::setIfRefresh(bool readRefresh) {
	callForRefresh = readRefresh;
}

void Figure::changePoint(std::vector <glm::vec4> point, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data[realIndex] = point[0];
	data[realIndex + 1] = point[1];
	data[realIndex + 2] = point[2];
	callForRefresh = true;
}

std::vector <glm::vec4> Figure::getPoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return {};
	std::vector <glm::vec4> realData;
	realData.push_back(data[realIndex]);
	realData.push_back(data[realIndex + 1]);
	realData.push_back(data[realIndex + 2]);
	return realData;
}

