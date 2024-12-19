#pragma once
#include "ShaderHandler.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "PoliLine.h"
#include "TriangleStrip.h"
#include "TriangleFan.h"
#include "QuadsTextured.h"
#include "CubeTextured.h"
#include "FigureE.h"
#include "Player.h"
#include "Observer.h"

class ObjectManager {
private:
	Shader* shader;
	std::vector<DirectDraw*> directList;
	std::vector<IndiceDraw*> indicedList;
	std::vector<IndiceDraw*> indicedTexturedList;
	std::vector<unsigned short int> totalIndices;
	std::vector<unsigned short int> totalIndicesTextured;
	Observer* camera;
public:
	ObjectManager();
	void addDirectDrawable(DirectDraw* readDirect, int index = -1);
	void removeDirectDrawable(int index = -1);
	DirectDraw* getDirectDrawable(int index = -1);
	void addIndicedDrawable(IndiceDraw* readIndiced, int index = -1);
	void removeIndicedDrawable(int index = -1);
	IndiceDraw* getIndicedDrawable(int index = -1);
	void addIndicedDrawableTextured(IndiceDraw* readIndiced, int index = -1);
	void removeIndicedDrawableTextured(int index = -1);
	IndiceDraw* getIndicedDrawableTextured(int index = -1);
	void clearIndicedList();
	void clearDirectList();
	void clearIndicedTexturedList();
	void drawAll();
	void setShader(Shader* readShader);
	void refreshBuffer();
	void setCamera(Observer* readCamera);
	Observer* getCamera();
};