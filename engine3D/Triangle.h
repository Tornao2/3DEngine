#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class Triangle
 *  Klasa reprezentuj¹ca trójk¹t.
 */
class Triangle : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt trójk¹ta.
     * @param readData Dane reprezentuj¹ce trójk¹t.
     */
    Triangle(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj¹ca trójk¹t wykorzystuj¹c funkcjê glDrawArrays.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
};
