#pragma once
#include "MouseHandler.h"
#include "Renderer.h"
#include "DisplayManager.h"
#include <functional>
#include "BitmapHandler.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer& renderer, DisplayManager& displayManager, int delay = 300);
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