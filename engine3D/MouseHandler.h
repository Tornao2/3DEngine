#pragma once
#include "Observer.h"
#include "KeyboardHandler.h"

/**
 * @enum mouseButtons
 * Enum reprezentuj¹cy przyciski myszy.
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
 * Klasa odpowiedzialna za zarz¹dzanie stanem przycisków myszy oraz obs³ugê zdarzeñ zwi¹zanych z mysz¹.
 */
class MouseHandler {
private:
    /** WskaŸnik do obiektu kamery, który mo¿e zostaæ zmieniony przez interakcjê z mysz¹ */
    Observer* camera = nullptr;
    /** Statyczna instancja klasy MouseHandler */
    static MouseHandler* instance;
    /** Tablica przechowuj¹ca stany przycisków myszy */
    KeyStates buttonStates[3] = { notClicked };
    /** Tablica informuj¹ca, czy dany przycisk wymaga odœwie¿enia co klatkê */
    bool ifButtonsRefresh[3] = { true };
    /** Tablica wskazuj¹ca, czy przycisk zosta³ naciœniêty w danej klatce */
    bool ifPressedOnThisFrame[3] = { false };
    /**
     * Funkcja obs³uguj¹ca naciœniêcie lub puszczenie przycisku myszy.
     * @param readButton Przycisk myszy, który zosta³ naciœniêty lub puszczony.
     * @param readState Stan przycisku myszy.
     * @param readX Pozycja X kursora w momencie naciœniêcia lub puszczenia przycisku.
     * @param readY Pozycja Y kursora w momencie naciœniêcia lub puszczenia przycisku.
     */
    void buttonHandleProper(int readButton, int readState, int readX, int readY);
public:
    /** Konstruktor domyœlny klasy MouseHandler */
    MouseHandler();
    /**
     * Funkcja odœwie¿aj¹ca stan przycisków myszy.
     */
    void refresh();
    /**
     * Funkcja ustalaj¹ca, czy dany przycisk myszy ma zostaæ odœwie¿ony co klatkê.
     * @param readButton Przycisk myszy, dla którego ma zostaæ ustawiona flaga.
     * @param readShould Nowa wartoœæ flagi.
     */
    void setIfShouldRefresh(unsigned char readButton, bool readShould);
    /**
     * Funkcja zwracaj¹ca, czy dany przycisk myszy ma byæ odœwie¿any.
     * @param readButton Przycisk myszy, dla którego sprawdzamy flagê odœwie¿ania.
     * @return Flaga informuj¹ca, czy przycisk jest odœwie¿any co klatkê.
     */
    bool getIfShouldRefresh(unsigned char readButton);
    /**
     * Funkcja wywo³ywana przy naciœniêciu lub puszczeniu przycisku myszy.
     * @param readButton Przycisk myszy, który zosta³ naciœniêty lub puszczony.
     * @param readState Stan przycisku.
     * @param readX Pozycja X kursora w momencie naciœniêcia lub puszczenia przycisku.
     * @param readY Pozycja Y kursora w momencie naciœniêcia lub puszczenia przycisku.
     */
    void static buttonHandle(int readButton, int readState, int readX, int readY);
    /**
     * Funkcja sprawdzaj¹ca, czy dany przycisk myszy jest wciœniêty.
     * @param readButton Przycisk myszy, który chcemy sprawdziæ.
     * @return Flaga wskazuj¹ca, czy przycisk jest wciœniêty.
     */
    bool checkIfPressed(unsigned char readButton);
    /**
     * Funkcja callback dla zdarzeñ myszy, wywo³ywana przy ruchu myszy.
     * @param readX Pozycja X kursora w momencie ruchu.
     * @param readY Pozycja Y kursora w momencie ruchu.
     */
    static void mouseCallback(int readX, int readY);
    /**
     * Funkcja zwracaj¹ca wskaŸnik do obiektu kamery, któr¹ kontroluje mysz.
     * @return WskaŸnik do obiektu kamery.
     */
    Observer* getCamera();
    /**
     * Funkcja ustawiaj¹ca obiekt kamery, któr¹ kontroluje mysz.
     * @param readCamera WskaŸnik do obiektu kamery, który ma byæ ustawiony.
     */
    void setCamera(Observer* readCamera);
};
