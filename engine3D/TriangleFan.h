#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class TriangleFan
 *  Klasa reprezentuj¹ca trójk¹towy wachlarz.
 */
class TriangleFan : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt trójk¹towego wachlarza.
     * @param readData Dane reprezentuj¹ce trójk¹towy wachlarz.
     */
    TriangleFan(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj¹ca trójk¹towy wachlarz wykorzystuj¹c funkcjê glDrawArrays.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj¹ca nowy punkt do trójk¹towego wachlarza.
     * @param readPoint Nowy punkt do dodania.
     * @param index Numer miejsca, w którym punkt ma zostaæ dodany.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj¹ca punkt z trójk¹towego wachlarza.
     * @param index Numer punktu do usuniêcia.
     */
    void removePoint(int index);
};
