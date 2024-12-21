#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class Triangle
 *  Klasa reprezentuj�ca tr�jk�t.
 */
class Triangle : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt tr�jk�ta.
     * @param readData Dane reprezentuj�ce tr�jk�t.
     */
    Triangle(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj�ca tr�jk�t wykorzystuj�c funkcj� glDrawArrays.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
};
