#include "PoliLine.h"

PoliLine::PoliLine(std::vector <glm::vec4> readData, float readSize, bool readClosed) {
	data = readData;
	size = readSize;
	closed = readClosed;
}

void PoliLine::drawDirect(int index) {
	glLineWidth((GLfloat) size);
	if (closed) 
		glDrawArrays(GL_LINE_LOOP, index, (GLsizei)data.size() / 3);
	else 
		glDrawArrays(GL_LINE_STRIP, index, (GLsizei)data.size() / 3);
}

void PoliLine::addPoint(std::vector <glm::vec4> readPoint, int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0) {
		data.push_back(readPoint[0]);
		data.push_back(readPoint[1]);
		data.push_back(readPoint[2]);
	}
	else {
		data.insert(data.begin() + realIndex, readPoint[2]);
		data.insert(data.begin() + realIndex, readPoint[1]);
		data.insert(data.begin() + realIndex, readPoint[0]);
	}
	callForRefresh = true;
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