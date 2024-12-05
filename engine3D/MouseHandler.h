#pragma once
#include <GL/freeglut_std.h>

typedef enum buttonsStates {
	releasedButton,
	pressedButton
}buttonsStates;

typedef enum mouseButtons {
	leftButton = 0,
	scrollButton,
	rightButton
};

class MouseHandler {
private:
	static MouseHandler* instance;
	buttonsStates buttonStates[3] = { releasedButton };
	bool ifButtonsRefresh[3] = { true };
	void buttonHandleProper(int button, int state, int x, int y);
public:
	MouseHandler();
	void refresh();
	void setIfShouldRefresh(unsigned char button, bool should);
	bool getIfShouldRefresh(unsigned char button);
	void static buttonHandle(int button, int state, int x, int y);
	bool checkIfPressed(unsigned char button);
};