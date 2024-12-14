#pragma once
#include "ShaderHandler.h"
#include <glm/gtc/type_ptr.hpp>

class Observer {
	Shader* shader;
	glm::mat4 modelViewMatrix;
	glm::vec3 cameraPos;
	glm::vec3 target;
	glm::vec3 up;
	float lastX, lastY, yaw, pitch;
public:
	Observer(Shader* readHandler);
	void updateCamera();
    Shader* getShader();
    glm::mat4 getModelViewMatrix();
    glm::vec3 getCameraPos();
    glm::vec3 getTarget();
    glm::vec3 getUp();
    float getLastX();
    float getLastY();
    float getYaw();
    float getPitch();
    void setShader(Shader* shaderPtr);
    void setModelViewMatrix(glm::mat4 matrix);
    void setCameraPos(glm::vec3 pos);
    void setTarget(glm::vec3 targetVec);
    void setUp(glm::vec3 upVec);
    void setLastX(float x);
    void setLastY(float y);
    void setYaw(float y);
    void setPitch(float p);
};