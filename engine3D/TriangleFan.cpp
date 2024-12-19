#include "TriangleFan.h"

TriangleFan::TriangleFan(std::vector <glm::vec4> readData) {
	data = readData;
}

void TriangleFan::drawDirect(int index) {
	glDrawArrays(GL_TRIANGLE_FAN, index, (GLsizei)data.size() / 3);
}

void TriangleFan::addPoint(std::vector <glm::vec4> readPoint, int index) {
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

void TriangleFan::removePoint(int index) {
	int realIndex = index * 3;
	if (data.size() <= realIndex || realIndex < 0)
		return;
	data.erase(data.begin() + realIndex + 2);
	data.erase(data.begin() + realIndex + 1);
	data.erase(data.begin() + realIndex);
	callForRefresh = true;
}
