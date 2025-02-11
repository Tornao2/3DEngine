#define STB_IMAGE_IMPLEMENTATION
#include "Engine.h"

#define NUMBEROFFIGURES 11
typedef enum figureType {
    point,
    line,
    poliline,
    triangle,
    quad,
    triangleFan,
    triangleStrip,
    cube,
    letterE,
    texturedQuad,
    texturedCube
}figureType;

class CustomKeyboard :public KeyboardHandler {
    DisplayManager* display;
    Engine* engine;
    Renderer* renderer;
    ObjectManager* manager;
    bool returnTheFunc;
    figureType createFigure;
    std::vector <TransformableFigure*>* transformable;
    Player* player;
public:
    CustomKeyboard(DisplayManager* readDisplay, Engine* readEngine, Renderer* readRenderer, ObjectManager* readManager, std::vector <TransformableFigure*>* transformables, Player* readPlayer) {
        display = readDisplay;
        engine = readEngine;
        renderer = readRenderer;
        manager = readManager;
        transformable = transformables;
        returnTheFunc = false;
        createFigure = point;
        player = readPlayer;
        setIfShouldRefresh('4', true);
        setIfShouldRefresh('5', true);
        setIfShouldRefresh('6', true);
        setIfShouldRefresh(',', true);
        setIfShouldRefresh('.', true);
        setIfShouldRefresh('[', true);
        setIfShouldRefresh(']', true);
    }
    void handleKeyboard() {
        glutKeyboardFunc(NULL);
        if (returnTheFunc) {
            glutKeyboardFunc(KeyboardHandler::keyDown);
            returnTheFunc = false;
        }
        if (checkIfPressed('['))
            renderer->toggleIfFlatShading();
        if (checkIfPressed(']'))
            renderer->setWarnModel(!renderer->getWarnModel());
        if (checkIfPressed('a')) 
            player->setMsX(-0.03f);
        if (checkIfPressed('d')) 
            player->setMsX(0.03f);
        if (checkIfPressed('s')) 
            player->setMsZ(0.03f);
        if (checkIfPressed('w')) 
            player->setMsZ(-0.03f);
        if (checkIfPressed(' '))
            player->setMsY(0.03f);
        if (checkIfPressed('z'))
            player->setMsY(-0.03f);
        if (checkIfPressed(27)) {
            glutDestroyWindow(glutGetWindow());
            exit(0);
        }
        if (checkIfPressed('1')) {
            returnTheFunc = true;
            std::cout << "Podaj liczbe klatek na sekunde: ";
            int fps;
            getUserInput<int>(fps);
            engine->setFpsCap(fps);
        }
        else if (checkIfPressed('2')) {
            returnTheFunc = true;
            std::cout << "Podaj szerokosc okna: ";
            int width;
            getUserInput<int>(width);
            display->setWindowWidth(width);
        }
        else if (checkIfPressed('3')) {
            returnTheFunc = true;
            std::cout << "Podaj wysokosc okna: ";
            int height;
            getUserInput<int>(height);
            display->setWindowHeight(height);
        }
        else if (checkIfPressed('7')) {
            returnTheFunc = true;
            float r, g, b;
            std::cout << "Podaj czesc r(0-1): ";
            getUserInput<float>(r);
            std::cout << "Podaj czesc g(0-1): ";
            getUserInput<float>(g);
            std::cout << "Podaj czesc b(0-1): ";
            getUserInput<float>(b);
            renderer->setClearColor({r, g, b});
        }
        else if (checkIfPressed('8')) {
            returnTheFunc = true;
            float x, y, z;
            std::cout << "Podaj czesc x: ";
            getUserInput<float>(x);
            std::cout << "Podaj czesc y: ";
            getUserInput<float>(y);
            std::cout << "Podaj czesc z: ";
            getUserInput<float>(z);
            renderer->setLightingPos({ x, y, z });
        }
        else if (checkIfPressed('p')) {
            returnTheFunc = true;
            float read;
            std::cout << "Podaj wspolczynnik: ";
            getUserInput<float>(read);
            renderer->setAmbientStrength(read);
        }
        else if (checkIfPressed('o')) {
            returnTheFunc = true;
            int read;
            std::cout << "Podaj wspolczynnik: ";
            getUserInput<int>(read);
            renderer->setScatterStrength(read);
        }
        else if (checkIfPressed('u')) {
            returnTheFunc = true;
            float read;
            std::cout << "Podaj wspolczynnik: ";
            getUserInput<float>(read);
            renderer->setSpecularStrength(read);
        }
        else if (checkIfPressed('l')) {
            returnTheFunc = true;
            float read;
            std::cout << "Podaj wspolczynnik: ";
            getUserInput<float>(read);
            renderer->setBoostColor(read);
        }
        else if (checkIfPressed('f')) {
            returnTheFunc = true;
            int numb;
            std::cout << "Podaj czy chcesz usunac figure indeksowa teksturowana - 2, figure indeksowa - 1, czy figure wierzcholkowa - 0: ";
            getUserInput<int>(numb);
            if (numb == 2) {
                std::cout << "Podaj indeks do usuniecia: ";
                getUserInput<int>(numb);
                renderer->getManager()->removeIndicedDrawableTextured(numb);
            } else if (numb == 1) {
                std::cout << "Podaj indeks do usuniecia: ";
                getUserInput<int>(numb);
                renderer->getManager()->removeIndicedDrawable(numb);
            }
            else if(numb == 0){
                std::cout << "Podaj indeks do usuniecia: ";
                getUserInput<int>(numb);
                renderer->getManager()->removeDirectDrawable(numb);
            }
        } else if (checkIfPressed('v')) {
            returnTheFunc = true;
            int numb;
            std::cout << "Podaj indeks obiektu do skalowania: ";
            getUserInput<int>(numb);
            if (numb >= 0 && transformable->size() > numb) {
                float scale;;
                std::cout << "Podaj wartosc skalowania: ";
                getUserInput<float>(scale);
                transformable->at(numb)->scale({scale});
            }
        } else if (checkIfPressed('t')) {
            returnTheFunc = true;
            int numb;
            std::cout << "Podaj indeks obiektu do translacji: ";
            getUserInput<int>(numb);
            if (numb >= 0 && transformable->size() > numb) {
                float transX, transY, transZ;
                std::cout << "Podaj wartosc translacji X: ";
                getUserInput<float>(transX);
                std::cout << "Podaj wartosc translacji Y: ";
                getUserInput<float>(transY);
                std::cout << "Podaj wartosc translacji Z: ";
                getUserInput<float>(transZ);
                transformable->at(numb)->translate({ transX, transY, transZ });
            }
        } else if (checkIfPressed('r')) {
            returnTheFunc = true;
            int numb;
            std::cout << "Podaj indeks obiektu do rotacji: ";
            getUserInput<int>(numb);
            if (numb >= 0 && transformable->size() > numb) {
                glm::vec3 axis;
                float rotate;
                std::cout << "Podaj wartosc osi X: ";
                getUserInput<float>(axis.x);
                std::cout << "Podaj wartosc osi Y: ";
                getUserInput<float>(axis.y);
                std::cout << "Podaj wartosc osi Z: ";
                getUserInput<float>(axis.z);
                std::cout << "Podaj rotacji: ";
                getUserInput<float>(rotate);
                transformable->at(numb)->rotate(rotate, axis);
            }
        }
        else if (checkIfPressed('c')) {
            returnTheFunc = true;
            std::vector <glm::vec4> temp;
            float size, x, y, z;
            BitmapHandler tempBitmap;
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
                manager->addDirectDrawable(new Point(temp, size));
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
                manager->addDirectDrawable(new Line(temp, size));
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
                    manager->addDirectDrawable(new PoliLine(temp, size, (bool) check));
                break;
            case triangle:
                for (int i = 1; i < 4; i++) {
                    std::cout << "Podaj pozycje " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) "<< i <<" punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                }
                manager->addDirectDrawable(new Triangle(temp));
                break;
            case quad:
                for (int i = 1; i < 5; i++) {
                    std::cout << "Podaj pozycje " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                    std::cout << "Podaj kolor(0-1) " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                }
                manager->addDirectDrawable(new Quads(temp));
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
                    manager->addDirectDrawable(new TriangleFan(temp));
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
                    manager->addDirectDrawable(new TriangleStrip(temp));
                break;
            case cube:
                do {
                    std::cout << "Podaj dlugosc boku szecianu E: ";
                    getUserInput<float>(size);
                } while (size <= 0);
                std::cout << "Podaj x szecianu: ";
                getUserInput<float>(x);
                std::cout << "Podaj y szecianu: ";
                getUserInput<float>(y);
                std::cout << "Podaj z szecianu: ";
                getUserInput<float>(z);
                std::cout << "Podaj kolor(0-1) szecianu w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                for (int i = 0; i < 23; i++)
                    temp.push_back(temp[0]);
                manager->addIndicedDrawable(new Cube(size, x, y, z, temp));
                break;
            case letterE:
                do {
                    std::cout << "Podaj dlugosc boku litery E: ";
                    getUserInput<float>(size);
                } while (size <= 0);
                std::cout << "Podaj x litery E: ";
                getUserInput<float>(x);
                std::cout << "Podaj y litery E: ";
                getUserInput<float>(y);
                std::cout << "Podaj z litery E: ";
                getUserInput<float>(z);
                std::cout << "Podaj kolor(0-1) litery E w formacie: _ _ _ _: ";
                temp.push_back(getUserInput());
                for (int i = 0; i < 76; i++)
                    temp.push_back(temp[0]);
                manager->addIndicedDrawable(new FigureE(size, x, y, z, temp));
                break;
            case texturedCube:
                do {
                    std::cout << "Podaj dlugosc boku szecianu E: ";
                    getUserInput<float>(size);
                } while (size <= 0);
                std::cout << "Podaj x szecianu: ";
                getUserInput<float>(x);
                std::cout << "Podaj y szecianu: ";
                getUserInput<float>(y);
                std::cout << "Podaj z szecianu: ";
                getUserInput<float>(z);              
                check = tempBitmap.loadBitmap("dirt.png");
                manager->addIndicedDrawableTextured(new CubeTextured(size, x, y, z));
                manager->getIndicedDrawableTextured()->setTextured(check);
                break;
            case texturedQuad:
                for (int i = 1; i < 5; i++) {
                    std::cout << "Podaj pozycje " << i << " punktu w formacie : _ _ _ _ : ";
                    temp.push_back(getUserInput());
                    temp.push_back({ 0, 0, 1, 0 });
                }
                temp.insert(temp.begin()+2, glm::vec4{0, 0, 0, 0});
                temp.insert(temp.begin() + 5, glm::vec4{ 1, 0, 0, 0 });
                temp.insert(temp.begin() + 8, glm::vec4{ 1, 1, 0, 0 });
                temp.push_back(glm::vec4{ 0, 1, 0, 0 });
                check = tempBitmap.loadBitmap("dirt.png");
                manager->addDirectDrawable(new QuadsTextured(temp));
                manager->getDirectDrawable()->setTextured(check);
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
            std::cout << "Wybrano typ obiektu rysowanego: ";
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
            case letterE:
                std::cout << "Litera E";
                break;
            case texturedCube:
                std::cout << "Szescian oteksturowany";
                break;
            case texturedQuad:
                std::cout << "Czworokat oteksturowany";
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
    void handleMouse() {
        if (checkIfPressed(leftButton))
            printf("Clicked\n");
        refresh();
    }
};

void fillManager(ObjectManager* managers, std::vector <TransformableFigure*>* transformables, Player** player) {
    std::vector<glm::vec4> pointData = {
        glm::vec4(-7.0f,  -1.0f, -5.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> lineData = {
        glm::vec4(-6.5f,  3.0f, -5, 1.0), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0, 1.0f),
        glm::vec4(-5.5f,  5.0f, -5, 1.0), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0, 1.0f)
    };
    std::vector<glm::vec4> triangleData = {
        glm::vec4(-4.5f,  2.5f, -5.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
        glm::vec4(-5.0f, 0.5f, -5.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 1.0f, 1.0f, 1.0f),
        glm::vec4(-4.0f, -1.5f, -5.0f, 1.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),glm::vec4(0.0f, 1.0f, 1.0f, 1.0f)
    };
    std::vector<glm::vec4> poliLineData = {
        glm::vec4(-3.0f,  2.0f, -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-2.5f,  5.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(-2.0f, 0.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
    };
    std::vector <glm::vec4> closedPoliLine = {
        glm::vec4(-1.5f,  2.0f, -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-2.0f, -3.0f, -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(0.0f,  2.0f, -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-1.5f,  2.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
    };
    std::vector<glm::vec4> triangleStripData = {
        glm::vec4(-0.3f, -3.5f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(0.5f,  0.5f,  -2.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-1.2f, -2.5f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.6f, 0.0f, 1.0f, 1.0f),
        glm::vec4(1.0f,  3.0f,  -2.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.1f, 1.0f, 0.2f, 1.0f),
    };
    std::vector<glm::vec4> triangleFanData = {
        glm::vec4(3.5f, 0.0f,  -4.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(3.0f, -1.0f,  -4.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f),
        glm::vec4(2.6f, -0.7f,  -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(2.5f, 2.0f,  -3.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f)
    };
    std::vector<glm::vec4> quadsData = {
        glm::vec4(-6.5f, -4.5f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-6.5f,  -8.0f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
        glm::vec4(-8.5f,  -8.0f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f),
        glm::vec4(-8.5f, -4.5f, -5.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
    };
    std::vector<glm::vec4> quadsTexturedData = {
        glm::vec4(30.5f, -14.5f, -30.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 0.0f, 0.0f),
        glm::vec4(30.5f,  -14.5f, 30.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 0.0f, 0.0f, 0.0f),
        glm::vec4(-30.5f,  -14.5f, 30.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(1.0f, 1.0f, 0.0f, 0.0f),
        glm::vec4(-30.5f, -14.5f, -30.0f, 1.0f),glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 0.0f),
    };
    std::vector<glm::vec4> cubeColors = {
        {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1},
        {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1},
        {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1},
        {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1}, {0, 1, 0, 1},
        {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1},
        {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1},
    };
    std::vector<glm::vec4> playerColors;
    for (int i = 0; i < 24; i++)
        playerColors.push_back({ 1, 1, 1, 1 });
    std::vector <glm::vec4> EColors;
    for (int i = 0; i < 76; i++) {
        EColors.push_back({ 1, 1, 1, 1 });
    }
    BitmapHandler tempBitmap;
    int dirtId = tempBitmap.loadBitmap("dirt.png");
    managers->addDirectDrawable(new Point(pointData, 20));
    transformables->push_back((Point*)managers->getDirectDrawable());
    managers->addDirectDrawable(new Line(lineData, 10));
    transformables->push_back((Line*)managers->getDirectDrawable());
    managers->addDirectDrawable(new Triangle(triangleData));
    transformables->push_back((Triangle*)managers->getDirectDrawable());
    managers->addDirectDrawable(new PoliLine(poliLineData, 10, false));
    transformables->push_back((PoliLine*)managers->getDirectDrawable());
    managers->addDirectDrawable(new PoliLine(closedPoliLine, 5, true));
    transformables->push_back((PoliLine*)managers->getDirectDrawable());
    managers->addDirectDrawable(new TriangleStrip(triangleStripData));
    transformables->push_back((TriangleStrip*)managers->getDirectDrawable());
    managers->addDirectDrawable(new TriangleFan(triangleFanData));
    transformables->push_back((TriangleFan*)managers->getDirectDrawable());
    managers->addDirectDrawable(new Quads(quadsData));
    transformables->push_back((Quads*)managers->getDirectDrawable());
    managers->addDirectDrawable(new QuadsTextured(quadsTexturedData));
    managers->getDirectDrawable()->setTextured(true);
    ((QuadsTextured*) managers->getDirectDrawable())->setTextureId(dirtId);
    transformables->push_back((QuadsTextured*)managers->getDirectDrawable());
    managers->addIndicedDrawableTextured(new CubeTextured(2.0f, 5.0f, -3.0, -5.0f));
    managers->getIndicedDrawableTextured()->setTextured(true);
    ((CubeTextured*)managers->getIndicedDrawableTextured())->setTextureId(dirtId);
    transformables->push_back((CubeTextured*)managers->getIndicedDrawableTextured());
    *player = new Player(0.4f, 0.0f, -2.0f, -2.0f, playerColors);
    managers->addIndicedDrawable(*player);
    transformables->push_back((Player*)managers->getIndicedDrawable());
    managers->addIndicedDrawable(new Cube(1.5f, -5.75f, -4.25f, -1.0f, cubeColors));
    transformables->push_back((Cube*)managers->getIndicedDrawable());
    managers->addIndicedDrawable(new FigureE(1.5f, -2.5f, 3.0f, -5.0f, EColors));
}

void printCommandList() {
    std::cout << "Nacisnij esc aby wyjsc" << std::endl;
    std::cout << "Nacisnij 1 zeby wybrac liczbe klatek na sekunde" << std::endl;
    std::cout << "Nacisnij 2 zeby wybrac szerokosc okna" << std::endl;
    std::cout << "Nacisnij 3 zeby wybrac wysokosc okna" << std::endl;
    std::cout << "Nacisnij 4 zeby wlaczyc/wylaczyc fullscreen" << std::endl;
    std::cout << "Nacisnij 5 zeby wlaczyc/wylaczyc readZBuffer" << std::endl;
    std::cout << "Nacisnij 6 zeby wlaczyc/wylaczyc widok ortogonalny" << std::endl;
    std::cout << "Nacisnij 7 zeby zmienic kolor odswiezania" << std::endl;
    std::cout << "Nacisnij 8 zeby zmienic pozycje oswietlenia" << std::endl;
    std::cout << "Nacisnij p aby zmienic wspolczynnik oswietlenia ambientowego" << std::endl;
    std::cout << "Nacisnij o aby zmienic wspolczynnik rozproszenia" << std::endl;
    std::cout << "Nacisnij u aby zmienic wspolczynnik odblasku" << std::endl;
    std::cout << "Nacisnij l aby zmienic zwiekszenie koloru" << std::endl;
    std::cout << "Nacisnij f zeby usunac obiekt rysowany" << std::endl;
    std::cout << "Nacisnij c aby stworzyc obiekt rysowany" << std::endl;
    std::cout << "Nacisnij r aby obrocic obiekt" << std::endl;
    std::cout << "Nacisnij v aby skalowac obiekt" << std::endl;
    std::cout << "Nacisnij t aby przeprowadzic translacje obiektu" << std::endl;
    std::cout << "Nacisnij , lub . aby przechodzic miedzy typami obiektu rysowanego do stworzenia" << std::endl;
    std::cout << "Nacisnij a/s/d/w/spacji/z aby sterowac graczem" << std::endl;
    std::cout << "Nacisnij [ aby przelaczac miedzy trybami cieniowania" << std::endl;
    std::cout << "Nacisnij ] aby przelaczac miedzy modelami oswietlenia" << std::endl;
}

int main(int argc, char** argv) {
    printCommandList();
    ObjectManager manager;
    Renderer renderer(&manager);
    DisplayManager displayManager;
    Engine engine(&argc, argv, renderer, displayManager, 300);
    std::vector <TransformableFigure*> transformables;
    Player* player = nullptr;
    fillManager(&manager, &transformables, &player);
    CustomMouse mouse;
    CustomKeyboard key(&displayManager, &engine, &renderer, &manager, &transformables, player);
    Observer camera = Observer(renderer.getShader());
    mouse.setCamera(&camera);
    engine.toggleMouse(true, std::bind(&CustomMouse::handleMouse, &mouse));
    engine.toggleKeyboard(true, std::bind(&CustomKeyboard::handleKeyboard, &key));
    glutMainLoop();
}
