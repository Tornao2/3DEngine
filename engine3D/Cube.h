#pragma once
#include "IndiceDraw.h"
#include "TransformableFigure.h"

/** @class Cube
 *  Klasa reprezentuj¹ca szeœcian.
 */
class Cube : public IndiceDraw, public TransformableFigure {
protected:
    /** D³ugoœæ boku szeœcianu */
    float sideLength;
    /** Pozycja szeœcianu w osi X */
    float x;
    /** Pozycja szeœcianu w osi Y */
    float y;
    /** Pozycja szeœcianu w osi Z */
    float z;
public:
    /**
     * Konstruktor tworz¹cy obiekt szeœcianu.
     * @param readSideLength D³ugoœæ boku szeœcianu.
     * @param readX Pozycja szeœcianu w osi X.
     * @param readY Pozycja szeœcianu w osi Y.
     * @param readZ Pozycja szeœcianu w osi Z.
     * @param readColors Kolory przypisane do figury szeœcianu.
     */
    Cube(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors = std::vector<glm::vec4>());
};
