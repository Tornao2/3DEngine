#pragma once
#include "vector"
#include "Primitive.h"

class ObjectManager {
private:
	Shader* shader;
	std::vector<Primitive*> primitiveList;
public:
	void addFigure(Primitive* readFigure, int index = -1);
	void removeFigure(int index = -1);
	Primitive* getFigure(int index = -1);
	void clearList();
	void drawAll();
	void setShader(Shader* readShader);
};