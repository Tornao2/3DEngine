#pragma once
#include "MouseHandler.h"
#include "Renderer.h"
#include "DisplayManager.h"
#include <functional>
#include "BitmapHandler.h"

/**
 * @class Engine
 * Klasa odpowiedzialna za zarz�dzanie g��wnym cyklem gry, w tym obs�ug� klawiatury, myszy, renderowania i okna wy�wietlania.
 */
class Engine {
public:
    /**
     * Konstruktor inicjalizuj�cy silnik gry.
     * @param argc Liczba argument�w wiersza polece�.
     * @param argv Tablica argument�w wiersza polece�.
     * @param readRenderer Obiekt odpowiedzialny za renderowanie.
     * @param readDisplayManager Obiekt odpowiedzialny za zarz�dzanie oknem.
     * @param readDelay Liczba fps (domy�lnie 300fps, ale jest to ograniczane przez od�wie�anie monitora).
     */
    Engine(int* argc, char* argv[], Renderer& readRenderer, DisplayManager& readDisplayManager, int readDelay = 300);
    /**
     * Funkcja zwracaj�ca limit klatek na sekund�.
     * @return Limit klatek na sekund�.
     */
    int getFpsCap();
    /**
     * Funkcja ustawiaj�ca limit klatek na sekund�.
     * @param readDelay Liczba klatek na sekund�.
     */
    void setFpsCap(int readDelay);
    /**
     * Funkcja w��czaj�ca/wy��czaj�ca obs�ug� klawiatury.
     * @param readShould Flaga okre�laj�ca, czy klawiatura ma by� w��czona.
     * @param readFunction Funkcja zajmuj�ca si� obs�ug� klawiatury wywo�ywana co klatk� programu.
     */
    void toggleKeyboard(bool readShould, std::function<void(void)> readFunction);
    /**
     * Funkcja w��czaj�ca/wy��czaj�ca obs�ug� myszy.
     * @param readShould Flaga okre�laj�ca, czy mysz ma by� w��czona.
     * @param readFunction Funkcja zajmuj�ca si� obs�ug� myszki wywo�ywana co klatk� programu.
     */
    void toggleMouse(bool readShould, std::function<void(void)> readFunction);
private:
    /** Limit klatek na sekund� */
    int fpsCap;
    /** Statyczna instancja silnika */
    static Engine* instance;
    /**
     * Funkcja inicjalizuj�ca bibliotek� i konfiguruj�ca okno.
     * @param argc Liczba argument�w wiersza polece�.
     * @param argv Tablica argument�w wiersza polece�.
     * @param readDisplayManager Obiekt odpowiedzialny za zarz�dzanie oknem.
     */
    void initializeLibrary(int* argc, char* argv[], DisplayManager& readDisplayManager);
    /**
     * Funkcja odpowiedzialna za cykliczne wywo�anie timeru.
     * @param readDummy Parametr pomocniczy (nieu�ywany).
     */
    static void timer(int readDummy);
    /** Funkcja obs�uguj�ca mysz� co klatk� */
    static std::function<void(void)> mouseFunc;
    /** Funkcja obs�uguj�ca wci�ni�cia klawiatur� co klatk� */
    static std::function<void(void)> keyboardFunc;
};
