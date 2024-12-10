#pragma once
#include <GL/freeglut_std.h>

typedef enum KeyStates {
	notClicked,
	removeLater,
	pressing
}KeyStates;

class KeyboardHandler {
private:
	static KeyboardHandler* instance;
	KeyStates keyStates[256] = { notClicked };
	bool ifKeyRefresh[256] = { false };
	bool ifKeyPressedThisFrame[256];
	void keyDownProper(unsigned char key, int x, int y);
	void keyUpProper(unsigned char key, int x, int y);
public:
	KeyboardHandler();
	void refresh();
	void setIfShouldRefresh(unsigned char key, bool should);
	bool getIfShouldRefresh(unsigned char key);
	void static keyDown(unsigned char key, int x, int y);
	void static keyUp(unsigned char key, int x, int y);
	bool checkIfPressed(unsigned char key);
};