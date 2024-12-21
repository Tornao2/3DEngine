#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class Point
 *  Klasa reprezentuj¹ca punkt.
 */
class Point : public DirectDraw, public Resizable, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt punktu.
     * @param readData Dane reprezentuj¹ce punkt.
     * @param readSize Rozmiar punktu.
     */
    Point(std::vector<glm::vec4> readData, float readSize);
    /**
     * Funkcja rysuj¹ca punkt, wykorzystuje OpenGL.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
};
