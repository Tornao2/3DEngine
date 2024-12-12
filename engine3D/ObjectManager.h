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
	std::vector<Figure*> figureList;
	std::vector<unsigned short int> totalIndices;
public:
	ObjectManager(Shader* readShader);
	ObjectManager();
	void addPrimitive(Primitive* readPrimitive, int index = -1);
	void removePrimitive(int index = -1);
	Primitive* getPrimitive(int index = -1);
	void addFigure(Figure* readFigure, int index = -1);
	void removeFigure(int index = -1);
	Figure* getFigure(int index = -1);
	void clearFigureList();
	void clearPrimitiveList();
	void drawAll();
	void setShader(Shader* readShader);
	void refreshBuffer();
};