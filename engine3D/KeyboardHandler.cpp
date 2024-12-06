#include "KeyboardHandler.h"

KeyboardHandler* KeyboardHandler::instance = nullptr;

KeyboardHandler::KeyboardHandler() {
	instance = this;
	glutKeyboardFunc(KeyboardHandler::keyDown);
	glutKeyboardUpFunc(KeyboardHandler::keyUp);
	glutIgnoreKeyRepeat(GL_TRUE);
}

void KeyboardHandler::keyDownProper(unsigned char key, int x, int y) {
	if (keyStates[key] != removeLater) {
		keyStates[key] = pressing;
		ifKeyPressedThisFrame[key] = true;
	}
}

void KeyboardHandler::keyUpProper(unsigned char key, int x, int y) {
	if (ifKeyPressedThisFrame[key])
		keyStates[key] = removeLater;
	else
		keyStates[key] = notClicked;
}

void KeyboardHandler::keyDown(unsigned char key, int x, int y) {
	instance->keyDownProper(key, x, y);
}

void KeyboardHandler::keyUp(unsigned char key, int x, int y) {
	instance->keyUpProper(key, x, y);
}

void KeyboardHandler::refresh() {
	for (int i = 0; i < 256; i++) {
		if (ifKeyRefresh[i] || keyStates[i] == removeLater)
			keyStates[i] = notClicked;
		ifKeyPressedThisFrame[i] = false;
	}
}

void KeyboardHandler::setIfShouldRefresh(unsigned char key, bool should) {
	ifKeyRefresh[key] = should;
}

bool KeyboardHandler::getIfShouldRefresh(unsigned char key) {
	return ifKeyRefresh[key];
}

bool KeyboardHandler::checkIfPressed(unsigned char key) {
	if (keyStates[key] != notClicked)
		return true;
	return false;
}
