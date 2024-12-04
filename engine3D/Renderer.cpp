#include "Renderer.h"

Renderer* Renderer::instance = nullptr;

Renderer::Renderer(Color readClearColor, bool zBuffer, bool shouldOrthogonal) {
	instance = this;
	clearColor = readClearColor;
	enableZBuffer = zBuffer;
	orthogonalView = shouldOrthogonal;
}

void Renderer::setClearColor(Color readClearColor) {
	clearColor = readClearColor;
	glClearColor(readClearColor.r, readClearColor.g, readClearColor.b, readClearColor .a);
}

void Renderer::prepareView() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (orthogonalView)
		glOrtho(-GLUT_WINDOW_WIDTH / 2, GLUT_WINDOW_WIDTH / 2, -GLUT_WINDOW_HEIGHT / 2, GLUT_WINDOW_HEIGHT / 2, -1.0, 1.0);
	else
		gluPerspective(45.0, GLUT_WINDOW_WIDTH / GLUT_WINDOW_HEIGHT, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
//DEBUGGING, DELETE FROM RELEASE
void Renderer::fadingBackground() {
	if (clearColor.r >= 1 || clearColor.g >= 1 || clearColor.b >= 1 || clearColor.r <= 0 || clearColor.g <= 0 || clearColor.b <= 0)
		clearColor = { 0.5, 0.5, 0.5, 1 };
	float randr = (float)(rand()%10-5)/1000;
	float randg = (float)(rand() % 10-5) / 1000;
	float randb = (float)(rand() % 10-5) / 1000;
	setClearColor({ clearColor.r + randr, clearColor.g + randg, clearColor.b + randb, 1 });
}
//DEBUGGING, DELETE FROM RELEASE
void Renderer::renderProper() {
	prepareView();
	//DEBUGGING, DELETE FROM RELEASE
	fadingBackground();
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

bool Renderer::getZBuffer() {
	return enableZBuffer;
}

bool Renderer::ifOrthogonal() {
	return orthogonalView;
}

void Renderer::setOrthogonal(bool shouldOrthogonal) {
	orthogonalView = shouldOrthogonal;
}