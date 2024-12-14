#pragma once
#include "Observer.h"
#include "KeyboardHandler.h"

typedef enum mouseButtons {
	leftButton = 0,
	scrollButton,
	rightButton
}mouseButtons;

class MouseHandler {
private:
	Observer* camera = nullptr;
	static MouseHandler* instance;
	KeyStates buttonStates[3] = { notClicked };
	bool ifButtonsRefresh[3] = { true };
	bool ifPressedOnThisFrame[3] = { false };
	void buttonHandleProper(int button, int state, int x, int y);
public:
	MouseHandler(Shader* shader);
	void refresh();
	void setIfShouldRefresh(unsigned char button, bool should);
	bool getIfShouldRefresh(unsigned char button);
	void static buttonHandle(int button, int state, int x, int y);
	bool checkIfPressed(unsigned char button);
	static void mouseCallback(int xpos, int ypos);
	Observer* getCamera();
	void setCamera(Observer* readCamera);
};