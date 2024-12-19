#include "Line.h"

Line::Line(std::vector <glm::vec4> readData, float readSize) {
	data = readData;
	size = readSize;
}

void Line::drawDirect(int index) {
	glLineWidth((GLfloat)size);
	glDrawArrays(GL_LINES, index, 2);
}