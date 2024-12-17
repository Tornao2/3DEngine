#include "Engine.h"

std::function<void()> Engine::mouseFunc = nullptr;
std::function<void()> Engine::keyboardFunc = nullptr;
Engine* Engine::instance = nullptr;

Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay) {
	instance = this;
	fpsCap = delay;
	initializeLibrary(argc, argv, displayManager);
	renderer.setZBuffer(renderer.getZBuffer());
	glutDisplayFunc(Renderer::render);
	glutTimerFunc(1, timer, fpsCap);
	renderer.setUpShaders();
	renderer.setClearColor(renderer.getClearColor());
}

void Engine::initializeLibrary(int* argc, char* argv[], DisplayManager& displayManager) {
	glutInit(argc, argv);
	displayManager.initializeWindow();
	GLenum glewInitResult = glewInit();
	if (glewInitResult != GLEW_OK) {
		std::cerr << "GLEW initialization failed: " << glewGetErrorString(glewInitResult) << std::endl;
		exit(-1);
	}
}

int Engine::getFpsCap() {
	return fpsCap;
}

void Engine::setFpsCap(int delay) {
	if (delay > 0)
		this->fpsCap = delay;
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

void Engine::toggleMouse(bool should, std::function<void(void)> function) {
	if (should) {
		glutMouseFunc(MouseHandler::buttonHandle);
		glutPassiveMotionFunc(MouseHandler::mouseCallback);
	}
	else {
		glutMouseFunc(NULL);
		glutPassiveMotionFunc(NULL);
	}
	mouseFunc = function;
}

void Engine::timer(int value) {
	glutTimerFunc(1000 / instance->fpsCap, timer, instance->fpsCap);
	glutPostRedisplay();
	if (Player::getInstance()) Player::move();
	Engine::mouseFunc();
	Engine::keyboardFunc();
}
