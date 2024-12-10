#include "Engine.h"

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
    CustomMouse(Shader* shader) : MouseHandler(shader) {};
    void handleMouse() {
        if (checkIfPressed(leftButton))
            printf("3");
        refresh();
    }
};

void fillManager(ObjectManager* managers) {
    std::vector<glm::vec4> triangleData = {
    glm::vec4(0.0f,  0.5f, -3.0f, 1.0f),
    glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
    glm::vec4(-11.5f, -10.5f, -3.0f, 1.0f),
    glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
    glm::vec4(11.5f, -0.5f, -3.0f, 1.0f),
    glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> lineData = {
        glm::vec4(-11.0f,  0.0f, -3.0f, 1.0),
        glm::vec4(1.0f, 1.0f, 0.0, 1.0f),
        glm::vec4(11.0f,  5.0f, -3.0f, 1.0),
        glm::vec4(1.0f, 0.0f, 0.1, 1.0f)
    };
    std::vector<glm::vec4> pointData = {
        glm::vec4(2.0f,  0.0f, -3.0f, 1.0f),
        glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    }; 
    std::vector<glm::vec4> circleData;
    const float radius = 10.0f;
    for (int i = 0; i < 360; i += 3) {
        float angle = glm::radians((float)i);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        circleData.push_back({ x, -y, -1.0f, 1 });
        circleData.push_back({ 1, 0, 0, 1 });
        managers->addFigure(new Point(circleData, 10));
        circleData.clear();
    }
    managers->addFigure(new Triangle(triangleData));
    managers->addFigure(new Point(pointData, 40));
    managers->addFigure(new Line(lineData, 10));
}

int main(int argc, char** argv) {
    std::cout << "Nacisnij 1 zeby wybrac liczbe klatek na sekunde" << std::endl;
    std::cout << "Nacisnij 2 zeby wybrac szerokosc okna" << std::endl;
    std::cout << "Nacisnij 3 zeby wybrac wysokosc okna" << std::endl;
    std::cout << "Nacisnij 4 zeby wlaczyc/wylaczyc fullscreen" << std::endl;
    std::cout << "Nacisnij 5 zeby wlaczyc/wylaczyc zBuffer" << std::endl;
    std::cout << "Nacisnij 6 zeby wlaczyc/wylaczyc widok ortogonalny" << std::endl;
    std::cout << "Nacisnij 7 zeby zmienic kolor odswiezania" << std::endl;
    ObjectManager manager;
    Renderer renderer(&manager);
    DisplayManager displayManager = DisplayManager();
    Engine engine(&argc, argv, renderer, displayManager);
    CustomKeyboard key(&displayManager, &engine, &renderer);
    renderer.setUpShaders();
    CustomMouse mouse(renderer.getShader());
    engine.toggleMouse(true, std::bind(&CustomMouse::handleMouse, &mouse));
    engine.toggleKeyboard(true, std::bind(&CustomKeyboard::handleKeyboard, &key));
    engine.registerCallbacks();
    fillManager(&manager);
    glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
    engine.run();
}
