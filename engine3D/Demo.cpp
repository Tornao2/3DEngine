#include "Engine.h"

#define NUMBEROFFIGURES 8
typedef enum figureType {
    point,
    line,
    poliline,
    triangle,
    quad,
    triangleFan,
    triangleStrip,
    cube
}figureType;

class CustomKeyboard :public KeyboardHandler {
    DisplayManager* display;
    Engine* engine;
    Renderer* renderer;
    ObjectManager* manager;
    bool returnTheFunc;
    figureType createFigure;
public:
    CustomKeyboard(DisplayManager* readDisplay, Engine* readEngine, Renderer* readRenderer, ObjectManager* readManager) {
        display = readDisplay;
        engine = readEngine;
        renderer = readRenderer;
        manager = readManager;
        returnTheFunc = false;
        setIfShouldRefresh('4', true);
        setIfShouldRefresh('5', true);
        setIfShouldRefresh('6', true);
        setIfShouldRefresh(',', true);
        setIfShouldRefresh('.', true);
        createFigure = point;
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
            getUserInput<float>(fps);
            engine->setFpsCap(fps);
        }
        else if (checkIfPressed('2')) {
            returnTheFunc = true;
            std::cout << "Podaj szerokosc okna ";
            float width;
            getUserInput<float>(width);
            display->setWindowWidth(width);
        }
        else if (checkIfPressed('3')) {
            returnTheFunc = true;
            std::cout << "Podaj wysokosc okna ";
            float height;
            getUserInput<float>(height);
            display->setWindowHeight(height);
        }
        else if (checkIfPressed('7')) {
            returnTheFunc = true;
            float r, g, b, a;
            std::cout << "Podaj czesc r(0-255) ";
            getUserInput<float>(r);
            std::cout << "Podaj czesc g(0-255) ";
            getUserInput<float>(g);
            std::cout << "Podaj czesc b(0-255) ";
            getUserInput<float>(b);
            renderer->setClearColor(normalizeColors({ r, g, b, 255 }));
        }
        else if (checkIfPressed('8')) {
            returnTheFunc = true;
            float x, y, z;
            std::cout << "Podaj czesc x ";
            getUserInput<float>(x);
            std::cout << "Podaj czesc y ";
            getUserInput<float>(y);
            std::cout << "Podaj czesc z ";
            getUserInput<float>(z);
            renderer->setlightingVector({ x, y, z, 0 });
        }
        else if (checkIfPressed('d')) {
            returnTheFunc = true;
            int numb;
            std::cout << "Podaj numer figury do usuniecia ";
            getUserInput<int>(numb);
            renderer->getManager()->removePrimitive(numb);
        }
        else if (checkIfPressed('c')) {
            returnTheFunc = true;
            std::vector <glm::vec4> temp;
            float size;
            int check;
            switch (createFigure) {
            case point:
                std::cout << "Podaj pozycje w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                temp.push_back({ 0, 0, 1, 0 });
                std::cout << "Podaj kolor(0-1) w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                std::cout << "Podaj rozmiar punktu: ";
                getUserInput <float>(size);
                manager->addPrimitive(new Point(temp, size));
                break;
            case line:
                std::cout << "Podaj pozycje 1 linii w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                temp.push_back({ 0, 0, 1, 0 });
                std::cout << "Podaj kolor(0-1) 1 linii w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                std::cout << "Podaj pozycje 2 linii w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                temp.push_back({ 0, 0, 1, 0 });
                std::cout << "Podaj kolor(0-1) 2 linii w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                std::cout << "Podaj szerokosc linii: ";
                getUserInput <float>(size);
                manager->addPrimitive(new Line(temp, size));
                break;
            case poliline:
                check = 1;
                while (check) {
                    std::cout << "Podaj pozycje kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    while (true) {
                        std::cout << "Podaj 1 aby kontynuowac albo 0 zeby przerwac: ";
                        getUserInput<int>(check);
                        if (check == 1 || check == 0) break;
                    }
                }
                std::cout << "Podaj szerokosc linii: ";
                getUserInput <float>(size);
                int check;
                while (true) {
                    std::cout << "Podaj 1 aby linia byla zamknieta albo 0 zeby otwarta: ";
                    getUserInput<int>(check);
                    if (check == 1 || check == 0) break;
                }
                if (temp.size() >= 3)
                    manager->addPrimitive(new PoliLine(temp, size, (bool) check));
                break;
            case triangle:
                for (int i = 1; i < 4; i++) {
                    std::cout << "Podaj pozycje " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) "<< i <<" punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                }
                manager->addPrimitive(new Triangle(temp));
                break;
            case quad:
                for (int i = 1; i < 5; i++) {
                    std::cout << "Podaj pozycje " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                }
                manager->addPrimitive(new Quads(temp));
                break;
            case triangleFan:
                check = 1;
                while (check)  {
                    std::cout << "Podaj pozycje kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    while (true) {
                        std::cout << "Podaj 1 aby kontynuowac albo 0 zeby przerwac: ";
                        getUserInput<int>(check);
                        if (check == 1 || check == 0) break;
                    }
                }
                if (temp.size() >= 9)
                    manager->addPrimitive(new TriangleFan(temp));
                break;
            case triangleStrip: 
                check = 1;
                while (check) {
                    std::cout << "Podaj pozycje kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) kolejnego punktu w formacie: _ _ _ _: ";
                    temp.push_back(getUserInput());
                    while (true) {
                        std::cout << "Podaj 1 aby kontynuowac albo 0 zeby przerwac: ";
                        getUserInput<int>(check);
                        if (check == 1 || check == 0) break;
                    }
                }
                if (temp.size() >= 9)
                    manager->addPrimitive(new TriangleStrip(temp));
                break;
            case cube:
                //Po dodaniu
                break;
            }
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
        if (checkIfPressed('.') || (checkIfPressed(','))) {
            if (checkIfPressed('.')) 
                createFigure = (figureType)((createFigure + 1) % NUMBEROFFIGURES);
            else {
                createFigure = (figureType)((createFigure)-1);
                if (createFigure < 0)
                    createFigure = (figureType)((createFigure)+NUMBEROFFIGURES);
            }
            std::cout << "Wybrano typ figury: ";
            switch (createFigure) {
            case point:
                std::cout << "Punkt";
                break;
            case line:
                std::cout << "Linia";
                break;
            case poliline:
                std::cout << "Linia lamana";
                break;
            case triangle:
                std::cout << "Trojkat";
                break;
            case quad:
                std::cout << "Czworokat";
                break;
            case triangleFan:
                std::cout << "Wachlarz trojkatow";
                break;
            case triangleStrip:
                std::cout << "Pas trojkatow";
                break;
            case cube:
                std::cout << "Szescian";
                break;
            }
            std::cout << std::endl;
        }
        if (!returnTheFunc)
            glutKeyboardFunc(KeyboardHandler::keyDown);
        refresh();
    }
    template <typename T>
    void getUserInput(T& inputVar) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> inputVar;
    }
    glm::vec4 getUserInput() {
        glm::vec4 temp;
        std::string line;
        std::getline(std::cin, line);
        trim(line);
        std::stringstream ss(line);
        ss >> temp.x;
        ss >> temp.y;
        ss >> temp.z;
        ss >> temp.w;
        return temp;
    }
    void leftTrim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {return !std::isspace(ch);}));
    }
    void rightTrim(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {return !std::isspace(ch);}).base(), s.end());
    }
    void trim(std::string& s) {
        leftTrim(s);
        rightTrim(s);
    }
};

class CustomMouse :public MouseHandler {
public:
    CustomMouse(Shader* shader) : MouseHandler(shader) {};
    void handleMouse() {
        if (checkIfPressed(leftButton))
            printf("3\n");
        refresh();
    }
};

void fillManager(ObjectManager* managers) {
    std::vector<glm::vec4> triangleData = {
        glm::vec4(-3.0f,  0.5f, -3.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-5.5f, -5.5f, -3.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(3.5f, -0.5f, -3.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> lineData = {
        glm::vec4(-5.5f,  0.0f, -30.0f, 1.0), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0, 1.0f),
        glm::vec4(5.5f,  5.0f, -30.0f, 1.0), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.1, 1.0f)
    };
    std::vector<glm::vec4> pointData = {
        glm::vec4(2.0f,  0.0f, -3.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> poliLineData = {
        glm::vec4(2.0f,  0.0f, -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(0.0f,  1.0f,  1.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-1.0f, 0.5f,  2.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
    };
    std::vector <glm::vec4> closedPoliLine = {
        glm::vec4(0.5f,  2.0f, -1.5f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
        glm::vec4(-2.0f, -1.0f, 1.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(1.0f,  -2.0f, -2.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f),
        glm::vec4(2.5f,  0.0f,  1.5f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.3f, 0.7f, 0.3f, 1.0f),
    };
    std::vector<glm::vec4> triangleStripData = {
        glm::vec4(-1.0f, -3.5f,  -4.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-1.0f,  2.5f,  -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(0.0f, -3.5f,  -4.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(0.0f,  2.5f,  -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(1.0f, -3.5f,  -4.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(1.0f,  1.0f,  -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> triangleFanData = {
        glm::vec4(3.0f, 0.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
        glm::vec4(3.5f, 0.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(3.3f, 0.7f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(3.0f, 1.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(2.6f, 0.7f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(2.5f, 0.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> quadsData = {
        glm::vec4(-0.5f, -2.5f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-0.5f,  -6.0f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-2.5f,  -6.0f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(-2.5f, -0.5f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
    };

    managers->addPrimitive(new Triangle(triangleData));
    managers->addPrimitive(new Point(pointData, 40));
    managers->addPrimitive(new Line(lineData, 10));
    managers->addPrimitive(new PoliLine(poliLineData, 10, false));
    managers->addPrimitive(new PoliLine(closedPoliLine, 5, true));
    managers->addPrimitive(new TriangleStrip(triangleStripData));
    managers->addPrimitive(new TriangleFan(triangleFanData));
    managers->addPrimitive(new Quads(quadsData));
    //managers->addFigure(new Cube())
}

int main(int argc, char** argv) {
    std::cout << "Nacisnij 1 zeby wybrac liczbe klatek na sekunde" << std::endl;
    std::cout << "Nacisnij 2 zeby wybrac szerokosc okna" << std::endl;
    std::cout << "Nacisnij 3 zeby wybrac wysokosc okna" << std::endl;
    std::cout << "Nacisnij 4 zeby wlaczyc/wylaczyc fullscreen" << std::endl;
    std::cout << "Nacisnij 5 zeby wlaczyc/wylaczyc zBuffer" << std::endl;
    std::cout << "Nacisnij 6 zeby wlaczyc/wylaczyc widok ortogonalny" << std::endl;
    std::cout << "Nacisnij 7 zeby zmienic kolor odswiezania" << std::endl;
    std::cout << "Nacisnij 8 zeby zmienic wektor oswietlenia" << std::endl;
    std::cout << "Nacisnij d zeby usunac figure" << std::endl;
    std::cout << "Nacisnij c aby stworzyc figure" << std::endl;
    std::cout << "Nacisnij , lub . aby przechodzic miedzy typami figury do stworzenia" << std::endl;
    ObjectManager manager;
    Renderer renderer(&manager);
    DisplayManager displayManager;;
    Engine engine(&argc, argv, renderer, displayManager);
    fillManager(&manager);
    CustomKeyboard key(&displayManager, &engine, &renderer, &manager);
    CustomMouse mouse(renderer.getShader());
    engine.toggleMouse(true, std::bind(&CustomMouse::handleMouse, &mouse));
    engine.toggleKeyboard(true, std::bind(&CustomKeyboard::handleKeyboard, &key));
    glutMainLoop();
}
