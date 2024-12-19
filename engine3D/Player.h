#pragma once
#include "Cube.h"

class Player: public Cube {
protected:
	static Player* instance;
	float msX, msY, msZ;
public:
	Player(float readSideLength, float readX, float readY, float readZ, std::vector <glm::vec4> readColors);
	void setMsX(float readMs);
	void setMsY(float readMs);
	void setMsZ(float readMs);
	float getMsX();
	float getMsY();
	float getMsZ();
	static void move();
	static Player* getInstance();
};