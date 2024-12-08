#include "Engine.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <sstream>

class CustomKeyboard :public KeyboardHandler {
    DisplayManager* display;
    Engine* engine;
    Renderer* renderer;
    bool returnTheFunc;
public:
    CustomKeyboard(DisplayManager* readDisplay, Engine* readEngine, Renderer* readRenderer) {
        display = readDisplay;
        engine = readEngine;
        renderer = readRenderer;
        returnTheFunc = false;
        setIfShouldRefresh('4', true);
        setIfShouldRefresh('5', true);
        setIfShouldRefresh('6', true);
    }
    void handleKeyboard() {
        glutKeyboardFunc(NULL);
        if (returnTheFunc) {
            glutKeyboardFunc(KeyboardHandler::keyDown);
            returnTheFunc = false;
        }
        if (checkIfPressed(27)) {
            glutDestroyWindow(glutGetWindow());
            exit(0);
        }
        if (checkIfPressed('1')) {
            returnTheFunc = true;
            std::cout << "Podaj liczbe klatek na sekunde ";
            float fps;
            getUserInput(fps);
            engine->setFpsCap(fps);
        }
        else if (checkIfPressed('2')) {
            returnTheFunc = true;
            std::cout << "Podaj szerokosc okna ";
            float width;
            getUserInput(width);
            display->setWindowWidth(width);
        }
        else if (checkIfPressed('3')) {
            returnTheFunc = true;
            std::cout << "Podaj wysokosc okna ";
            float height;
            getUserInput(height);
            display->setWindowHeight(height);
        }
        else if (checkIfPressed('7')) {
            returnTheFunc = true;
            float r, g, b, a;
            std::cout << "Podaj czesc r(0-255) ";
            getUserInput(r);
            std::cout << "Podaj czesc g(0-255) ";
            getUserInput(g);
            std::cout << "Podaj czesc b(0-255) ";
            getUserInput(b);
            renderer->setClearColor(normalizeColors({ r, g, b, 255 }));
        }
        if (checkIfPressed('4'))
            display->setFullscreen(!display->ifFullscreen());
        if (checkIfPressed('5')) {
            renderer->setZBuffer(!renderer->getZBuffer());
            std::cout << "Zmieniono ZBuffer" << std::endl;
        }
        if (checkIfPressed('6')) {
            renderer->setOrthogonal(!renderer->getOrthogonal());
            std::cout << "Zmieniono ustawienie widoku ortogonalnego" << std::endl;
        }
        if (!returnTheFunc)
            glutKeyboardFunc(KeyboardHandler::keyDown);
        refresh();
    }
    void getUserInput(float& inputVar) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> inputVar;
    }
};

class CustomMouse :public MouseHandler {
public:
    void handleMouse() {
        if (checkIfPressed(leftButton))
            printf("3");
        refresh();
    }
};

void fillManager(ObjectManager& manager) {
    float pos[6] = { 1, 0 ,0, 1.0, 1, 0.2 };
    float pos2[6] = { 0, -1 ,1, 1.0, 1.0, 1.0 };
    manager.addFigure(new Point(pos, 50));
    manager.addFigure(new Point(pos2, 50));
}

int main(int argc, char* argv[]) {
    std::cout << "Nacisnij 1 zeby wybrac liczbe klatek na sekunde" << std::endl;
    std::cout << "Nacisnij 2 zeby wybrac szerokosc okna" << std::endl;
    std::cout << "Nacisnij 3 zeby wybrac wysokosc okna" << std::endl;
    std::cout << "Nacisnij 4 zeby wlaczyc/wylaczyc fullscreen" << std::endl;
    std::cout << "Nacisnij 5 zeby wlaczyc/wylaczyc zBuffer" << std::endl;
    std::cout << "Nacisnij 6 zeby wlaczyc/wylaczyc widok ortogonalny" << std::endl;
    std::cout << "Nacisnij 7 zeby zmienic kolor odswiezania" << std::endl;
    ObjectManager manager;
    Renderer renderer(&manager, Color{ 0.5, 0.5, 0.5, 1 }, true, false);
    DisplayManager displayManager(640, 480, false, true, "3DEngine");
    Engine engine(&argc, argv, renderer, displayManager, 60);
    CustomKeyboard key(&displayManager, &engine, &renderer);
    CustomMouse mouse;
    engine.toggleKeyboard(true, std::bind(&CustomKeyboard::handleKeyboard, &key));
    engine.toggleMouse(true, std::bind(&CustomMouse::handleMouse, &mouse));
    engine.setKeyboardFunc(std::bind(&CustomKeyboard::handleKeyboard, &key));
    engine.registerCallbacks();
    renderer.setUpShaders();
    fillManager(manager);
    engine.run();
    return 0;
}