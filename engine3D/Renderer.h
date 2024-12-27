#pragma once
#include "ObjectManager.h"
#include <glm/gtc/type_ptr.hpp>

/**
 * @class Renderer
 * Klasa odpowiedzialna za renderowanie progrmau.
 */
class Renderer {
private:
    /** Funkcja wykonuj�ca w�a�ciwe renderowanie. */
    void renderProper();
    /** Statyczny wska�nik na instancj� klasy Renderer. */
    static Renderer* instance;
    /** Wska�nik na mened�era obiekt�w do renderowania. */
    ObjectManager* manager;
    /** Wska�nik na obiekt obs�uguj�cy shadery. */
    Shader* shader;
    /** Kolor t�a, kt�ry zostanie u�yty przy czyszczeniu ekranu. */
    glm::vec3 clearColor;
    /** Flaga okre�laj�ca, czy z-buffer jest w��czony. */
    bool enableZBuffer;
    /** Flaga okre�laj�ca, czy widok ortogonalny jest aktywowany. */
    bool orthogonalView;
    /** Flaga informuj�ca, czy ma by� wykorzystany model Warna do o�wietlenia(latarka). */
    bool ifWarnModel;
    /** Macierz projekcji. */
    glm::mat4 projectionMatrix;
    /** Wsp�czynnik si�y �wiat�a ambientowego. */
    float ambientStrength;
    /** Wsp�czynnik si�y �wiat�a spekularnego. */
    float specularStrength;
    /** Wsp�czynnik rozproszenia �wiat�a wyk�adnikiem. */
    int scatterStrength;
    /** Wsp�czynnik wzmocnienia koloru obiekt�w. */
    float boostColor;
    /** Pozycja �wiat�a w przestrzeni 3D. */
    glm::vec3 lightPos;
    /** K�t odci�cia dla modelu Warna. */
    float angleWarnCutOff;
    /** Intensywno�� wygaszenia na granicy o�wietlenia dla modelu Warna. */
    float intensityWarn;
public:
    /**
     * Konstruktor klasy Renderer.
     * @param readManager Wska�nik na obiekt zarz�dzaj�cy obiektami do renderowania.
     * @param readClearColor Kolor t�a (domy�lnie czarny).
     * @param readZBuffer Flaga w��czaj�ca z-buffer.
     * @param shouldOrthogonal Flaga decyduj�ca o widoku ortogonalnym.
     */
    Renderer(ObjectManager* readManager, glm::vec3 readClearColor = { 0, 0, 0 }, bool readZBuffer = true, bool shouldOrthogonal = true);
    /** Statyczna funkcja renderuj�ca scen�. */
    static void render();
    /**
     * Ustawia kolor t�a.
     * @param readClearColor Kolor t�a.
     */
    void setClearColor(glm::vec3 readClearColor);
    /**
     * Zwraca kolor t�a.
     * @return Kolor t�a.
     */
    glm::vec3 getClearColor();
    /**
     * Ustawia flag� w��czenia z-bufferu.
     * @param readShould Flaga w��czaj�ca z-buffer.
     */
    void setZBuffer(bool readShould);
    /**
     * Zwraca flag�, czy z-buffer jest w��czony.
     * @return Flaga z-bufferu.
     */
    bool getZBuffer();
    /**
     * Zwraca flag�, czy widok ortogonalny jest w��czony.
     * @return Flaga widoku ortogonalnego.
     */
    bool getOrthogonal();
    /**
     * Ustawia flag� dla widoku ortogonalnego.
     * @param shouldOrthogonal Flaga aktywuj�ca widok ortogonalny.
     */
    void setOrthogonal(bool shouldOrthogonal);
    /**
     * Zwraca wska�nik na mened�era obiekt�w.
     * @return Wska�nik na mened�era obiekt�w.
     */
    ObjectManager* getManager();
    /**
     * Zast�puje bie��cego mened�era obiekt�w.
     * @param readManager Nowy mened�er obiekt�w.
     */
    void replaceManager(ObjectManager* readManager);
    /** Konfiguruje shadery do renderowania. */
    void setUpShaders();
    /**
     * Zwraca wska�nik na aktualnie u�ywany obiekt do obs�ugiwania shader�w.
     * @return Wska�nik na obiekt do obs�ugiwania shader�w.
     */
    Shader* getShader();
    /**
     * Ustawia pozycj� �wiat�a w przestrzeni.
     * @param readLighting Nowa pozycja �wiat�a.
     */
    void setLightingPos(glm::vec3 readLighting);
    /**
     * Zwraca pozycj� �wiat�a.
     * @return Pozycja �wiat�a w przestrzeni.
     */
    glm::vec3 getLightingPos();
    /**
     * Ustawia si�� �wiat�a ambientowego.
     * @param readStrength Nowa si�a �wiat�a ambientowego.
     */
    void setAmbientStrength(float readStrength);
    /**
     * Zwraca si�� �wiat�a ambientowego.
     * @return Si�a �wiat�a ambientowego.
     */
    float getAmbientStrength();
    /**
     * Ustawia si�� �wiat�a spekularnego.
     * @param readStrength Nowa si�a �wiat�a spekularnego.
     */
    void setSpecularStrength(float readStrength);
    /**
     * Zwraca si�� �wiat�a spekularnego.
     * @return Si�a �wiat�a spekularnego.
     */
    float getSpecularStrength();
    /**
     * Ustawia si�� rozproszenia �wiat�a.
     * @param readStrength Nowa si�a rozproszenia �wiat�a.
     */
    void setScatterStrength(int readStrength);
    /**
     * Zwraca si�� rozproszenia �wiat�a.
     * @return Si�a rozproszenia �wiat�a.
     */
    int getScatterStrength();
    /**
     * Ustawia wsp�czynnik wzmocnienia koloru obiekt�w.
     * @param readBoost Nowy wsp�czynnik wzmocnienia koloru.
     */
    void setBoostColor(float readBoost);
    /**
     * Zwraca wsp�czynnik wzmocnienia koloru obiekt�w.
     * @return Wsp�czynnik wzmocnienia koloru.
     */
    float getBoostColor();
    /** Prze��cza tryb renderowania z p�askim cieniowaniem. */
    void toggleIfFlatShading();
    /**
     * Zwraca czy jest u�ywany model Warna.
     * @return Flaga czy jest u�ywany model Warna.
     */
    bool getWarnModel();
    /**
     * Ustawia flag� czy jest u�ywany model Warna.
     * @param readIfWarn Nowa flaga czy jest u�ywany model Warna.
     */
    void setWarnModel(bool readIfWarn);
    /**
     * Ustawia k�t odci�cia dla modelu Warna.
     * @param readCutOff K�t odci�cia dla modelu Warna.
     */
    void setWarnCutOff(float readCutOff);
    /**
     * Zwraca k�t odci�cia dla modelu Warna.
     * @return K�t odci�cia dla modelu Warna.
     */
    float getWarnCutOff();
    /**
     * Ustawia intensywno�� dla modelu Warna.
     * @param readIntensity Intensywno�� dla modelu Warna.
     */
    void setWarnIntensity(float readIntensity);
    /**
     * Zwraca intensywno�� dla modelu Warna.
     * @return Intensywno�� dla modelu Warna.
     */
    float getWarnIntensity();
};
