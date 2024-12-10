#pragma once
#include "MouseHandler.h"
#include "Renderer.h"
#include "DisplayManager.h"
#include <functional>
#include "Point.h"
#include "Line.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay = 60);
	void registerCallbacks();
	void run();
	int getFpsCap();
	void setFpsCap(int delay);
	void toggleKeyboard(bool should, std::function<void(void)> function);
	void toggleMouse(bool should, std::function<void(void)> function);
private:
	int fpsCap;
	static Engine* instance;
	void initializeLibrary(int* argc, char* argv[], DisplayManager& displayManager);
	void static timer(int value);
	static std::function<void(void)> mouseFunc;
	static std::function<void(void)> keyboardFunc;
};