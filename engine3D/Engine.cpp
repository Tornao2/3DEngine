#include "Engine.h"

Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay, bool readMouse, bool readKeyboard) {
	fpsCap = delay;
	initializeLibrary(argc, argv);
	displayManager.initializeWindow();
	renderer.setClearColor(renderer.getClearColor());
	renderer.setZBuffer(renderer.getZBuffer());
	registerCallbacks(readMouse, readKeyboard);
	glutMainLoop();
}

void Engine::finishProgram() {
	glutDestroyWindow(glutGetWindow());
}

void Engine::initializeLibrary(int* argc, char* argv[]) {
	glutInit(argc, argv);
}

void Engine::registerCallbacks(bool readMouse, bool readKeyboard) {
	glutDisplayFunc(Renderer::render);
	if (readMouse) {
		mouse = true;
		glutMouseFunc(MouseHandler::handleMouse);
	}
	if (readKeyboard) {
		keyboard = true;
		glutKeyboardFunc(KeyboardHandler::handleKeyboard);
	}
	glutTimerFunc(1, timer, fpsCap);
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

void Engine::toggleKeyboard(bool toggle) {
	if (toggle && !keyboard) {
		glutKeyboardFunc(KeyboardHandler::handleKeyboard);
		keyboard = true;
	}
	else if (!toggle && keyboard) {
		glutKeyboardFunc(NULL);
		keyboard = false;
	}
}

bool Engine::getKeyboard() {
	return keyboard;
}

void Engine::toggleMouse(bool toggle) {
	if (toggle && !mouse) {
		glutMouseFunc(MouseHandler::handleMouse);
		mouse = true;
	}
	else if (!toggle && mouse) {
		glutMouseFunc(NULL);
		mouse = false;
	}
}

bool Engine::getMouse() {
	return mouse;
}