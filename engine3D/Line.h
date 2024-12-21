#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class Line
 *  Klasa reprezentuj¹ca liniê.
 */
class Line : public DirectDraw, public Resizable, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt linii.
     * @param readData Dane reprezentuj¹ce liniê.
     * @param readSize Szerokoœæ linii.
     */
    Line(std::vector<glm::vec4> readData, float readSize);
    /**
     * Funkcja rysuj¹ca liniê, wykorzystuje OpenGL do narysowania linii, wywo³uj¹c funkcjê glDrawArrays.
     * @param index Numer pierwszego wierzcho³ka danej figury w buferze.
     */
    void drawDirect(int index);
};
