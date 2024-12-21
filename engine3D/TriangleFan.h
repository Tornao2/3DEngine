#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class TriangleFan
 *  Klasa reprezentuj�ca tr�jk�towy wachlarz.
 */
class TriangleFan : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz�cy obiekt tr�jk�towego wachlarza.
     * @param readData Dane reprezentuj�ce tr�jk�towy wachlarz.
     */
    TriangleFan(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj�ca tr�jk�towy wachlarz wykorzystuj�c funkcj� glDrawArrays.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj�ca nowy punkt do tr�jk�towego wachlarza.
     * @param readPoint Nowy punkt do dodania.
     * @param index Numer miejsca, w kt�rym punkt ma zosta� dodany.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj�ca punkt z tr�jk�towego wachlarza.
     * @param index Numer punktu do usuni�cia.
     */
    void removePoint(int index);
};
