#pragma once
#include "IndiceDraw.h"
#include "TransformableFigure.h"

/** @class Cube
 *  Klasa reprezentuj�ca sze�cian.
 */
class Cube : public IndiceDraw, public TransformableFigure {
protected:
    /** D�ugo�� boku sze�cianu */
    float sideLength;
    /** Pozycja sze�cianu w osi X */
    float x;
    /** Pozycja sze�cianu w osi Y */
    float y;
    /** Pozycja sze�cianu w osi Z */
    float z;
public:
    /**
     * Konstruktor tworz�cy obiekt sze�cianu.
     * @param readSideLength D�ugo�� boku sze�cianu.
     * @param readX Pozycja sze�cianu w osi X.
     * @param readY Pozycja sze�cianu w osi Y.
     * @param readZ Pozycja sze�cianu w osi Z.
     * @param readColors Kolory przypisane do figury sze�cianu.
     */
    Cube(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors = std::vector<glm::vec4>());
};
