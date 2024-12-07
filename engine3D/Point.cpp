#include "Point.h"

Point::Point(float point[3], float color[3], int readSize) {
	colorVertex = new float[3];
	pointVertex = new float[3];
	pointVertex = point;
	colorVertex = color;
	size = readSize;
}

void Point::drawFigure() {
	glPointSize(size);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, pointVertex);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colorVertex);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

int Point::getSize() {
	return size;
}

void Point::setSize(int readSize) {
	size = readSize;
}