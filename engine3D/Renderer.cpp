#include "Renderer.h"
#include "Point.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(Color readClearColor, bool zBuffer, bool shouldOrthogonal) {
	instance = this;
	clearColor = readClearColor;
	setZBuffer(zBuffer);
	orthogonalView = shouldOrthogonal;
}

void Renderer::setClearColor(Color readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, readClearColor.a);
}

void Renderer::prepareView() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (orthogonalView)
		glOrtho(-GLUT_WINDOW_WIDTH / 2, GLUT_WINDOW_WIDTH / 2, -GLUT_WINDOW_HEIGHT / 2, GLUT_WINDOW_HEIGHT / 2, -5.0f, 5.0f);
	else
		gluPerspective(45.0, GLUT_WINDOW_WIDTH / GLUT_WINDOW_HEIGHT, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Renderer::renderProper() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	prepareView();
	//Draw Figures here
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
