#include "Renderer.h"
#include "Point.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(ObjectManager* readManager, glm::vec4 readClearColor, glm::vec4 lightingVector, bool zBuffer, bool shouldOrthogonal) {
	instance = this;
	shader = nullptr;
	manager = readManager;
	clearColor = readClearColor;
	setZBuffer(zBuffer);
	orthogonalView = shouldOrthogonal;
	lightDir = lightingVector;
}

void Renderer::setClearColor(glm::vec4 readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, readClearColor.a);
	glUseProgram(shader->getProgramId());
	GLint ambientDir = glGetUniformLocation(shader->getProgramId(), "ambientDir");
	glUniform4fv(ambientDir, 1, glm::value_ptr(clearColor));
}

void Renderer::setUpShaders() {
	shader = new Shader();
	manager->setShader(shader);
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "lightDir");
	glUniform4fv(lightingDir, 1, glm::value_ptr(lightDir));
	float aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
	if (orthogonalView)
		projectionMatrix = glm::ortho(-1.0f * aspectRatio, 1.0f * aspectRatio, -1.0f, 1.0f, 1.0f, 100.0f);
	else
		projectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
	GLint projectionLoc = glGetUniformLocation(shader->getProgramId(), "projectionMatrix");
	glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, glm::value_ptr(projectionMatrix));
}
#include <chrono>
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

glm::vec4 Renderer::getClearColor() {
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
		projectionMatrix = glm::perspective(glm::radians(50.0f), aspectRatio, 2.0f, 100.0f);
	
	GLint projectionLoc = glGetUniformLocation(shader->getProgramId(), "projectionMatrix");
	glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, glm::value_ptr(projectionMatrix));
}

ObjectManager* Renderer::getManager() {
	return manager;
}

void Renderer::replaceManager(ObjectManager* readManager) {
	manager->clearDirectListList();
	manager->clearIndicedList();
	manager = readManager;
}

Shader* Renderer::getShader() {
	return shader;
}

glm::vec4 Renderer::getLightningVector() {
	return lightDir;
}

void Renderer::setlightingVector(glm::vec4 readLighting) {
	lightDir = readLighting;
	glUseProgram(shader->getProgramId());
	GLint lightingDir = glGetUniformLocation(shader->getProgramId(), "lightDir");
	glUniform4fv(lightingDir, 1, glm::value_ptr(lightDir));
}