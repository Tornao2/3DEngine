#pragma once
#include "Color.h"
#include "ObjectManager.h"
#include <glm/gtc/type_ptr.hpp>

class Renderer {
private:
	void renderProper();
	void prepareView();
	static Renderer* instance;
	Color clearColor;
	bool enableZBuffer;
	bool orthogonalView;
	ObjectManager* manager;
	Shader* shader;
	glm::mat4 projectionMatrix;
	glm::vec4 lightDir;
public:
	Renderer(ObjectManager* readManager, Color readClearColor = { 0, 0, 0, 0 }, glm::vec4 lightingVector = { 1, 1, 1, 0 }, bool zBuffer = true, bool shouldOrthogonal = true);
	static void render();
	void setClearColor(Color readClearColor);
	Color getClearColor();
	void setZBuffer(bool should);
	bool getZBuffer();
	bool getOrthogonal();
	void setOrthogonal(bool shouldOrthogonal);
	ObjectManager* getManager();
	void replaceManager(ObjectManager* readManager);
	void setUpShaders();
	Shader* getShader();
	glm::vec4 getLightningVector();
	void setlightingVector(glm::vec4 readLighting);
};