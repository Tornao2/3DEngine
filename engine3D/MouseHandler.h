#pragma once
#include "Observer.h"
#include "KeyboardHandler.h"

/**
 * @enum mouseButtons
 * Enum reprezentuj�cy przyciski myszy.
 */
typedef enum mouseButtons {
    /** Lewy przycisk myszy */
    leftButton = 0,
    /** Przycisk przewijania myszy */
    scrollButton,
    /** Prawy przycisk myszy */
    rightButton
} mouseButtons;

/**
 * @class MouseHandler
 * Klasa odpowiedzialna za zarz�dzanie stanem przycisk�w myszy oraz obs�ug� zdarze� zwi�zanych z mysz�.
 */
class MouseHandler {
private:
    /** Wska�nik do obiektu kamery, kt�ry mo�e zosta� zmieniony przez interakcj� z mysz� */
    Observer* camera = nullptr;
    /** Statyczna instancja klasy MouseHandler */
    static MouseHandler* instance;
    /** Tablica przechowuj�ca stany przycisk�w myszy */
    KeyStates buttonStates[3] = { notClicked };
    /** Tablica informuj�ca, czy dany przycisk wymaga od�wie�enia co klatk� */
    bool ifButtonsRefresh[3] = { true };
    /** Tablica wskazuj�ca, czy przycisk zosta� naci�ni�ty w danej klatce */
    bool ifPressedOnThisFrame[3] = { false };
    /**
     * Funkcja obs�uguj�ca naci�ni�cie lub puszczenie przycisku myszy.
     * @param readButton Przycisk myszy, kt�ry zosta� naci�ni�ty lub puszczony.
     * @param readState Stan przycisku myszy.
     * @param readX Pozycja X kursora w momencie naci�ni�cia lub puszczenia przycisku.
     * @param readY Pozycja Y kursora w momencie naci�ni�cia lub puszczenia przycisku.
     */
    void buttonHandleProper(int readButton, int readState, int readX, int readY);
public:
    /** Konstruktor domy�lny klasy MouseHandler */
    MouseHandler();
    /**
     * Funkcja od�wie�aj�ca stan przycisk�w myszy.
     */
    void refresh();
    /**
     * Funkcja ustalaj�ca, czy dany przycisk myszy ma zosta� od�wie�ony co klatk�.
     * @param readButton Przycisk myszy, dla kt�rego ma zosta� ustawiona flaga.
     * @param readShould Nowa warto�� flagi.
     */
    void setIfShouldRefresh(unsigned char readButton, bool readShould);
    /**
     * Funkcja zwracaj�ca, czy dany przycisk myszy ma by� od�wie�any.
     * @param readButton Przycisk myszy, dla kt�rego sprawdzamy flag� od�wie�ania.
     * @return Flaga informuj�ca, czy przycisk jest od�wie�any co klatk�.
     */
    bool getIfShouldRefresh(unsigned char readButton);
    /**
     * Funkcja wywo�ywana przy naci�ni�ciu lub puszczeniu przycisku myszy.
     * @param readButton Przycisk myszy, kt�ry zosta� naci�ni�ty lub puszczony.
     * @param readState Stan przycisku.
     * @param readX Pozycja X kursora w momencie naci�ni�cia lub puszczenia przycisku.
     * @param readY Pozycja Y kursora w momencie naci�ni�cia lub puszczenia przycisku.
     */
    void static buttonHandle(int readButton, int readState, int readX, int readY);
    /**
     * Funkcja sprawdzaj�ca, czy dany przycisk myszy jest wci�ni�ty.
     * @param readButton Przycisk myszy, kt�ry chcemy sprawdzi�.
     * @return Flaga wskazuj�ca, czy przycisk jest wci�ni�ty.
     */
    bool checkIfPressed(unsigned char readButton);
    /**
     * Funkcja callback dla zdarze� myszy, wywo�ywana przy ruchu myszy.
     * @param readX Pozycja X kursora w momencie ruchu.
     * @param readY Pozycja Y kursora w momencie ruchu.
     */
    static void mouseCallback(int readX, int readY);
    /**
     * Funkcja zwracaj�ca wska�nik do obiektu kamery, kt�r� kontroluje mysz.
     * @return Wska�nik do obiektu kamery.
     */
    Observer* getCamera();
    /**
     * Funkcja ustawiaj�ca obiekt kamery, kt�r� kontroluje mysz.
     * @param readCamera Wska�nik do obiektu kamery, kt�ry ma by� ustawiony.
     */
    void setCamera(Observer* readCamera);
};
