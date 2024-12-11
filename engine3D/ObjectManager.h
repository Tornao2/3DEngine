#pragma once
#include "ShaderHandler.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "PoliLine.h"
#include "TriangleStrip.h"
#include "TriangleFan.h"
#include "Quads.h"
#include "Cube.h"

class ObjectManager {
private:
	Shader* shader;
	std::vector<Primitive*> primitiveList;
public:
	ObjectManager(Shader* readShader);
	ObjectManager();
	void addFigure(Primitive* readFigure, int index = -1);
	void removeFigure(int index = -1);
	Primitive* getFigure(int index = -1);
	void clearList();
	void drawAll();
	void setShader(Shader* readShader);
	void refreshBuffer();
};