#include "Engine.h"

std::function<void()> Engine::mouseFunc = nullptr;
std::function<void()> Engine::keyboardFunc = nullptr;
Engine* Engine::instance = nullptr;

Engine::Engine(int* argc, char* argv[], Renderer& readRenderer, DisplayManager& readDisplayManager, int readDelay) {
	instance = this;
	fpsCap = readDelay;
	initializeLibrary(argc, argv, readDisplayManager);
	readRenderer.setZBuffer(readRenderer.getZBuffer());
	glutDisplayFunc(Renderer::render);
	glutTimerFunc(1, timer, fpsCap);
	readRenderer.setUpShaders();
	readRenderer.setClearColor(readRenderer.getClearColor());
}

void Engine::initializeLibrary(int* argc, char* argv[], DisplayManager& readDisplayManager) {
	glutInit(argc, argv);
	readDisplayManager.initializeWindow();
	GLenum glewInitResult = glewInit();
	if (glewInitResult != GLEW_OK) {
		std::cerr << "GLEW initialization failed: " << glewGetErrorString(glewInitResult) << std::endl;
		exit(-1);
	}
}

int Engine::getFpsCap() {
	return fpsCap;
}

void Engine::setFpsCap(int readDelay) {
	if (readDelay > 0)
		this->fpsCap = readDelay;
}

void Engine::toggleKeyboard(bool readShould, std::function<void(void)> readFunction) {
	if (readShould) {
		glutKeyboardFunc(KeyboardHandler::keyDown);
		glutKeyboardUpFunc(KeyboardHandler::keyUp);
	}
	else {
		glutKeyboardFunc(NULL);
		glutKeyboardUpFunc(NULL);
	}
	keyboardFunc = readFunction;
}

void Engine::toggleMouse(bool readShould, std::function<void(void)> readFunction) {
	if (readShould) {
		glutMouseFunc(MouseHandler::buttonHandle);
		glutPassiveMotionFunc(MouseHandler::mouseCallback);
	}
	else {
		glutMouseFunc(NULL);
		glutPassiveMotionFunc(NULL);
	}
	mouseFunc = readFunction;
}

void Engine::timer(int readDummy) {
	glutTimerFunc(1000 / instance->fpsCap, timer, instance->fpsCap);
	glutPostRedisplay();
	if (Player::getInstance()) Player::move();
	Engine::mouseFunc();
	Engine::keyboardFunc();
}
