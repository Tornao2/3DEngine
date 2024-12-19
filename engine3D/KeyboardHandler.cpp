#include "KeyboardHandler.h"

KeyboardHandler* KeyboardHandler::instance = nullptr;

KeyboardHandler::KeyboardHandler() {
	instance = this;
	glutKeyboardFunc(KeyboardHandler::keyDown);
	glutKeyboardUpFunc(KeyboardHandler::keyUp);
	glutIgnoreKeyRepeat(GL_TRUE);
}

void KeyboardHandler::keyDownProper(unsigned char readKey, int readX, int readY) {
	if (keyStates[readKey] != removeInFuture) {
		keyStates[readKey] = pressing;
		ifKeyPressedThisFrame[readKey] = true;
	}
}

void KeyboardHandler::keyUpProper(unsigned char readKey, int readX, int readY) {
	if (ifKeyPressedThisFrame[readKey])
		keyStates[readKey] = removeInFuture;
	else
		keyStates[readKey] = notClicked;
}

void KeyboardHandler::keyDown(unsigned char readKey, int readX, int readY) {
	instance->keyDownProper(readKey, readX, readY);
}

void KeyboardHandler::keyUp(unsigned char readKey, int readX, int readY) {
	instance->keyUpProper(readKey, readX, readY);
}

void KeyboardHandler::refresh() {
	for (int i = 0; i < 256; i++) {
		if (ifKeyRefresh[i] || keyStates[i] == removeInFuture)
			keyStates[i] = notClicked;
		ifKeyPressedThisFrame[i] = false;
	}
}

void KeyboardHandler::setIfShouldRefresh(unsigned char readKey, bool readShould) {
	ifKeyRefresh[readKey] = readShould;
}

bool KeyboardHandler::getIfShouldRefresh(unsigned char readKey) {
	return ifKeyRefresh[readKey];
}

bool KeyboardHandler::checkIfPressed(unsigned char readKey) {
	if (keyStates[readKey] != notClicked)
		return true;
	return false;
}