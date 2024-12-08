#include "Point.h"

Point::Point(float point[6], int readSize) {
	vertex = new float[6];
	vertex = point;
	size = readSize;
}

void Point::drawFigure(Shader* shader) {
	glBindBuffer(GL_ARRAY_BUFFER, shader->getVBO());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (GLvoid*)(sizeof(float) * 3));
	glEnableVertexAttribArray(1);
	glPointSize(size);
	glDrawArrays(GL_POINTS, 0, 2);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
