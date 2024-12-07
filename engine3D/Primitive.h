#pragma once
#include <GL/glut.h>

class Primitive {
protected:
	float* pointVertex;
	float* colorVertex;
public:
	float* getPointVertex();
	void setPointVertex(float* readVertex);
	float* getColorVertex();
	void setColorVertex(float* readVertex);
	void virtual drawFigure() = 0;
};
