#include "Triangle.h"

Triangle::Triangle(std::vector <glm::vec4> readData) {
	data = readData;
}

void Triangle::drawDirect(int index) {
	glDrawArrays(GL_TRIANGLES, index, 3);
}