#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class Quads
 *  Klasa reprezentuj¹ca czworok¹ty.
 */
class Quads : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt czworok¹ta.
     * @param readData Dane reprezentuj¹ce czworok¹ty.
     */
    Quads(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj¹ca czworok¹t wykorzystuj¹ca glDrawArrays.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
};
