#include <fstream>
#include <sstream>
#include <string>
#include "ObjectManager.h"
#include "DisplayManager.h"
#include "MouseHandler.h"
#include <iostream>
#include <vector>
#include "Engine.h"

Shader* shader = nullptr;
ObjectManager* manager = nullptr;

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader->getProgramId());
    glBindVertexArray(shader->getVAO());
    manager->drawAll();
    glBindVertexArray(0);
    glutSwapBuffers();
}

void fillManager(ObjectManager* managers) {
    std::vector <glm::vec4> triangleData = {
    glm::vec4(0.0f,  0.5f, 0.0f, 1.0f),
    glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
    glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f),
    glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
    glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),
    glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
    };
    std::vector <glm::vec4> lineData = {
        glm::vec4(-0.75f, 0.75f, 0.0f, 1.0f),
        glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(0.75f, 0.75f, 0.0f, 1.0f),
        glm::vec4(1.0f, 0.0f, 0.1f, 1.0f)
    };
    std::vector <glm::vec4> line1Data = {
        glm::vec4(0.0f, 0.75f, 0.0f, 1.0f),
        glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
    };
    std::vector <glm::vec4> pointData = {
        glm::vec4(0.0f, -0.75f, 0.0f, 1.0f),
        glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    };
    managers->addFigure(new Triangle (triangleData, 10));
    managers->addFigure(new Point(pointData, 10));
    managers->addFigure(new Line(lineData, 2));
}

class CustomKeyboard :public KeyboardHandler {
    DisplayManager* display;
    //Engine* engine;
    //Renderer* renderer;
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

int main(int argc, char** argv) {
    DisplayManager displayManager(640, 480, false, true, "3DEngine");
    shader = new Shader();
    manager = new ObjectManager(shader);
    fillManager(manager);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
