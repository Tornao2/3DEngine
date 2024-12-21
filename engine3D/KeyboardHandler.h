#pragma once
#include <GL/freeglut_std.h>

/**
 * @enum KeyStates
 * Enum zawieraj¹cy stany przycisków na klawiaturze.
 */
typedef enum KeyStates {
    /** Przyciski, które nie zosta³y naciœniête */
    notClicked,
    /** Przyciski, które maj¹ zostaæ usuniête w przysz³oœci */
    removeInFuture,
    /** Przyciski, które s¹ aktualnie naciskane */
    pressing
} KeyStates;

/**
 * @class KeyboardHandler
 * Klasa odpowiedzialna za zarz¹dzanie stanem klawiatury.
 */
class KeyboardHandler {
private:
    /** Statyczna instancja klasy KeyboardHandler */
    static KeyboardHandler* instance;
    /** Tablica przechowuj¹ca stany klawiszy  */
    KeyStates keyStates[256] = { notClicked };
    /** Tablica informuj¹ca, czy klawisz powinien byæ odœwie¿any co ka¿d¹ klatkê */
    bool ifKeyRefresh[256] = { false };
    /** Tablica wskazuj¹ca, czy klawisz zosta³ naciœniêty w danej klatce */
    bool ifKeyPressedThisFrame[256];
    /**
     * Prawdziwa funkcja odpowiedzialna za obs³ugê naciœniêcia klawisza.
     * @param readKey Klawisz, który zosta³ naciœniêty.
     * @param readX Pozycja X kursora myszy w momencie naciœniêcia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie naciœniêcia klawisza.
     */
    void keyDownProper(unsigned char readKey, int readX, int readY);
    /**
     * Prawdziwa funkcja odpowiedzialna za obs³ugê puszczenia klawisza.
     * @param readKey Klawisz, który zosta³ puszczony.
     * @param readX Pozycja X kursora myszy w momencie puszczenia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie puszczenia klawisza.
     */
    void keyUpProper(unsigned char readKey, int readX, int readY);
public:
    /** Konstruktor domyœlny klasy KeyboardHandler */
    KeyboardHandler();
    /**
     * Funkcja odœwie¿aj¹ca stan klawiatury.
     */
    void refresh();
    /**
     * Funkcja ustalaj¹ca, czy dany klawisz ma byæ odœwie¿any co ka¿d¹ klamkê.
     * @param readKey Klawisz, dla którego ma zostaæ ustawiona flaga.
     * @param readShould Nowa wartoœæ flagi.
     */
    void setIfShouldRefresh(unsigned char readKey, bool readShould);
    /**
     * Funkcja zwracaj¹ca, czy dany klawisz ma byæ odœwie¿any.
     * @param readKey Klawisz, dla którego sprawdzamy flagê odœwie¿enia.
     * @return Flaga informuj¹ca, czy klawisz wymaga odœwie¿enia.
     */
    bool getIfShouldRefresh(unsigned char readKey);
    /**
     * Funkcja przekierowywuj¹ca do prawdziwej wywo³ywana przy naciœniêciu klawisza.
     * @param readKey Klawisz, który zosta³ naciœniêty.
     * @param readX Pozycja X kursora myszy w momencie naciœniêcia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie naciœniêcia klawisza.
     */
    void static keyDown(unsigned char readKey, int readX, int readY);
    /**
     * Funkcja przekierowywuj¹ca do prawdziwej wywo³ywana przy puszczeniu klawisza.
     * @param readKey Klawisz, który zosta³ puszczony.
     * @param readX Pozycja X kursora myszy w momencie puszczenia klawisza.
     * @param readY Pozycja Y kursora myszy w momencie puszczenia klawisza.
     */
    void static keyUp(unsigned char readKey, int readX, int readY);
    /**
     * Funkcja sprawdzaj¹ca, czy dany klawisz jest wciœniêty.
     * @param readKey Klawisz, który chcemy sprawdziæ.
     * @return Flaga wskazuj¹ca, czy klawisz jest wciœniêty.
     */
    bool checkIfPressed(unsigned char readKey);
};
