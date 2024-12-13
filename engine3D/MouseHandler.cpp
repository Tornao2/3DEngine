#include "MouseHandler.h"

MouseHandler* MouseHandler::instance = nullptr;

MouseHandler::MouseHandler(Shader* shader) {
	instance = this;
	camera = CameraHandler(shader);
	glutMouseFunc(buttonHandle);
}

void MouseHandler::buttonHandleProper(int button, int state, int x, int y) {
	if (state == GLUT_DOWN) {
		buttonStates[button] = pressing;
		ifPressedOnThisFrame[button] = true;
	}
	else if (state == GLUT_UP)
		if (ifPressedOnThisFrame[button])
			buttonStates[button] = removeLater;
		else
			buttonStates[button] = notClicked;
}

void MouseHandler::buttonHandle(int button, int state, int x, int y) {
	instance->buttonHandleProper(button, state, x, y);
}

void MouseHandler::refresh() {
	for (int i = 0; i < 3; i++) {
		if (buttonStates[i] == removeLater || ifButtonsRefresh[i])
			buttonStates[i] = notClicked;
		ifPressedOnThisFrame[i] = false;
	}
}

void MouseHandler::setIfShouldRefresh(unsigned char button, bool should) {
	ifButtonsRefresh[button] = should;
}

bool MouseHandler::getIfShouldRefresh(unsigned char button) {
	return ifButtonsRefresh[button];
}

bool MouseHandler::checkIfPressed(unsigned char button) {
	if (buttonStates[button] != notClicked)
		return true;
	return false;
}

void MouseHandler::mouseCallback(int xpos, int ypos) {
	float xoffset = xpos - instance->camera.lastX;
	float yoffset = instance->camera.lastY - ypos;
	instance->camera.lastX = xpos;
	instance->camera.lastY = ypos;
	float sensitivity = 0.5f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;
	instance->camera.yaw -= xoffset;
	instance->camera.pitch -= yoffset;
	if (instance->camera.pitch > 89.0f) instance->camera.pitch = 89.0f;
	if (instance->camera.pitch < -89.0f) instance->camera.pitch = -89.0f;
	instance->camera.updateCamera();
}