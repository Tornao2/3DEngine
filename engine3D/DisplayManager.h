#pragma once
#include "GL/glut.h"

class DisplayManager {
public:
	DisplayManager(int width, int height, bool shouldFullscreen);
	void initializeWindow();
	int getWindowWidth();
	int GetWindowHeight();
	void setWindowWidth(int width);
	void setWindowHeight(int height);
	bool getFullscreen();
	void setFullscreen(bool shouldFullscreen);
private:
	int windowWidth;
	int windowHeight;
	bool fullscreen;
};