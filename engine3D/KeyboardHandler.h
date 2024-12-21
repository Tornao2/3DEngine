#pragma once
#include <GL/freeglut_std.h>

/**
 * @enum KeyStates
 * Enum zawieraj�cy stany przycisk�w na klawiaturze.
 */
typedef enum KeyStates {
    /** Przyciski, kt�re nie zosta�y naci�ni�te */
    notClicked,
    /** Przyciski, kt�re maj� zosta� usuni�te w przysz�o�ci */
    removeInFuture,
    /** Przyciski, kt�re s� aktualnie naciskane */
    pressing
} KeyStates;

/**
 * @class KeyboardHandler
 * Klasa odpowiedzialna za zarz�dzanie stanem klawiatury.
 */
class KeyboardHandler {
private:
    /** Statyczna instancja klasy KeyboardHandler */
    static KeyboardHandler* instance;
    /** Tablica przechowuj�ca stany klawiszy  */
    KeyStates keyStates[256] = { notClicked };
    /** Tablica informuj�ca, czy klawisz powinien by� od�wie�any co ka�d� klatk� */
    bool ifKeyRefresh[256] = { false };
    /** Tablica wskazuj�ca, czy klawisz zosta� naci�ni�ty w danej klatce */
    bool ifKeyPressedThisFrame[256];
    /**
     * Prawdziwa funkcja odpowiedzialna za obs�ug� naci�ni�cia klawisza.
     * @param readKey Klawisz, kt�ry zosta� naci�ni�ty.
     * @param readX Pozycja X kursora myszy w momencie naci�ni�cia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie naci�ni�cia klawisza.
     */
    void keyDownProper(unsigned char readKey, int readX, int readY);
    /**
     * Prawdziwa funkcja odpowiedzialna za obs�ug� puszczenia klawisza.
     * @param readKey Klawisz, kt�ry zosta� puszczony.
     * @param readX Pozycja X kursora myszy w momencie puszczenia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie puszczenia klawisza.
     */
    void keyUpProper(unsigned char readKey, int readX, int readY);
public:
    /** Konstruktor domy�lny klasy KeyboardHandler */
    KeyboardHandler();
    /**
     * Funkcja od�wie�aj�ca stan klawiatury.
     */
    void refresh();
    /**
     * Funkcja ustalaj�ca, czy dany klawisz ma by� od�wie�any co ka�d� klamk�.
     * @param readKey Klawisz, dla kt�rego ma zosta� ustawiona flaga.
     * @param readShould Nowa warto�� flagi.
     */
    void setIfShouldRefresh(unsigned char readKey, bool readShould);
    /**
     * Funkcja zwracaj�ca, czy dany klawisz ma by� od�wie�any.
     * @param readKey Klawisz, dla kt�rego sprawdzamy flag� od�wie�enia.
     * @return Flaga informuj�ca, czy klawisz wymaga od�wie�enia.
     */
    bool getIfShouldRefresh(unsigned char readKey);
    /**
     * Funkcja przekierowywuj�ca do prawdziwej wywo�ywana przy naci�ni�ciu klawisza.
     * @param readKey Klawisz, kt�ry zosta� naci�ni�ty.
     * @param readX Pozycja X kursora myszy w momencie naci�ni�cia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie naci�ni�cia klawisza.
     */
    void static keyDown(unsigned char readKey, int readX, int readY);
    /**
     * Funkcja przekierowywuj�ca do prawdziwej wywo�ywana przy puszczeniu klawisza.
     * @param readKey Klawisz, kt�ry zosta� puszczony.
     * @param readX Pozycja X kursora myszy w momencie puszczenia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie puszczenia klawisza.
     */
    void static keyUp(unsigned char readKey, int readX, int readY);
    /**
     * Funkcja sprawdzaj�ca, czy dany klawisz jest wci�ni�ty.
     * @param readKey Klawisz, kt�ry chcemy sprawdzi�.
     * @return Flaga wskazuj�ca, czy klawisz jest wci�ni�ty.
     */
    bool checkIfPressed(unsigned char readKey);
};
