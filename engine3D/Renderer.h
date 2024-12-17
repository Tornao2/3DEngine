#pragma once
#include "ObjectManager.h"
#include <glm/gtc/type_ptr.hpp>

class Renderer {
private:
	void renderProper();
	static Renderer* instance;
	glm::vec3 clearColor;
	bool enableZBuffer;
	bool orthogonalView;
	ObjectManager* manager;
	Shader* shader;
	glm::mat4 projectionMatrix;
	float ambientStrength;
	float specularStrength;
	int scatterStrength;
	float boostColor;
	glm::vec3 lightPos;
	bool warnModel;
	float angleWarnCutOff;
	float intensityWarn;
public:
	Renderer(ObjectManager* readManager, glm::vec3 readClearColor = { 0, 0, 0 }, bool zBuffer = true, bool shouldOrthogonal = true);
	static void render();
	void setClearColor(glm::vec3 readClearColor);
	glm::vec3 getClearColor();
	void setZBuffer(bool should);
	bool getZBuffer();
	bool getOrthogonal();
	void setOrthogonal(bool shouldOrthogonal);
	ObjectManager* getManager();
	void replaceManager(ObjectManager* readManager);
	void setUpShaders();
	Shader* getShader();
	void setLightingPos(glm::vec3 readLighting);
	glm::vec3 getLightingPos();
	void setAmbientStrength(float readStrength);
	float getAmbientStrength();
	void setSpecularStrength(float readStrength);
	float getSpecularStrength();
	void setScatterStrength(int readStrength);
	int getScatterStrength();
	void setBoostColor(float readBoost);
	float getBoostColor();
	void toggleIfFlatShading();
	bool getWarnModel();
	void setWarnModel(bool readVal);
	void setWarnCutOff(float readCutOff);
	float getWarnCutOff();
	void setWarnIntensity(float readIntensity);
	float getWarnIntensity();
};