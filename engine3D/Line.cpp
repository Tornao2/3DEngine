/*#include "Line.h"

Line::Line(float point[6], float color[6], int readSize) {
	colorVertex = new float[6];
	pointVertex = new float[6];
	pointVertex = point;
	colorVertex = color;
	size = readSize;
}

void Line::drawFigure(Shader* shader) {
	glLineWidth(size);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pointVertex);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colorVertex);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Line::changeFirstPoint(float point[3], float color[3]) {
	std::memcpy(&pointVertex[0], point, sizeof(float) * 3);
	std::memcpy(&colorVertex[0], color, sizeof(float) * 3);
}

void Line::changeSecondPoint(float point[3], float color[3]) {
	std::memcpy(&pointVertex[3], point, sizeof(float) * 3);
	std::memcpy(&colorVertex[3], color, sizeof(float) * 3);
}

float* Line::getFirstPoint() {
	float firstPoint[6];
	std::memcpy(&firstPoint[0], &pointVertex[0], sizeof(float) * 3);
	std::memcpy(&firstPoint[3], &colorVertex[0], sizeof(float) * 3);
	return firstPoint;
}

float* Line::getSecondPoint() {
	float secondPoint[6];
	std::memcpy(&secondPoint[0], &pointVertex[3], sizeof(float) * 3);
	std::memcpy(&secondPoint[3], &colorVertex[3], sizeof(float) * 3);
	return secondPoint;
}
*/