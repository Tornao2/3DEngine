#include "Renderer.h"
#include "Point.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(ObjectManager* readManager, Color readClearColor, bool zBuffer, bool shouldOrthogonal) {
	instance = this;
	shader = nullptr;
	manager = readManager;
	clearColor = readClearColor;
	setZBuffer(zBuffer);
	orthogonalView = shouldOrthogonal;
}

void Renderer::setClearColor(Color readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, readClearColor.a);
}

void Renderer::setUpShaders() {
	shader = new Shader();
	manager->setShader(shader);
}

void Renderer::prepareView() {
	float aspectRatio = (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
	if (orthogonalView) 
		projectionMatrix = glm::ortho(-1.0f * aspectRatio, 1.0f * aspectRatio, -1.0f, 1.0f, 1.0f, 100.0f);
	else 
		projectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 3.0f, 100.0f);
	GLint projectionLoc = glGetUniformLocation(shader->getProgramId(), "projectionMatrix");
	glUniformMatrix4fv(projectionLoc, 1, GL_TRUE, glm::value_ptr(projectionMatrix));

}

void Renderer::renderProper() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	prepareView();
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

Color Renderer::getClearColor() {
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
}

ObjectManager* Renderer::getManager() {
	return manager;
}

void Renderer::replaceManager(ObjectManager* readManager) {
	manager->clearList();
	manager = readManager;
}

Shader* Renderer::getShader() {
	return shader;
}