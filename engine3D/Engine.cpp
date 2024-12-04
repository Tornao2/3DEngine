#include "Engine.h"

Engine::Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager) {
	initializeLibrary(argc, argv);
	displayManager.initializeWindow();
	registerCallbacks(renderer);
	glutMainLoop();
}

void Engine::finishProgram() {
	glutDestroyWindow(glutGetWindow());
}

void Engine::initializeLibrary(int* argc, char* argv[]) {
	glutInit(argc, argv);
}

void Engine::registerCallbacks(Renderer& renderer) {
	glutDisplayFunc(renderer.render);
	glutReshapeFunc(renderer.resize);
	glutIdleFunc(renderer.render);
}
