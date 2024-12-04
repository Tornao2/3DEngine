#include "DisplayManager.h"

DisplayManager::DisplayManager(int width, int height, bool shouldFullscreen) {
	windowHeight = height;
	windowWidth = width;
	fullscreen = shouldFullscreen;
}

void DisplayManager::initializeWindow() {
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight)/2);
	glutCreateWindow("3DEngine");
	setFullscreen(fullscreen);
}

int DisplayManager::getWindowWidth() {
	return windowWidth;
}

int DisplayManager::GetWindowHeight() {
	return windowHeight;
}

void DisplayManager::setWindowWidth(int width) {
	windowWidth = width;
}

void DisplayManager::setWindowHeight(int height) {
	windowHeight = height;
}

bool DisplayManager::getFullscreen() {
	return fullscreen;
}

void DisplayManager::setFullscreen(bool shouldFullscreen) {
	if (shouldFullscreen) {
		glutFullScreen();
		fullscreen = true;
	} else {
		glutReshapeWindow(windowWidth, windowHeight);   
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
		fullscreen = false;
	}
}