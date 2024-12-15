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
	std::vector<DirectDraw*> directList;
	std::vector<IndiceDraw*> indicedList;
	std::vector<unsigned short int> totalIndices;
public:
	ObjectManager(Shader* readShader);
	ObjectManager();
	void addDirectDrawable(DirectDraw* readPrimitive, int index = -1);
	void removeDirectDrawable(int index = -1);
	DirectDraw* getDirectDrawable(int index = -1);
	void addIndicedDrawable(IndiceDraw* readFigure, int index = -1);
	void removeFigure(int index = -1);
	IndiceDraw* getIndicedDrawable(int index = -1);
	void clearIndicedList();
	void clearDirectListList();
	void drawAll();
	void setShader(Shader* readShader);
	void refreshBuffer();
};