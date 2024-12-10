#pragma once
#include "ShaderHandler.h"
#include "Gl/glut.h"
#include "Color.h"
#include "ObjectManager.h"
#include <glm/glm.hpp>
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
public:
	Renderer(ObjectManager* readManager, Color readClearColor = {0, 0, 0, 0}, bool zBuffer = true, bool shouldOrthogonal = true);
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
};