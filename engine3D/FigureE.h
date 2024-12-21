#pragma once
#include "IndiceDraw.h"

/** @class FigureE
 *  Klasa reprezentuj¹ca obiekt 3D litery E.
 */
class FigureE : public IndiceDraw {
public:
    /**
     * Konstruktor tworz¹cy obiekt FigureE.
     * @param readSideLength Maksymalna d³ugoœæ boku figury.
     * @param readX Pozycja figury w osi X.
     * @param readY Pozycja figury w osi Y.
     * @param readZ Pozycja figury w osi Z.
     * @param readColors Kolory przypisane do figury.
     */
    FigureE(float readSideLength, float readX, float readY, float readZ, std::vector<glm::vec4> readColors);
};
