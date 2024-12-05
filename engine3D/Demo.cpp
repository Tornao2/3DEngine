#include "Engine.h"
#include "stdlib.h"
#include <iostream>

class CustomKeyboard {
public:
    static void handleKeyboard(unsigned char key, int x, int y) {
        if (key == 27)
            exit(0);
    }
};

class CustomMouse {
public:
    static void handleMouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            printf("3");
    }
};

int main(int argc, char* argv[]) {
    Renderer renderer(Color { 0.5, 0.5, 0.5, 1 }, true, false);
    DisplayManager displayManager(640, 480, false, true, "3DEngine");
    KeyboardHandler key;
    MouseHandler mouse;
    Engine engine(&argc, argv, renderer, displayManager, 60);
    engine.registerCallbacks (CustomMouse::handleMouse, CustomKeyboard::handleKeyboard);
    engine.run();
    return 0;
}