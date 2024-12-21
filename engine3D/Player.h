#pragma once
#include "Cube.h"

/** @class Player
 *  Klasa gracza
 */
class Player : public Cube {
protected:
    /** Statyczna instancja gracza */
    static Player* instance;
    /** Pr�dko�� gracza w osi X */
    float msX;
    /** Pr�dko�� gracza w osi Y */
    float msY;
    /** Pr�dko�� gracza w osi Z */
    float msZ;
public:
    /**
     * Konstruktor tworz�cy obiekt gracza.
     * @param readSideLength D�ugo�� boku gracza.
     * @param readX Pozycja gracza w osi X.
     * @param readY Pozycja gracza w osi Y.
     * @param readZ Pozycja gracza w osi Z.
     * @param readColors Kolory, kt�re b�d� przypisane do figury gracza.
     */
    Player(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors);
    /**
     * Funkcja ustalaj�ca pr�dko�� gracza w osi X.
     * @param readMs Nowa warto�� pr�dko�ci gracza w osi X.
     */
    void setMsX(float readMs);
    /**
     * Funkcja ustalaj�ca pr�dko�� gracza w osi Y.
     * @param readMs Nowa warto�� pr�dko�ci gracza w osi Y.
     */
    void setMsY(float readMs);
    /**
     * Funkcja ustalaj�ca pr�dko�� gracza w osi Z.
     * @param readMs Nowa warto�� pr�dko�ci gracza w osi Z.
     */
    void setMsZ(float readMs);
    /**
     * Funkcja zwracaj�ca pr�dko�� gracza w osi X.
     * @return Warto�� pr�dko�ci gracza w osi X.
     */
    float getMsX();
    /**
     * Funkcja zwracaj�ca pr�dko�� gracza w osi Y.
     * @return Warto�� pr�dko�ci gracza w osi Y.
     */
    float getMsY();
    /**
     * Funkcja zwracaj�ca pr�dko�� gracza w osi Z.
     * @return Warto�� pr�dko�ci gracza w osi Z.
     */
    float getMsZ();
    /**
     * Statyczna funkcja poruszaj�ca graczem na podstawie obecnych pr�dko�ci i zeruj�ca je po wykonaniu
     */
    static void move();
    /**
     * Funkcja zwracaj�ca instancj� gracza.
     * @return Wska�nik na instancj� gracza.
     */
    static Player* getInstance();
};
