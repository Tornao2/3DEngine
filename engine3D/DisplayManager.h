#pragma once
#include "GL/glut.h"
#include "string"

class DisplayManager {
public:
	DisplayManager(float width, float height, bool shouldFullscreen, bool shouldDoubleBuffer, std::string title);
	void initializeWindow();
	float getWindowWidth();
	float GetWindowHeight();
	void setWindowWidth(float width);
	void setWindowHeight(float height);
	bool ifFullscreen();
	void setFullscreen(bool shouldFullscreen);
private:
	float windowWidth;
	float windowHeight;
	bool fullscreen;
	bool doubleBuffer;
	std::string programTitle;
};