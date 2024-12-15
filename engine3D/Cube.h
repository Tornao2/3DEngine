#pragma once
#include "IndiceDraw.h"
#include "Transformable.h"

class Cube :public IndiceDraw, public Transformable {
	float sideLength, x, y, z;
public:
	Cube(float rSideLength, float rx, float ry, float rz, std::vector <glm::vec4> colors);
	void translate(glm::vec3 readChange) override;
	void rotate(float angle, glm::vec3 axis) override;
	void scale(glm::vec3 readChange) override;
	void freeTransform(glm::mat4 readMatr) override;
};
 