#pragma once
#include "ShaderHandler.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CameraHandler {
	Shader* shader;
public:
	CameraHandler(Shader* readHandler);
	glm::mat4 modelViewMatrix;
	glm::vec3 cameraPos;
	glm::vec3 target;
	glm::vec3 up;
	float lastX, lastY, yaw, pitch;
	void updateCamera();
};