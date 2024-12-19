#include "DisplayManager.h"

DisplayManager::DisplayManager(int readWidth, int readHeight, bool readFullscreen, bool readDoubleBuffer, std::string readTitle) {
	windowHeight = readHeight;
	windowWidth = readWidth;
	fullscreen = readFullscreen;
	doubleBuffer = readDoubleBuffer;
	programTitle = readTitle;
}

void DisplayManager::initializeWindow() {
	if (doubleBuffer)
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	else
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
	glutCreateWindow(programTitle.c_str());
	setFullscreen(fullscreen); 
}

int DisplayManager::getWindowWidth() {
	return windowWidth;
}

int DisplayManager::GetWindowHeight() {
	return windowHeight;
}

void DisplayManager::setWindowWidth(int readWidth) {
	windowWidth = readWidth;
	if (readWidth > 1) {
		glutReshapeWindow(windowWidth, windowHeight);
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
	}
}

void DisplayManager::setWindowHeight(int readHeight) {
	windowHeight = readHeight;
	if (readHeight > 1) {
		glutReshapeWindow(windowWidth, windowHeight);
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
	}
}

bool DisplayManager::ifFullscreen() {
	return fullscreen;
}

void DisplayManager::setFullscreen(bool readFullscreen) {
	if (readFullscreen) {
		glutFullScreen();
		fullscreen = true;
	}
	else {
		glutReshapeWindow(windowWidth, windowHeight);
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
		fullscreen = false;
	}
}