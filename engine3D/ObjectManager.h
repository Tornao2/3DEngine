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
#include "FigureE.h"

class ObjectManager {
private:
	Shader* shader;
	std::vector<DirectDraw*> primitiveList;
	std::vector<IndiceDraw*> figureList;
	std::vector<unsigned short int> totalIndices;
public:
	ObjectManager(Shader* readShader);
	ObjectManager();
	void addPrimitive(DirectDraw* readPrimitive, int index = -1);
	void removePrimitive(int index = -1);
	DirectDraw* getPrimitive(int index = -1);
	void addFigure(IndiceDraw* readFigure, int index = -1);
	void removeFigure(int index = -1);
	IndiceDraw* getFigure(int index = -1);
	void clearFigureList();
	void clearPrimitiveList();
	void drawAll();
	void setShader(Shader* readShader);
	void refreshBuffer();
};