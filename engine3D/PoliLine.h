#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

class PoliLine :public DirectDraw, public Resizable, public TransformableFigure {
private:
	bool closed;
public:
	PoliLine(std::vector <glm::vec4> readData, float readSize, bool readClosed);
	void drawDirect(int index);
	void addPoint(std::vector <glm::vec4> readPoint, int index);
	void removePoint(int index);
	bool getIfClosed();
	void setIfClosed(bool readClosed);
};