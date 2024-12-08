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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	if (orthogonalView)
		glOrtho(-glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_WIDTH) / 2, -glutGet(GLUT_WINDOW_HEIGHT) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2, 1.0f, 100.0f);
	else {
		float fov = 2.0f * atan((glutGet(GLUT_WINDOW_HEIGHT) / 2.0f)) * (180.0f / 3.14159f);
		gluPerspective(fov, (float)glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT), 1.0f, 100.0f);
	}
	glMatrixMode(GL_MODELVIEW);
}

void Renderer::setupCamera() {
	glLoadIdentity();  
	gluLookAt(0.0f, 0.0f, 5.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
}

void Renderer::renderProper() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setupCamera();
	prepareView();
	shader->use();
	glBindVertexArray(shader->getVAO());
	manager->drawAll();
	glBindVertexArray(0);
	if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) glutSwapBuffers();
	glFlush();
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
