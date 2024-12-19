#pragma once
#include <GL/glut.h>
#include <string>

class DisplayManager {
public:
	DisplayManager(int readWidth = 640, int readHeight = 480, bool readFullscreen = false, bool readDoubleBuffer = true, std::string readTitle = "Engine");
	void initializeWindow();
	int getWindowWidth();
	int GetWindowHeight();
	void setWindowWidth(int readWidth);
	void setWindowHeight(int readHeight);
	bool ifFullscreen();
	void setFullscreen(bool readFullscreen);
private:
	int windowWidth;
	int windowHeight;
	bool fullscreen;
	bool doubleBuffer;
	std::string programTitle;
};