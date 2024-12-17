#include "Renderer.h"
#include "Point.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(ObjectManager* readManager, glm::vec3 readClearColor, bool zBuffer, bool shouldOrthogonal) {
	instance = this;
	shader = nullptr;
	manager = readManager;
	clearColor = readClearColor;
	setZBuffer(zBuffer);
	orthogonalView = shouldOrthogonal;
}

void Renderer::setClearColor(glm::vec3 readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, 1.0f);
	glUseProgram(shader->getProgramId());
	GLint lightColor = glGetUniformLocation(shader->getProgramId(), "lightColor");
	glUniform3fv(lightColor, 1, glm::value_ptr(clearColor));
}

void Renderer::setUpShaders() {
	shader = new Shader();
	manager->setShader(shader);
	setOrthogonal(orthogonalView);
	setlightingPos({6, 30, 20});
	setAmbientStrength(0.1);
	setScatterStrength(24);
	setBoostColor(1.1);
	setSpecularStrength(0.4);
	setClearColor({ 1, 0.95, 0.95 });
}

void Renderer::renderProper() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->use();
	glBindVertexArray(shader->getVAO());
	manager->drawAll();
	glBindVertexArray(0);
	if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) glutSwapBuffers();
	else glFlush();
}

void Renderer::render() {
	instance->renderProper();
}

glm::vec3 Renderer::getClearColor() {
	return clearColor;
}

void Renderer::setZBuffer(bool should) {
	enableZBuffer = should;
	if (enableZBuffer)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);
}

bool Renderer::getZBuffer() {
	return enableZBuffer;
}

bool Renderer::getOrthogonal() {
	return orthogonalView;
}

void Renderer::setOrthogonal(bool shouldOrthogonal) {
	orthogonalView = shouldOrthogonal;
	glUseProgram(shader->getProgramId());
	float aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
	if (orthogonalView)
		projectionMatrix = glm::ortho(-1.0f * aspectRatio, 1.0f * aspectRatio, -1.0f, 1.0f, 1.0f, 100.0f);
	else
		projectionMatrix = glm::perspective(glm::radians(60.0f), aspectRatio, 1.0f, 100.0f);
	GLint projectionLoc = glGetUniformLocation(shader->getProgramId(), "projectionMatrix");
	glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, glm::value_ptr(projectionMatrix));
}

ObjectManager* Renderer::getManager() {
	return manager;
}

void Renderer::replaceManager(ObjectManager* readManager) {
	manager->clearDirectList();
	manager->clearIndicedList();
	manager = readManager;
}

Shader* Renderer::getShader() {
	return shader;
}

void Renderer::setlightingPos(glm::vec3 readLighting) {
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "lightPos");
	glUniform3fv(lightingDir, 1, glm::value_ptr(readLighting));
}

void Renderer::setAmbientStrength(float readStrength) {
	ambientStrength = readStrength;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "ambientStrength");
	glUniform1f(lightingDir, ambientStrength);
}

float Renderer::getAmbientStrength() {
	return ambientStrength;
}

void Renderer::setSpecularStrength(float readStrength) {
	specularStrength = readStrength;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "specularStrength");
	glUniform1f(lightingDir, specularStrength);
}

float Renderer::getSpecularStrength() {
	return specularStrength;
}

void Renderer::setScatterStrength(int readStrength) {
	scatterStrength = readStrength;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "scatterStrength");
	glUniform1i(lightingDir, scatterStrength);
}

int Renderer::getScatterStrength() {
	return scatterStrength;
}

void Renderer::setBoostColor(float readBoost) {
	boostColor = readBoost;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "boostColor");
	glUniform1f(lightingDir, boostColor);
}

float Renderer::getBoostColor() {
	return boostColor;
}