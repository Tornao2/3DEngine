#pragma once
#include "Cube.h"

/** @class Player
 *  Klasa gracza
 */
class Player : public Cube {
protected:
    /** Statyczna instancja gracza */
    static Player* instance;
    /** Prêdkoœæ gracza w osi X */
    float msX;
    /** Prêdkoœæ gracza w osi Y */
    float msY;
    /** Prêdkoœæ gracza w osi Z */
    float msZ;
public:
    /**
     * Konstruktor tworz¹cy obiekt gracza.
     * @param readSideLength D³ugoœæ boku gracza.
     * @param readX Pozycja gracza w osi X.
     * @param readY Pozycja gracza w osi Y.
     * @param readZ Pozycja gracza w osi Z.
     * @param readColors Kolory, które bêd¹ przypisane do figury gracza.
     */
    Player(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors);
    /**
     * Funkcja ustalaj¹ca prêdkoœæ gracza w osi X.
     * @param readMs Nowa wartoœæ prêdkoœci gracza w osi X.
     */
    void setMsX(float readMs);
    /**
     * Funkcja ustalaj¹ca prêdkoœæ gracza w osi Y.
     * @param readMs Nowa wartoœæ prêdkoœci gracza w osi Y.
     */
    void setMsY(float readMs);
    /**
     * Funkcja ustalaj¹ca prêdkoœæ gracza w osi Z.
     * @param readMs Nowa wartoœæ prêdkoœci gracza w osi Z.
     */
    void setMsZ(float readMs);
    /**
     * Funkcja zwracaj¹ca prêdkoœæ gracza w osi X.
     * @return Wartoœæ prêdkoœci gracza w osi X.
     */
    float getMsX();
    /**
     * Funkcja zwracaj¹ca prêdkoœæ gracza w osi Y.
     * @return Wartoœæ prêdkoœci gracza w osi Y.
     */
    float getMsY();
    /**
     * Funkcja zwracaj¹ca prêdkoœæ gracza w osi Z.
     * @return Wartoœæ prêdkoœci gracza w osi Z.
     */
    float getMsZ();
    /**
     * Statyczna funkcja poruszaj¹ca graczem na podstawie obecnych prêdkoœci i zeruj¹ca je po wykonaniu
     */
    static void move();
    /**
     * Funkcja zwracaj¹ca instancjê gracza.
     * @return WskaŸnik na instancjê gracza.
     */
    static Player* getInstance();
};
