#pragma once
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include "Figures.h"

class TransformableFigure: public virtual Figures {
public:
	void translate(glm::vec3 readChange);
	void rotate(float angle, glm::vec3 axis);
	void scale(float readScale);
	void freeTransform(glm::mat4 readMatr);
};