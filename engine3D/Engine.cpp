#include "Engine.h"

Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay) {
	fpsCap = delay;
	initializeLibrary(argc, argv);
	displayManager.initializeWindow();
	renderer.setClearColor(renderer.getClearColor());
	renderer.setZBuffer(renderer.getZBuffer());
}

void Engine::finishProgram() {
	glutDestroyWindow(glutGetWindow());
}

void Engine::initializeLibrary(int* argc, char* argv[]) {
	glutInit(argc, argv);
}

void Engine::run() {
	glutMainLoop();
}

void Engine::timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(1000/value, timer, value);
}

int Engine::getFpsCap() {
	return fpsCap;
}

void Engine::setFpsCap(int delay) {
	glutTimerFunc(fpsCap, timer, delay);
	fpsCap = delay;
}
