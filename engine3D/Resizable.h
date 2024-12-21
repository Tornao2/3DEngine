#pragma once

/** @class Resizable
 *  Klasa bazowa umo�liwiaj�ca manipulacj� pewnymi wymiarami(szeroko�� linii, punktu) obiekt�w.
 */
class Resizable {
protected:
    /** Dany rozmiar obiektu */
    float size;
public:
    /**
     * Funkcja zwracaj�ca dany rozmiar obiektu.
     * @return Warto�� danego rozmiaru obiektu.
     */
    float getSize();
    /**
     * Funkcja ustawiaj�ca dany rozmiar obiektu.
     * @param readSize Nowa warto�� danego rozmiaru obiektu.
     */
    void setSize(float readSize);
};
