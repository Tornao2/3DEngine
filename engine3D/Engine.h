#pragma once
#include "Renderer.h"
#include "DisplayManager.h"

class Engine {
public:
	Engine(int* argc, char* argv[], Renderer&renderer, DisplayManager& displayManager);
	void finishProgram();
private:
	void initializeLibrary(int* argc, char* argv[]);
	void registerCallbacks(Renderer& renderer);
};