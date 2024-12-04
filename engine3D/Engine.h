#pragma once
#include "Renderer.h"
#include "DisplayManager.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer&renderer, DisplayManager& displayManager, int delay, bool readMouse, bool readKeyboard);
	void finishProgram();
	int getFpsCap();
	void setFpsCap(int delay);
private:
	bool keyboard;
	bool mouse;
	int fpsCap;
	void initializeLibrary(int* argc, char* argv[]);
	void registerCallbacks(bool readMouse, bool readKeyboard);
	void static timer(int value);
	void toggleKeyboard(bool toggle);
	bool getKeyboard();
	void toggleMouse(bool toggle);
	bool getMouse();
};