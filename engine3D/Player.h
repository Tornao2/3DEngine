#pragma once
#include "Cube.h"

class Player: public Cube {
protected:
	static Player* instance;
	float msX, msY, msZ;
public:
	Player(float rSideLength, float rx, float ry, float rz, std::vector <glm::vec4> colors);
	void setMsX(float readMs);
	void setMsY(float readMs);
	void setMsZ(float readMs);
	float getMsX();
	float getMsY();
	float getMsZ();
	static void move();
	static Player* getInstance();
};