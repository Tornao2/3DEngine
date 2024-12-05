#pragma once
#include "Renderer.h"
#include "DisplayManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer&renderer, DisplayManager& displayManager, int delay);
	template<typename mouseFunc, typename keyboardFunc>
	void registerCallbacks(mouseFunc mouse, keyboardFunc keyboard) {
		glutDisplayFunc(Renderer::render);
		if (mouse)
			glutMouseFunc(mouse);
		if (keyboard)
			glutKeyboardFunc(keyboard);
		glutTimerFunc(1, timer, fpsCap);
	}
	void run();
	void finishProgram();
	int getFpsCap();
	void setFpsCap(int delay);
private:
	int fpsCap;
	void initializeLibrary(int* argc, char* argv[]);
	void static timer(int value);
	template<typename keyboardFunc> void toggleKeyboard(keyboardFunc keyboard) {
		if (keyboard)
			glutKeyboardFunc(keyboard);
		else if (!keyboard)
			glutKeyboardFunc(NULL);
	}
	template<typename mouseFunc> void toggleMouse(mouseFunc mouse) {
		if (mouse)
			glutMouseFunc(mouse);
		else if (!mouse)
			glutMouseFunc(NULL);
	}
};