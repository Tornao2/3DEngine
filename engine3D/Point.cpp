#include "Point.h"

Point::Point(std::vector <glm::vec4> readData, int readSize) {
	data = readData;
	size = readSize;
}

void Point::drawFigure(int index) {
	glPointSize(size);
	glDrawArrays(GL_POINTS, index, 1);
}