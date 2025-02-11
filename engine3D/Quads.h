#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class Quads
 *  Klasa reprezentująca czworokąty.
 */
class Quads : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworzący obiekt czworokąta.
     * @param readData Dane reprezentujące czworokąty.
     */
    Quads(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysująca czworokąt wykorzystująca glDrawArrays.
     * @param index Numer pierwszego wierzchołka w buferze.
     */
    void drawDirect(int index);
};
