#include "Primitive.h"

std::vector <glm::vec4> Primitive::getData() {
	return data;
}

void Primitive::setData(std::vector <glm::vec4> readData) {
	data = readData;
	callForRefresh = true;
}

int Primitive::getSize() {
	return size;
}

void Primitive::setSize(int readSize) {
	size = readSize;
}

int Primitive::getDataCount() {
	return data.size()/3;
}

void Primitive::updateIndex(int& index) {
	index += data.size()/3;
}

bool Primitive::getIfRefresh() {
	return callForRefresh;
}

void Primitive::setIfRefresh(bool readRefresh) {
	callForRefresh = readRefresh;
}