#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class Quads
 *  Klasa reprezentuj�ca czworok�ty.
 */
class Quads : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt czworok�ta.
     * @param readData Dane reprezentuj�ce czworok�ty.
     */
    Quads(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj�ca czworok�t wykorzystuj�ca glDrawArrays.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
};
