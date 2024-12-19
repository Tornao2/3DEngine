#include "Renderer.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(ObjectManager* readManager, glm::vec3 readClearColor, bool readZBuffer, bool shouldOrthogonal) {
	instance = this;
	shader = nullptr;
	manager = readManager;
	clearColor = readClearColor;
	setZBuffer(readZBuffer);
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
	setLightingPos({0, 1, 0});
	setAmbientStrength(0.1f);
	setScatterStrength(24);
	setBoostColor(1.1f);
	setSpecularStrength(0.4f);
	setClearColor({ 1.0f, 0.95f, 0.95f });
	setWarnCutOff(25);
	setWarnIntensity(20);
}

void Renderer::renderProper() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->use();
	manager->drawAll();
	if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) glutSwapBuffers();
	else glFlush();
}

void Renderer::render() {
	instance->renderProper();
}

glm::vec3 Renderer::getClearColor() {
	return clearColor;
}

void Renderer::setZBuffer(bool readShould) {
	enableZBuffer = readShould;
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

void Renderer::setLightingPos(glm::vec3 readLighting) {
	lightPos = readLighting;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "lightPos");
	glUniform3fv(lightingDir, 1, glm::value_ptr(readLighting));
}

glm::vec3 Renderer::getLightingPos() {
	return lightPos;
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

void Renderer::toggleIfFlatShading() {
	shader->switchShading();
	setClearColor(getClearColor());
	setOrthogonal(getOrthogonal());
	setLightingPos(getLightingPos());
	setAmbientStrength(getAmbientStrength());
	setSpecularStrength(getSpecularStrength());
	setScatterStrength(getScatterStrength());
	setBoostColor(getBoostColor());
	setWarnModel(getWarnModel());
	setWarnCutOff(getWarnCutOff());
	setWarnIntensity(getWarnIntensity());
	if (manager->getCamera() != nullptr)
		manager->getCamera()->updateCamera();
}

bool Renderer::getWarnModel() {
	return ifWarnModel;
}

void Renderer::setWarnModel(bool readIfWarn) {
	ifWarnModel = readIfWarn;
	glUseProgram(shader->getProgramId());
	GLint warnModelInt = glGetUniformLocation(shader->getProgramId(), "ifWarnModel");
	glUniform1i(warnModelInt, ifWarnModel);
}

void Renderer::setWarnCutOff(float readCutOff) {
	angleWarnCutOff = readCutOff;
	glUseProgram(shader->getProgramId());
	GLint warnAngle = glGetUniformLocation(shader->getProgramId(), "cutOff");
	glUniform1f(warnAngle, glm::cos(glm::radians(angleWarnCutOff)));
}

float Renderer::getWarnCutOff() {
	return angleWarnCutOff;
}

void Renderer::setWarnIntensity(float readIntensity) {
	intensityWarn = readIntensity;
	glUseProgram(shader->getProgramId());
	GLint warnIntensity = glGetUniformLocation(shader->getProgramId(), "intensity");
	glUniform1f(warnIntensity, intensityWarn);
}

float Renderer::getWarnIntensity() {
	return intensityWarn;
}