#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class Line
 *  Klasa reprezentuj�ca lini�.
 */
class Line : public DirectDraw, public Resizable, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt linii.
     * @param readData Dane reprezentuj�ce lini�.
     * @param readSize Szeroko�� linii.
     */
    Line(std::vector<glm::vec4> readData, float readSize);
    /**
     * Funkcja rysuj�ca lini�, wykorzystuje OpenGL do narysowania linii, wywo�uj�c funkcj� glDrawArrays.
     * @param index Numer pierwszego wierzcho�ka danej figury w buferze.
     */
    void drawDirect(int index);
};
