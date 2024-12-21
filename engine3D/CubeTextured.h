#pragma once
#include "Cube.h"
#include "Textured.h"

/** @class CubeTextured
 *  Klasa reprezentuj¹ca szeœcian z tekstur¹.
 */
class CubeTextured : public Cube, public Textured {
public:
    /**
     * Konstruktor tworz¹cy obiekt szeœcianu z tekstur¹.
     * @param readSideLength D³ugoœæ boku szeœcianu.
     * @param readX Pozycja szeœcianu w osi X.
     * @param readY Pozycja szeœcianu w osi Y.
     * @param readZ Pozycja szeœcianu w osi Z.
     */
    CubeTextured(float readSideLength, float readX, float readY, float readZ);
};
