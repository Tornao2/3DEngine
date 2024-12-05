#include "Engine.h"
#include "stdlib.h"
#include <iostream>

class CustomKeyboard:public KeyboardHandler {
public:
    void handleKeyboard() {
        if (checkIfPressed(27))
            exit(0);
        if (checkIfPressed('a'))
            puts("2");
         refresh();
    }
};

class CustomMouse:public MouseHandler {
public:
    void handleMouse() {
        if (checkIfPressed(leftButton))
            printf("3");
        refresh();
    }
};

int main(int argc, char* argv[]) {
    Renderer renderer(Color { 0.5, 0.5, 0.5, 1 }, true, false);
    DisplayManager displayManager(640, 480, false, true, "3DEngine");
    Engine engine(&argc, argv, renderer, displayManager, 60);
    CustomKeyboard key;
    CustomMouse mouse;
    engine.toggleKeyboard(true, std::bind(&CustomKeyboard::handleKeyboard, &key));
    engine.toggleMouse(true, std::bind(&CustomMouse::handleMouse, &mouse));
    engine.setKeyboardFunc(std::bind(&CustomKeyboard::handleKeyboard, &key));
    engine.registerCallbacks();
    engine.run();
    return 0;
}