#include "PoliLine.h"

PoliLine::PoliLine(std::vector <glm::vec4> readData, float readSize, bool readClosed) {
	data = readData;
	size = readSize;
	closed = readClosed;
}

void PoliLine::drawFigure(int index) {
	glLineWidth((GLfloat) size);
	if (closed) 
		glDrawArrays(GL_LINE_LOOP, index, (GLsizei)data.size() / 3);
	else 
		glDrawArrays(GL_LINE_STRIP, index, (GLsizei)data.size() / 3);
}

void PoliLine::addPoint(std::vector <glm::vec4> point, int index) {
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

void PoliLine::changePoint(std::vector <glm::vec4> point, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data[realIndex] = point[0];
	data[realIndex + 1] = point[1];
	data[realIndex + 2] = point[2];
	callForRefresh = true;
}

std::vector <glm::vec4> PoliLine::getPoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return {};
	std::vector <glm::vec4> realData;
	realData.push_back(data[realIndex]);
	realData.push_back(data[realIndex + 1]);
	realData.push_back(data[realIndex + 2]);
	return realData;
}

void PoliLine::removePoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data.erase(data.begin() + realIndex + 2);
	data.erase(data.begin() + realIndex + 1);
	data.erase(data.begin() + realIndex);
	callForRefresh = true;
}

bool PoliLine::getIfClosed() {
	return closed;
}

void PoliLine::setIfClosed(bool readClosed) {
	closed = readClosed;
}