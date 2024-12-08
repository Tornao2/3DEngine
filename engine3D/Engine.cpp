#include "Engine.h"

std::function<void()> Engine::mouseFunc = nullptr;
std::function<void()> Engine::keyboardFunc = nullptr;
Engine* Engine::instance = nullptr;

void APIENTRY MessageCallback(GLenum source, GLenum type, GLuint id,
	GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam) {
	std::cerr << "GL CALLBACK: " << (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "")
		<< " type = 0x" << type
		<< ", severity = 0x" << severity
		<< ", message = " << message << std::endl;
}
Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay) {
	instance = this;
	fpsCap = delay;
	initializeLibrary(argc, argv);
	displayManager.initializeWindow();
	glewInit();
	renderer.setClearColor(renderer.getClearColor());
	renderer.setZBuffer(renderer.getZBuffer());
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);
}

void Engine::registerCallbacks(){
	glutDisplayFunc(Renderer::render);
	glutTimerFunc(1, timer, fpsCap);
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
	glutTimerFunc(1000 / instance->fpsCap, timer, instance->fpsCap);
}

void Engine::setKeyboardFunc(std::function<void(void)> function) {
	Engine::keyboardFunc = function;
}

void Engine::setMouseFunc(std::function<void(void)> function) {
	Engine::mouseFunc = function;
}
