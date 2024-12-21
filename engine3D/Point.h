#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class Point
 *  Klasa reprezentuj�ca punkt.
 */
class Point : public DirectDraw, public Resizable, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt punktu.
     * @param readData Dane reprezentuj�ce punkt.
     * @param readSize Rozmiar punktu.
     */
    Point(std::vector<glm::vec4> readData, float readSize);
    /**
     * Funkcja rysuj�ca punkt, wykorzystuje OpenGL.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
};
