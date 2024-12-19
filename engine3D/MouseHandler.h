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
	void buttonHandleProper(int readButton, int readState, int readX, int readY);
public:
	MouseHandler();
	void refresh();
	void setIfShouldRefresh(unsigned char readButton, bool readShould);
	bool getIfShouldRefresh(unsigned char readButton);
	void static buttonHandle(int readButton, int readState, int readX, int readY);
	bool checkIfPressed(unsigned char readButton);
	static void mouseCallback(int readX, int readY);
	Observer* getCamera();
	void setCamera(Observer* readCamera);
};