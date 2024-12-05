#pragma once
#include "Renderer.h"
#include "DisplayManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include "GL/freeglut_std.h"
#include <functional>

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer&renderer, DisplayManager& displayManager, int delay);
	void registerCallbacks();
	void run();
	void finishProgram();
	int getFpsCap();
	void setFpsCap(int delay);
	void toggleKeyboard(bool should, std::function<void(void)> function);
	void toggleMouse(bool should, std::function<void(void)> function);
	void setKeyboardFunc(std::function<void(void)> function);
	void setMouseFunc(std::function<void(void)> function);
private:
	int fpsCap;
	void initializeLibrary(int* argc, char* argv[]);
	void static timer(int value);
	static std::function<void(void)> mouseFunc;
	static std::function<void(void)> keyboardFunc;
};