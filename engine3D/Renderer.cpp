#include "Renderer.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(Color readClearColor, bool zBuffer, bool doubleBuffer) {
	instance = this;
	clearColor = readClearColor;
	enableDoubleBuffer = doubleBuffer;
	enableZBuffer = zBuffer;
}

void Renderer::setClearColor(Color readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, readClearColor .a);
}

void Renderer::renderProper() {
	//DEBUGGING, DELETE FROM RELEASE
	if (clearColor.r >= 1) 
		clearColor = { 0, 0, 0, 1 };
	setClearColor({clearColor.r + 0.001, clearColor.g + 0.001, clearColor.b + 0.001, 1});
	//DEBUGGING, DELETE FROM RELEASE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void Renderer::setDoubleBuffer(bool should) {
	enableDoubleBuffer = should;
}

bool Renderer::getZBuffer() {
	return enableZBuffer;
}

bool Renderer::getDoubleBuffer() {
	return enableDoubleBuffer;
}
