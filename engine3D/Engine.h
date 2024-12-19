#pragma once
#include "MouseHandler.h"
#include "Renderer.h"
#include "DisplayManager.h"
#include <functional>
#include "BitmapHandler.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer& readRenderer, DisplayManager& readDisplayManager, int readDelay = 300);
	int getFpsCap();
	void setFpsCap(int readDelay);
	void toggleKeyboard(bool readShould, std::function<void(void)> readFunction);
	void toggleMouse(bool readShould, std::function<void(void)> readFunction);
private:
	int fpsCap;
	static Engine* instance;
	void initializeLibrary(int* argc, char* argv[], DisplayManager& readDisplayManager);
	void static timer(int readDummy);
	static std::function<void(void)> mouseFunc;
	static std::function<void(void)> keyboardFunc;
};