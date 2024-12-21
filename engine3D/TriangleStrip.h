#pragma once
#include "DirectDraw.h"
#include "TransformableFigure.h"

/** @class TriangleStrip
 *  Klasa reprezentuj¹ca paski trójk¹tów.
 */
class TriangleStrip : public DirectDraw, public TransformableFigure {
public:
    /**
     * Konstruktor tworz¹cy obiekt paska trójk¹tów.
     * @param readData Dane reprezentuj¹ce pasek trójk¹tów.
     */
    TriangleStrip(std::vector<glm::vec4> readData);
    /**
     * Funkcja rysuj¹ca pasek trójk¹tów wykorzystuj¹c funkcjê glDrawArrays.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj¹ca nowy punkt do paska trójk¹tów.
     * @param readPoint Nowy punkt do dodania.
     * @param index Numer miejsca, w którym punkt ma zostaæ dodany.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj¹ca punkt z paska trójk¹tów.
     * @param index Numer punktu do usuniêcia.
     */
    void removePoint(int index);
};
