#include "TriangleFan.h"

TriangleFan::TriangleFan(std::vector <glm::vec4> readData) {
	data = readData;
}

void TriangleFan::drawFigure(int index) {
	glDrawArrays(GL_TRIANGLE_FAN, index, (GLsizei)data.size() / 3);
}

void TriangleFan::addPoint(std::vector <glm::vec4> point, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0) {
		data.push_back(point[0]);
		data.push_back(point[1]);
		data.push_back(point[2]);
	}
	else {
		data.insert(data.begin() + realIndex, point[2]);
		data.insert(data.begin() + realIndex, point[1]);
		data.insert(data.begin() + realIndex, point[0]);
	}
	callForRefresh = true;
}

void TriangleFan::changePoint(std::vector <glm::vec4> point, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data[realIndex] = point[0];
	data[realIndex + 1] = point[1];
	data[realIndex + 2] = point[2];
	callForRefresh = true;
}

std::vector <glm::vec4> TriangleFan::getPoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return {};
	std::vector <glm::vec4> realData;
	realData.push_back(data[realIndex]);
	realData.push_back(data[realIndex + 1]);
	realData.push_back(data[realIndex + 2]);
	return realData;
}

void TriangleFan::removePoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data.erase(data.begin() + realIndex + 2);
	data.erase(data.begin() + realIndex + 1);
	data.erase(data.begin() + realIndex);
	callForRefresh = true;
}
