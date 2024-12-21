#pragma once
#include "ShaderHandler.h"
#include <glm/gtc/type_ptr.hpp>

/** @class Observer
 *  Klasa kamery silnika
 */
class Observer {
protected:
    /** Obiekt zajmuj�cy si� shaderami programu */
	Shader* shader;
    /** Macierz widoku */
	glm::mat4 viewMatrix;
    /** Pozycja kamery */
	glm::vec3 cameraPos;
    /** Kierunek w kt�rym si� patrzy kamera */
	glm::vec3 target;
    /** Wektor m�wi�cy kt�ry kierunek jest uznawany za g�r� */
	glm::vec3 up;
    /** X podczas ostatniego wykonania funkcji obracaj�cej widok */
    float lastX;
    /** Y podczas ostatniego wykonania funkcji obracaj�cej widok */
    float lastY;
    /** K�t odchylenia kamery */
    float yaw;
    /** K�t nachylenia kamery */
    float pitch;
public:
    /**
    * Konstruktor tworz�cy kamer�.
    * @param readHandler Wska�nik na obiekt zajmuj�cy si� shaderami programu.
    */
    Observer(Shader* readHandler);
    /**
     * Funkcja aktualizuj�ca macierz widoku i wysy�aj�ca j� do u�ycia.
     */
    void updateCamera();
    /**
     * Funkcja zwracaj�ca wska�nik na obiekt shader�w programu.
     * @return Wska�nik na obiekt typu Shader.
     */
    Shader* getShader();
    /**
     * Funkcja zwracaj�ca macierz widoku kamery.
     * @return Macierz widoku typu glm::mat4.
     */
    glm::mat4 getviewMatrix();
    /**
     * Funkcja zwracaj�ca pozycj� kamery.
     * @return Wektor typu glm::vec3 reprezentuj�cy pozycj� kamery w przestrzeni 3D.
     */
    glm::vec3 getCameraPos();
    /**
     * Funkcja zwracaj�ca kierunek, w kt�rym patrzy kamera.
     * @return Wektor typu glm::vec3 reprezentuj�cy cel kamery.
     */
    glm::vec3 getTarget();
    /**
     * Funkcja zwracaj�ca wektor "g�ra" kamery.
     * @return Wektor typu glm::vec3 reprezentuj�cy wektor "g�ra".
     */
    glm::vec3 getUp();
    /**
     * Funkcja zwracaj�ca wsp�rz�dn� X z ostatniego pomiaru funkcji obracaj�cej widok.
     * @return Warto�� float reprezentuj�ca wsp�rz�dn� X ostatniego punktu.
     */
    float getLastX();
    /**
     * Funkcja zwracaj�ca wsp�rz�dn� Y z ostatniego pomiaru funkcji obracaj�cej widok.
     * @return Warto�� float reprezentuj�ca wsp�rz�dn� Y ostatniego punktu.
     */
    float getLastY();
    /**
     * Funkcja zwracaj�ca k�t odchylenia kamery.
     * @return Warto�� float reprezentuj�ca k�t odchylenia (yaw) kamery.
     */
    float getYaw();
    /**
     * Funkcja zwracaj�ca k�t nachylenia kamery.
     * @return Warto�� float reprezentuj�ca k�t nachylenia (pitch) kamery.
     */
    float getPitch();
    /**
     * Funkcja ustalaj�ca obiekt obs�ugi shader�w dla kamery.
     * @param readShader Wska�nik na nowy obiekt obs�ugi shader�w.
     */
    void setShader(Shader* readShader);
    /**
     * Funkcja ustalaj�ca now� macierz widoku kamery.
     * @param readMatrix Nowa macierz widoku typu glm::mat4.
     */
    void setviewMatrix(glm::mat4 readMatrix);
    /**
     * Funkcja ustalaj�ca now� pozycj� kamery.
     * @param readPos Nowa pozycja kamery typu glm::vec3.
     */
    void setCameraPos(glm::vec3 readPos);
    /**
     * Funkcja ustalaj�ca nowy cel kamery.
     * @param readTarget Nowy cel kamery typu glm::vec3.
     */
    void setTarget(glm::vec3 readTarget);
    /**
     * Funkcja ustalaj�ca nowy wektor "g�ra" kamery.
     * @param readUp Nowy wektor "g�ra" typu glm::vec3.
     */
    void setUp(glm::vec3 readUp);
    /**
     * Funkcja ustalaj�ca wsp�rz�dn� X z ostatniego pomiaru funkcji obracaj�cej widok.
     * @param readX Nowa warto�� wsp�rz�dnej X.
     */
    void setLastX(float readX);
    /**
     * Funkcja ustalaj�ca wsp�rz�dn� Y z ostatniego pomiaru funkcji obracaj�cej widok.
     * @param readY Nowa warto�� wsp�rz�dnej Y.
     */
    void setLastY(float readY);
    /**
     * Funkcja ustalaj�ca k�t odchylenia kamery.
     * @param readYaw Nowa warto�� k�ta odchylenia.
     */
    void setYaw(float readYaw);
    /**
     * Funkcja ustalaj�ca k�t nachylenia kamery.
     * @param readPitch Nowa warto�� k�ta nachylenia.
     */
    void setPitch(float readPitch);
};