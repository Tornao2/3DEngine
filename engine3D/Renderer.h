#pragma once
#include "ObjectManager.h"
#include <glm/gtc/type_ptr.hpp>

/**
 * @class Renderer
 * Klasa odpowiedzialna za renderowanie progrmau.
 */
class Renderer {
private:
    /** Funkcja wykonuj¹ca w³aœciwe renderowanie. */
    void renderProper();
    /** Statyczny wskaŸnik na instancjê klasy Renderer. */
    static Renderer* instance;
    /** WskaŸnik na mened¿era obiektów do renderowania. */
    ObjectManager* manager;
    /** WskaŸnik na obiekt obs³uguj¹cy shadery. */
    Shader* shader;
    /** Kolor t³a, który zostanie u¿yty przy czyszczeniu ekranu. */
    glm::vec3 clearColor;
    /** Flaga okreœlaj¹ca, czy z-buffer jest w³¹czony. */
    bool enableZBuffer;
    /** Flaga okreœlaj¹ca, czy widok ortogonalny jest aktywowany. */
    bool orthogonalView;
    /** Flaga informuj¹ca, czy ma byæ wykorzystany model Warna do oœwietlenia(latarka). */
    bool ifWarnModel;
    /** Macierz projekcji. */
    glm::mat4 projectionMatrix;
    /** Wspó³czynnik si³y œwiat³a ambientowego. */
    float ambientStrength;
    /** Wspó³czynnik si³y œwiat³a spekularnego. */
    float specularStrength;
    /** Wspó³czynnik rozproszenia œwiat³a wyk³adnikiem. */
    int scatterStrength;
    /** Wspó³czynnik wzmocnienia koloru obiektów. */
    float boostColor;
    /** Pozycja œwiat³a w przestrzeni 3D. */
    glm::vec3 lightPos;
    /** K¹t odciêcia dla modelu Warna. */
    float angleWarnCutOff;
    /** Intensywnoœæ wygaszenia na granicy oœwietlenia dla modelu Warna. */
    float intensityWarn;
public:
    /**
     * Konstruktor klasy Renderer.
     * @param readManager WskaŸnik na obiekt zarz¹dzaj¹cy obiektami do renderowania.
     * @param readClearColor Kolor t³a (domyœlnie czarny).
     * @param readZBuffer Flaga w³¹czaj¹ca z-buffer.
     * @param shouldOrthogonal Flaga decyduj¹ca o widoku ortogonalnym.
     */
    Renderer(ObjectManager* readManager, glm::vec3 readClearColor = { 0, 0, 0 }, bool readZBuffer = true, bool shouldOrthogonal = true);
    /** Statyczna funkcja renderuj¹ca scenê. */
    static void render();
    /**
     * Ustawia kolor t³a.
     * @param readClearColor Kolor t³a.
     */
    void setClearColor(glm::vec3 readClearColor);
    /**
     * Zwraca kolor t³a.
     * @return Kolor t³a.
     */
    glm::vec3 getClearColor();
    /**
     * Ustawia flagê w³¹czenia z-bufferu.
     * @param readShould Flaga w³¹czaj¹ca z-buffer.
     */
    void setZBuffer(bool readShould);
    /**
     * Zwraca flagê, czy z-buffer jest w³¹czony.
     * @return Flaga z-bufferu.
     */
    bool getZBuffer();
    /**
     * Zwraca flagê, czy widok ortogonalny jest w³¹czony.
     * @return Flaga widoku ortogonalnego.
     */
    bool getOrthogonal();
    /**
     * Ustawia flagê dla widoku ortogonalnego.
     * @param shouldOrthogonal Flaga aktywuj¹ca widok ortogonalny.
     */
    void setOrthogonal(bool shouldOrthogonal);
    /**
     * Zwraca wskaŸnik na mened¿era obiektów.
     * @return WskaŸnik na mened¿era obiektów.
     */
    ObjectManager* getManager();
    /**
     * Zastêpuje bie¿¹cego mened¿era obiektów.
     * @param readManager Nowy mened¿er obiektów.
     */
    void replaceManager(ObjectManager* readManager);
    /** Konfiguruje shadery do renderowania. */
    void setUpShaders();
    /**
     * Zwraca wskaŸnik na aktualnie u¿ywany obiekt do obs³ugiwania shaderów.
     * @return WskaŸnik na obiekt do obs³ugiwania shaderów.
     */
    Shader* getShader();
    /**
     * Ustawia pozycjê œwiat³a w przestrzeni.
     * @param readLighting Nowa pozycja œwiat³a.
     */
    void setLightingPos(glm::vec3 readLighting);
    /**
     * Zwraca pozycjê œwiat³a.
     * @return Pozycja œwiat³a w przestrzeni.
     */
    glm::vec3 getLightingPos();
    /**
     * Ustawia si³ê œwiat³a ambientowego.
     * @param readStrength Nowa si³a œwiat³a ambientowego.
     */
    void setAmbientStrength(float readStrength);
    /**
     * Zwraca si³ê œwiat³a ambientowego.
     * @return Si³a œwiat³a ambientowego.
     */
    float getAmbientStrength();
    /**
     * Ustawia si³ê œwiat³a spekularnego.
     * @param readStrength Nowa si³a œwiat³a spekularnego.
     */
    void setSpecularStrength(float readStrength);
    /**
     * Zwraca si³ê œwiat³a spekularnego.
     * @return Si³a œwiat³a spekularnego.
     */
    float getSpecularStrength();
    /**
     * Ustawia si³ê rozproszenia œwiat³a.
     * @param readStrength Nowa si³a rozproszenia œwiat³a.
     */
    void setScatterStrength(int readStrength);
    /**
     * Zwraca si³ê rozproszenia œwiat³a.
     * @return Si³a rozproszenia œwiat³a.
     */
    int getScatterStrength();
    /**
     * Ustawia wspó³czynnik wzmocnienia koloru obiektów.
     * @param readBoost Nowy wspó³czynnik wzmocnienia koloru.
     */
    void setBoostColor(float readBoost);
    /**
     * Zwraca wspó³czynnik wzmocnienia koloru obiektów.
     * @return Wspó³czynnik wzmocnienia koloru.
     */
    float getBoostColor();
    /** Prze³¹cza tryb renderowania z p³askim cieniowaniem. */
    void toggleIfFlatShading();
    /**
     * Zwraca czy jest u¿ywany model Warna.
     * @return Flaga czy jest u¿ywany model Warna.
     */
    bool getWarnModel();
    /**
     * Ustawia flagê czy jest u¿ywany model Warna.
     * @param readIfWarn Nowa flaga czy jest u¿ywany model Warna.
     */
    void setWarnModel(bool readIfWarn);
    /**
     * Ustawia k¹t odciêcia dla modelu Warna.
     * @param readCutOff K¹t odciêcia dla modelu Warna.
     */
    void setWarnCutOff(float readCutOff);
    /**
     * Zwraca k¹t odciêcia dla modelu Warna.
     * @return K¹t odciêcia dla modelu Warna.
     */
    float getWarnCutOff();
    /**
     * Ustawia intensywnoœæ dla modelu Warna.
     * @param readIntensity Intensywnoœæ dla modelu Warna.
     */
    void setWarnIntensity(float readIntensity);
    /**
     * Zwraca intensywnoœæ dla modelu Warna.
     * @return Intensywnoœæ dla modelu Warna.
     */
    float getWarnIntensity();
};
