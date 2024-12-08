#pragma once
#include "ShaderHandler.h"
#include <GL/glut.h>

class Primitive {
protected:
	float* vertex;
	int size;
public:
	float* getVertex();
	void setVertex(float* readVertex);
	void virtual drawFigure(Shader* shader) {};
	int getSize();
	void setSize(int readSize);
	int virtual getVerticeSize() { return sizeof(vertex); };
};
