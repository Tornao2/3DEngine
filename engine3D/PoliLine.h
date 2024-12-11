#pragma once
#include "Primitive.h"

class PoliLine :public Primitive {
private:
	bool closed;
public:
	PoliLine(std::vector <glm::vec4> readData, int readSize, bool readClosed);
	void drawFigure(int index);
	void changePoint(std::vector <glm::vec4> point, int index);
	void addPoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
	void removePoint(int index);
	bool getIfClosed();
	void setIfClosed(bool readClosed);
};