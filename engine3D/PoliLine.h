#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class PoliLine
 *  Klasa reprezentuj¹ca polilinie.
 */
class PoliLine : public DirectDraw, public Resizable, public TransformableFigure {
private:
    /** Flaga wskazuj¹ca, czy polilinia jest zamkniêta */
    bool closed;
public:
    /**
     * Konstruktor tworz¹cy obiekt polilinii.
     * @param readData Dane reprezentuj¹ce poliliniê.
     * @param readSize Szerokoœæ polilinii.
     * @param readClosed Flaga wskazuj¹ca, czy polilinia jest zamkniêta.
     */
    PoliLine(std::vector<glm::vec4> readData, float readSize, bool readClosed);
    /**
     * Funkcja rysuj¹ca poliliniê, wykorzystuje OpenGL.
     * @param index Numer pierwszego wierzcho³ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj¹ca punkt do polilinii.
     * @param readPoint Dane punktu do dodania.
     * @param index Indeks, w którym ma byæ dodany punkt.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj¹ca punkt z polilinii.
     * @param index Indeks punktu do usuniêcia.
     */
    void removePoint(int index);
    /**
     * Funkcja zwracaj¹ca informacjê, czy polilinia jest zamkniêta.
     * @return True, jeœli polilinia jest zamkniêta, w przeciwnym razie false.
     */
    bool getIfClosed();
    /**
     * Funkcja ustawiaj¹ca, czy polilinia ma byæ zamkniêta.
     * @param readClosed Flaga, która okreœla, czy polilinia ma byæ zamkniêta.
     */
    void setIfClosed(bool readClosed);
};
