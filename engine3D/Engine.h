#pragma once
#include "MouseHandler.h"
#include "Renderer.h"
#include "DisplayManager.h"
#include <functional>
#include "BitmapHandler.h"

/**
 * @class Engine
 * Klasa odpowiedzialna za zarz¹dzanie g³ównym cyklem gry, w tym obs³ug¹ klawiatury, myszy, renderowania i okna wyœwietlania.
 */
class Engine {
public:
    /**
     * Konstruktor inicjalizuj¹cy silnik gry.
     * @param argc Liczba argumentów wiersza poleceñ.
     * @param argv Tablica argumentów wiersza poleceñ.
     * @param readRenderer Obiekt odpowiedzialny za renderowanie.
     * @param readDisplayManager Obiekt odpowiedzialny za zarz¹dzanie oknem.
     * @param readDelay Liczba fps (domyœlnie 300fps, ale jest to ograniczane przez odœwie¿anie monitora).
     */
    Engine(int* argc, char* argv[], Renderer& readRenderer, DisplayManager& readDisplayManager, int readDelay = 300);
    /**
     * Funkcja zwracaj¹ca limit klatek na sekundê.
     * @return Limit klatek na sekundê.
     */
    int getFpsCap();
    /**
     * Funkcja ustawiaj¹ca limit klatek na sekundê.
     * @param readDelay Liczba klatek na sekundê.
     */
    void setFpsCap(int readDelay);
    /**
     * Funkcja w³¹czaj¹ca/wy³¹czaj¹ca obs³ugê klawiatury.
     * @param readShould Flaga okreœlaj¹ca, czy klawiatura ma byæ w³¹czona.
     * @param readFunction Funkcja zajmuj¹ca siê obs³ug¹ klawiatury wywo³ywana co klatkê programu.
     */
    void toggleKeyboard(bool readShould, std::function<void(void)> readFunction);
    /**
     * Funkcja w³¹czaj¹ca/wy³¹czaj¹ca obs³ugê myszy.
     * @param readShould Flaga okreœlaj¹ca, czy mysz ma byæ w³¹czona.
     * @param readFunction Funkcja zajmuj¹ca siê obs³ug¹ myszki wywo³ywana co klatkê programu.
     */
    void toggleMouse(bool readShould, std::function<void(void)> readFunction);
private:
    /** Limit klatek na sekundê */
    int fpsCap;
    /** Statyczna instancja silnika */
    static Engine* instance;
    /**
     * Funkcja inicjalizuj¹ca bibliotekê i konfiguruj¹ca okno.
     * @param argc Liczba argumentów wiersza poleceñ.
     * @param argv Tablica argumentów wiersza poleceñ.
     * @param readDisplayManager Obiekt odpowiedzialny za zarz¹dzanie oknem.
     */
    void initializeLibrary(int* argc, char* argv[], DisplayManager& readDisplayManager);
    /**
     * Funkcja odpowiedzialna za cykliczne wywo³anie timeru.
     * @param readDummy Parametr pomocniczy (nieu¿ywany).
     */
    static void timer(int readDummy);
    /** Funkcja obs³uguj¹ca myszê co klatkê */
    static std::function<void(void)> mouseFunc;
    /** Funkcja obs³uguj¹ca wciœniêcia klawiaturê co klatkê */
    static std::function<void(void)> keyboardFunc;
};
