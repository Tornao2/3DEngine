#pragma once
#include "Cube.h"
#include "Textured.h"

/** @class CubeTextured
 *  Klasa reprezentuj�ca sze�cian z tekstur�.
 */
class CubeTextured : public Cube, public Textured {
public:
    /**
     * Konstruktor tworz�cy obiekt sze�cianu z tekstur�.
     * @param readSideLength D�ugo�� boku sze�cianu.
     * @param readX Pozycja sze�cianu w osi X.
     * @param readY Pozycja sze�cianu w osi Y.
     * @param readZ Pozycja sze�cianu w osi Z.
     */
    CubeTextured(float readSideLength, float readX, float readY, float readZ);
};
