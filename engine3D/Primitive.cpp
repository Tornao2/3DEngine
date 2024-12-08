#include "Primitive.h"

float* Primitive::getVertex() {
	return vertex;
}

void Primitive::setVertex(float* readVertex) {
	vertex = readVertex;
}

int Primitive::getSize() {
	return size;
}

void Primitive::setSize(int readSize) {
	size = readSize;
}
