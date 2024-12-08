#include "Point.h"

Point::Point(float point[6], int readSize) {
	vertex = new float[6];
	vertex = point;
	size = readSize;
}

void Point::drawFigure(Shader* shader) {
	glPointSize(size);
	GLuint positionAttrib = glGetAttribLocation(shader->getProgramId(), "position");
	GLuint colorAttrib = glGetAttribLocation(shader->getProgramId(), "color");
	glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float)*6, 0);
	glEnableVertexAttribArray(positionAttrib);
	glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (GLvoid*)(sizeof(float) * 3));
	glEnableVertexAttribArray(colorAttrib);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableVertexAttribArray(positionAttrib);
	glDisableVertexAttribArray(colorAttrib);
}
