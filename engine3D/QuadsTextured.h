#pragma once
#include "Quads.h"
#include "Textured.h"

class QuadsTextured :public Quads, public Textured {
public:
	QuadsTextured(std::vector <glm::vec4> readData);
};

