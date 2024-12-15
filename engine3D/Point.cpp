#include "Point.h"

Point::Point(std::vector <glm::vec4> readData, float readSize) {
	data = readData;
	size = readSize;
}

void Point::drawDirect(int index) {
	glPointSize((GLfloat)size);
	glDrawArrays(GL_POINTS, index, 1);
}