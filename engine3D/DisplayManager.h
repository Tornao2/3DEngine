#pragma once
#include <GL/glut.h>
#include <string>

class DisplayManager {
public:
	DisplayManager(int width = 640, int height = 480, bool shouldFullscreen = false, bool shouldDoubleBuffer = true, std::string title = "Engine");
	void initializeWindow();
	int getWindowWidth();
	int GetWindowHeight();
	void setWindowWidth(int width);
	void setWindowHeight(int height);
	bool ifFullscreen();
	void setFullscreen(bool shouldFullscreen);
private:
	int windowWidth;
	int windowHeight;
	bool fullscreen;
	bool doubleBuffer;
	std::string programTitle;
};