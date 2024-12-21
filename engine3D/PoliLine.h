#pragma once
#include "DirectDraw.h"
#include "Resizable.h"
#include "TransformableFigure.h"

/** @class PoliLine
 *  Klasa reprezentuj�ca polilinie.
 */
class PoliLine : public DirectDraw, public Resizable, public TransformableFigure {
private:
    /** Flaga wskazuj�ca, czy polilinia jest zamkni�ta */
    bool closed;
public:
    /**
     * Konstruktor tworz�cy obiekt polilinii.
     * @param readData Dane reprezentuj�ce polilini�.
     * @param readSize Szeroko�� polilinii.
     * @param readClosed Flaga wskazuj�ca, czy polilinia jest zamkni�ta.
     */
    PoliLine(std::vector<glm::vec4> readData, float readSize, bool readClosed);
    /**
     * Funkcja rysuj�ca polilini�, wykorzystuje OpenGL.
     * @param index Numer pierwszego wierzcho�ka w buferze.
     */
    void drawDirect(int index);
    /**
     * Funkcja dodaj�ca punkt do polilinii.
     * @param readPoint Dane punktu do dodania.
     * @param index Indeks, w kt�rym ma by� dodany punkt.
     */
    void addPoint(std::vector<glm::vec4> readPoint, int index);
    /**
     * Funkcja usuwaj�ca punkt z polilinii.
     * @param index Indeks punktu do usuni�cia.
     */
    void removePoint(int index);
    /**
     * Funkcja zwracaj�ca informacj�, czy polilinia jest zamkni�ta.
     * @return True, je�li polilinia jest zamkni�ta, w przeciwnym razie false.
     */
    bool getIfClosed();
    /**
     * Funkcja ustawiaj�ca, czy polilinia ma by� zamkni�ta.
     * @param readClosed Flaga, kt�ra okre�la, czy polilinia ma by� zamkni�ta.
     */
    void setIfClosed(bool readClosed);
};
