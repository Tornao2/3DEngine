#include "MouseHandler.h"

MouseHandler* MouseHandler::instance = nullptr;


MouseHandler::MouseHandler() {
	instance = this;
	glutMouseFunc(buttonHandle);
}

void MouseHandler::buttonHandleProper(int button, int state, int x, int y) {
	if (state == GLUT_UP)
		buttonStates[button] = releasedButton;
	else
		buttonStates[button] = pressedButton;
}

void MouseHandler::buttonHandle(int button, int state, int x, int y) {
	instance->buttonHandleProper(button, state, x, y);
}

void MouseHandler::refresh() {
	for (int i = 0; i < 3; i++)
		if (ifButtonsRefresh[i])
			instance->buttonStates[i] = releasedButton;
}

void MouseHandler::setIfShouldRefresh(unsigned char button, bool should) {
	ifButtonsRefresh[button] = should;
}

bool MouseHandler::getIfShouldRefresh(unsigned char button) {
	return ifButtonsRefresh[button];
}

bool MouseHandler::checkIfPressed(unsigned char button) {
	if (buttonStates[button] == pressedButton)
		return true;
	return false;
}