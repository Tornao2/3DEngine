#include "Engine.h"

std::function<void()> Engine::mouseFunc = nullptr;
std::function<void()> Engine::keyboardFunc = nullptr;

Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay) {
	fpsCap = delay;
	initializeLibrary(argc, argv);
	displayManager.initializeWindow();
	renderer.setClearColor(renderer.getClearColor());
	renderer.setZBuffer(renderer.getZBuffer());
}
void Engine::registerCallbacks(){
	glutDisplayFunc(Renderer::render);
	glutTimerFunc(1, timer, fpsCap);
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

int Engine::getFpsCap() {
	return fpsCap;
}

void Engine::setFpsCap(int delay) {
	glutTimerFunc(fpsCap, timer, delay);
	fpsCap = delay;
}

void Engine::toggleKeyboard(bool should, std::function<void(void)> function) {
	if (should) {
		glutKeyboardFunc(KeyboardHandler::keyDown);
		glutKeyboardUpFunc(KeyboardHandler::keyUp);
	}
	else {
		glutKeyboardFunc(NULL);
		glutKeyboardUpFunc(NULL);
	}
	keyboardFunc = function;
}

void Engine::toggleMouse(bool should, std::function<void(void)> function){
	if (should)
		glutMouseFunc(MouseHandler::buttonHandle);
	else 
		glutMouseFunc(NULL);
	mouseFunc = function;
}

void Engine::timer(int value) {
	Engine::mouseFunc();
	Engine::keyboardFunc();
	glutPostRedisplay();
	glutTimerFunc(1000 / value, timer, value);
}

void Engine::setKeyboardFunc(std::function<void(void)> function) {
	Engine::keyboardFunc = function;
}

void Engine::setMouseFunc(std::function<void(void)> function) {
	Engine::mouseFunc = function;
}