#pragma once
#include <GL/glut.h>
#include <string>

/** @class DisplayManager
 *  Klasa odpowiedzialna za zarz�dzanie oknem wy�wietlania oraz konfiguracj� wy�wietlania.
 */
class DisplayManager {
public:
    /**
     * Konstruktor inicjalizuj�cy ustawienia okna.
     * @param readWidth Szeroko�� okna.
     * @param readHeight Wysoko�� okna.
     * @param readFullscreen Flaga informuj�ca, czy okno ma by� w trybie pe�noekranowym.
     * @param readDoubleBuffer Flaga informuj�ca, czy w��czony ma by� bufor podw�jny.
     * @param readTitle Tytu� okna programu.
     */
    DisplayManager(int readWidth = 640, int readHeight = 480, bool readFullscreen = false, bool readDoubleBuffer = true, std::string readTitle = "Engine");
    /**
     * Funkcja inicjalizuj�ca okno wy�wietlania.
     */
    void initializeWindow();
    /**
     * Funkcja zwracaj�ca szeroko�� okna.
     * @return Szeroko�� okna.
     */
    int getWindowWidth();
    /**
     * Funkcja zwracaj�ca wysoko�� okna.
     * @return Wysoko�� okna.
     */
    int GetWindowHeight();
    /**
     * Funkcja ustalaj�ca szeroko�� okna.
     * @param readWidth Nowa szeroko�� okna.
     */
    void setWindowWidth(int readWidth);
    /**
     * Funkcja ustalaj�ca wysoko�� okna.
     * @param readHeight Nowa wysoko�� okna.
     */
    void setWindowHeight(int readHeight);
    /**
     * Funkcja zwracaj�ca, czy okno jest w trybie pe�noekranowym.
     * @return Flaga wskazuj�ca, czy tryb pe�noekranowy jest w��czony.
     */
    bool ifFullscreen();
    /**
     * Funkcja ustalaj�ca, czy okno ma by� w trybie pe�noekranowym.
     * @param readFullscreen Flaga informuj�ca, czy w��czy� tryb pe�noekranowy.
     */
    void setFullscreen(bool readFullscreen);
private:
    /** Szeroko�� okna */
    int windowWidth;
    /** Wysoko�� okna */
    int windowHeight;
    /** Flaga informuj�ca, czy tryb pe�noekranowy jest w��czony */
    bool fullscreen;
    /** Flaga informuj�ca, czy bufor podw�jny jest w��czony */
    bool doubleBuffer;
    /** Tytu� okna programu */
    std::string programTitle;
};
