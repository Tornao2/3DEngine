#pragma once
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>

class Transformable {
public:
	void virtual translate(glm::vec3 readChange) = 0;
	void virtual rotate(float angle, glm::vec3 axis) = 0;
	void virtual scale(glm::vec3 readChange) = 0;
	void virtual freeTransform(glm::mat4 readMatr) = 0;
};