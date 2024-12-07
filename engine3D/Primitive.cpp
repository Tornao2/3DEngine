#include "Primitive.h"

float* Primitive::getPointVertex() {
	return pointVertex;
}

void Primitive::setPointVertex(float* readVertex) {
	pointVertex = readVertex;
}

float* Primitive::getColorVertex() {
	return colorVertex;
}

void Primitive::setColorVertex(float* readVertex) {
	colorVertex = readVertex;
}