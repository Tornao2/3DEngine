#pragma once
#include <GL/freeglut_std.h>

typedef enum KeyStates {
	notClicked,
	removeInFuture,
	pressing
}KeyStates;

class KeyboardHandler {
private:
	static KeyboardHandler* instance;
	KeyStates keyStates[256] = { notClicked };
	bool ifKeyRefresh[256] = { false };
	bool ifKeyPressedThisFrame[256];
	void keyDownProper(unsigned char readKey, int readX, int readY);
	void keyUpProper(unsigned char readKey, int readX, int readY);
public:
	KeyboardHandler();
	void refresh();
	void setIfShouldRefresh(unsigned char readKey, bool readShould);
	bool getIfShouldRefresh(unsigned char readKey);
	void static keyDown(unsigned char readKey, int readX, int readY);
	void static keyUp(unsigned char readKey, int readX, int readY);
	bool checkIfPressed(unsigned char readKey);
};