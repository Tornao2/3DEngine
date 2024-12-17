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
	void changePoint(std::vector <glm::vec4> point, int index);
	void addPoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
	void removePoint(int index);
	bool getIfClosed();
	void setIfClosed(bool readClosed);
};