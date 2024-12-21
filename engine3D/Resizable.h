#pragma once

/** @class Resizable
 *  Klasa bazowa umo¿liwiaj¹ca manipulacjê pewnymi wymiarami(szerokoœæ linii, punktu) obiektów.
 */
class Resizable {
protected:
    /** Dany rozmiar obiektu */
    float size;
public:
    /**
     * Funkcja zwracaj¹ca dany rozmiar obiektu.
     * @return Wartoœæ danego rozmiaru obiektu.
     */
    float getSize();
    /**
     * Funkcja ustawiaj¹ca dany rozmiar obiektu.
     * @param readSize Nowa wartoœæ danego rozmiaru obiektu.
     */
    void setSize(float readSize);
};
