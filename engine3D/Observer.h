#pragma once
#include "ShaderHandler.h"
#include <glm/gtc/type_ptr.hpp>

/** @class Observer
 *  Klasa kamery silnika
 */
class Observer {
protected:
    /** Obiekt zajmuj¹cy siê shaderami programu */
	Shader* shader;
    /** Macierz widoku */
	glm::mat4 viewMatrix;
    /** Pozycja kamery */
	glm::vec3 cameraPos;
    /** Kierunek w którym siê patrzy kamera */
	glm::vec3 target;
    /** Wektor mówi¹cy który kierunek jest uznawany za górê */
	glm::vec3 up;
    /** X podczas ostatniego wykonania funkcji obracaj¹cej widok */
    float lastX;
    /** Y podczas ostatniego wykonania funkcji obracaj¹cej widok */
    float lastY;
    /** K¹t odchylenia kamery */
    float yaw;
    /** K¹t nachylenia kamery */
    float pitch;
public:
    /**
    * Konstruktor tworz¹cy kamerê.
    * @param readHandler WskaŸnik na obiekt zajmuj¹cy siê shaderami programu.
    */
    Observer(Shader* readHandler);
    /**
     * Funkcja aktualizuj¹ca macierz widoku i wysy³aj¹ca j¹ do u¿ycia.
     */
    void updateCamera();
    /**
     * Funkcja zwracaj¹ca wskaŸnik na obiekt shaderów programu.
     * @return WskaŸnik na obiekt typu Shader.
     */
    Shader* getShader();
    /**
     * Funkcja zwracaj¹ca macierz widoku kamery.
     * @return Macierz widoku typu glm::mat4.
     */
    glm::mat4 getviewMatrix();
    /**
     * Funkcja zwracaj¹ca pozycjê kamery.
     * @return Wektor typu glm::vec3 reprezentuj¹cy pozycjê kamery w przestrzeni 3D.
     */
    glm::vec3 getCameraPos();
    /**
     * Funkcja zwracaj¹ca kierunek, w którym patrzy kamera.
     * @return Wektor typu glm::vec3 reprezentuj¹cy cel kamery.
     */
    glm::vec3 getTarget();
    /**
     * Funkcja zwracaj¹ca wektor "góra" kamery.
     * @return Wektor typu glm::vec3 reprezentuj¹cy wektor "góra".
     */
    glm::vec3 getUp();
    /**
     * Funkcja zwracaj¹ca wspó³rzêdn¹ X z ostatniego pomiaru funkcji obracaj¹cej widok.
     * @return Wartoœæ float reprezentuj¹ca wspó³rzêdn¹ X ostatniego punktu.
     */
    float getLastX();
    /**
     * Funkcja zwracaj¹ca wspó³rzêdn¹ Y z ostatniego pomiaru funkcji obracaj¹cej widok.
     * @return Wartoœæ float reprezentuj¹ca wspó³rzêdn¹ Y ostatniego punktu.
     */
    float getLastY();
    /**
     * Funkcja zwracaj¹ca k¹t odchylenia kamery.
     * @return Wartoœæ float reprezentuj¹ca k¹t odchylenia (yaw) kamery.
     */
    float getYaw();
    /**
     * Funkcja zwracaj¹ca k¹t nachylenia kamery.
     * @return Wartoœæ float reprezentuj¹ca k¹t nachylenia (pitch) kamery.
     */
    float getPitch();
    /**
     * Funkcja ustalaj¹ca obiekt obs³ugi shaderów dla kamery.
     * @param readShader WskaŸnik na nowy obiekt obs³ugi shaderów.
     */
    void setShader(Shader* readShader);
    /**
     * Funkcja ustalaj¹ca now¹ macierz widoku kamery.
     * @param readMatrix Nowa macierz widoku typu glm::mat4.
     */
    void setviewMatrix(glm::mat4 readMatrix);
    /**
     * Funkcja ustalaj¹ca now¹ pozycjê kamery.
     * @param readPos Nowa pozycja kamery typu glm::vec3.
     */
    void setCameraPos(glm::vec3 readPos);
    /**
     * Funkcja ustalaj¹ca nowy cel kamery.
     * @param readTarget Nowy cel kamery typu glm::vec3.
     */
    void setTarget(glm::vec3 readTarget);
    /**
     * Funkcja ustalaj¹ca nowy wektor "góra" kamery.
     * @param readUp Nowy wektor "góra" typu glm::vec3.
     */
    void setUp(glm::vec3 readUp);
    /**
     * Funkcja ustalaj¹ca wspó³rzêdn¹ X z ostatniego pomiaru funkcji obracaj¹cej widok.
     * @param readX Nowa wartoœæ wspó³rzêdnej X.
     */
    void setLastX(float readX);
    /**
     * Funkcja ustalaj¹ca wspó³rzêdn¹ Y z ostatniego pomiaru funkcji obracaj¹cej widok.
     * @param readY Nowa wartoœæ wspó³rzêdnej Y.
     */
    void setLastY(float readY);
    /**
     * Funkcja ustalaj¹ca k¹t odchylenia kamery.
     * @param readYaw Nowa wartoœæ k¹ta odchylenia.
     */
    void setYaw(float readYaw);
    /**
     * Funkcja ustalaj¹ca k¹t nachylenia kamery.
     * @param readPitch Nowa wartoœæ k¹ta nachylenia.
     */
    void setPitch(float readPitch);
};