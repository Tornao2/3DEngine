#include "KeyboardHandler.h"

KeyboardHandler* KeyboardHandler::instance = nullptr;

KeyboardHandler::KeyboardHandler() {
	instance = this;
	glutKeyboardFunc(KeyboardHandler::keyDown);
	glutKeyboardUpFunc(KeyboardHandler::keyUp);
}

void KeyboardHandler::keyDownProper(unsigned char key, int x, int y) {
	keyStates[key] = pressed;
}

void KeyboardHandler::keyUpProper(unsigned char key, int x, int y) {
	keyStates[key] = released; 
}

void KeyboardHandler::keyDown(unsigned char key, int x, int y) {
	instance->keyDownProper(key, x, y);
}

void KeyboardHandler::keyUp(unsigned char key, int x, int y) {
	instance->keyUpProper(key, x, y);
}

void KeyboardHandler::refresh() {
	for (int i = 0; i < 256; i++)
		if (ifKeyRefresh[i])
			instance->keyStates[i] = released;
}

void KeyboardHandler::setIfShouldRefresh(unsigned char key, bool should) {
	ifKeyRefresh[key] = should;
}

bool KeyboardHandler::getIfShouldRefresh(unsigned char key) {
	return ifKeyRefresh[key];
}

bool KeyboardHandler::checkIfPressed(unsigned char key) {
	if (keyStates[key] == pressed)
		return true;
	return false;
}