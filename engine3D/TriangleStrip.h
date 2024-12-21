#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class TriangleStrip
 *  Klasa reprezentuj�ca paski tr�jk�t�w.
 */
class TriangleStrip : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt paska tr�jk�t�w.
     * @param readData Dane reprezentuj�ce pasek tr�jk�t�w.
     */
    TriangleStrip(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj�ca pasek tr�jk�t�w wykorzystuj�c funkcj� glDrawArrays.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj�ca nowy punkt do paska tr�jk�t�w.
     * @param readPoint Nowy punkt do dodania.
     * @param index Numer miejsca, w kt�rym punkt ma zosta� dodany.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj�ca punkt z paska tr�jk�t�w.
     * @param index Numer punktu do usuni�cia.
     */
    void removePoint(int index);
};
