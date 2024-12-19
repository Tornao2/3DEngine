#include "MouseHandler.h"

MouseHandler* MouseHandler::instance = nullptr;

MouseHandler::MouseHandler() {
	instance = this;
	glutMouseFunc(buttonHandle);
}

void MouseHandler::buttonHandleProper(int readButton, int readState, int readX, int readY) {
	if (readState == GLUT_DOWN) {
		buttonStates[readButton] = pressing;
		ifPressedOnThisFrame[readButton] = true;
	}
	else if (readState == GLUT_UP)
		if (ifPressedOnThisFrame[readButton])
			buttonStates[readButton] = removeInFuture;
		else
			buttonStates[readButton] = notClicked;
}

void MouseHandler::buttonHandle(int readButton, int readState, int readX, int readY) {
	instance->buttonHandleProper(readButton, readState, readX, readY);
}

void MouseHandler::refresh() {
	for (int i = 0; i < 3; i++) {
		if (buttonStates[i] == removeInFuture || ifButtonsRefresh[i])
			buttonStates[i] = notClicked;
		ifPressedOnThisFrame[i] = false;
	}
}

void MouseHandler::setIfShouldRefresh(unsigned char readButton, bool readShould) {
	ifButtonsRefresh[readButton] = readShould;
}

bool MouseHandler::getIfShouldRefresh(unsigned char readButton) {
	return ifButtonsRefresh[readButton];
}

bool MouseHandler::checkIfPressed(unsigned char readButton) {
	if (buttonStates[readButton] != notClicked)
		return true;
	return false;
}

void MouseHandler::mouseCallback(int readX, int readY) {
	if (instance->camera != nullptr) {
		float xoffset = readX - instance->camera->getLastX();
		float yoffset = instance->camera->getLastY() - readY;
		instance->camera->setLastX((float)readX);
		instance->camera->setLastY((float)readY);
		float sensitivity = 0.5f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		instance->camera->setYaw(instance->camera->getYaw() - xoffset);
		instance->camera->setPitch(instance->camera->getPitch() - yoffset);
		if (instance->camera->getPitch() > 89.0f) instance->camera->setPitch(89.0f);
		if (instance->camera->getPitch() < -89.0f) instance->camera->setPitch(-89.0f);
		instance->camera->updateCamera();
	}
}

Observer* MouseHandler::getCamera() {
	return camera;
}

void MouseHandler::setCamera(Observer* readCamera) {
	camera = readCamera;
}