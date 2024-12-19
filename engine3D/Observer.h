#pragma once
#include "ShaderHandler.h"
#include <glm/gtc/type_ptr.hpp>

class Observer {
protected:
	Shader* shader;
	glm::mat4 viewMatrix;
	glm::vec3 cameraPos;
	glm::vec3 target;
	glm::vec3 up;
	float lastX, lastY, yaw, pitch;
public:
	Observer(Shader* readHandler);
	void updateCamera();
    Shader* getShader();
    glm::mat4 getviewMatrix();
    glm::vec3 getCameraPos();
    glm::vec3 getTarget();
    glm::vec3 getUp();
    float getLastX();
    float getLastY();
    float getYaw();
    float getPitch();
    void setShader(Shader* readShader);
    void setviewMatrix(glm::mat4 readMatrix);
    void setCameraPos(glm::vec3 readPos);
    void setTarget(glm::vec3 readTarget);
    void setUp(glm::vec3 readUp);
    void setLastX(float readX);
    void setLastY(float readY);
    void setYaw(float readYaw);
    void setPitch(float readPitch);
};