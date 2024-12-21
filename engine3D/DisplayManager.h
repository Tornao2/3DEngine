#pragma once
#include <GL/glut.h>
#include <string>

/** @class DisplayManager
 *  Klasa odpowiedzialna za zarz¹dzanie oknem wyœwietlania oraz konfiguracjê wyœwietlania.
 */
class DisplayManager {
public:
    /**
     * Konstruktor inicjalizuj¹cy ustawienia okna.
     * @param readWidth Szerokoœæ okna.
     * @param readHeight Wysokoœæ okna.
     * @param readFullscreen Flaga informuj¹ca, czy okno ma byæ w trybie pe³noekranowym.
     * @param readDoubleBuffer Flaga informuj¹ca, czy w³¹czony ma byæ bufor podwójny.
     * @param readTitle Tytu³ okna programu.
     */
    DisplayManager(int readWidth = 640, int readHeight = 480, bool readFullscreen = false, bool readDoubleBuffer = true, std::string readTitle = "Engine");
    /**
     * Funkcja inicjalizuj¹ca okno wyœwietlania.
     */
    void initializeWindow();
    /**
     * Funkcja zwracaj¹ca szerokoœæ okna.
     * @return Szerokoœæ okna.
     */
    int getWindowWidth();
    /**
     * Funkcja zwracaj¹ca wysokoœæ okna.
     * @return Wysokoœæ okna.
     */
    int GetWindowHeight();
    /**
     * Funkcja ustalaj¹ca szerokoœæ okna.
     * @param readWidth Nowa szerokoœæ okna.
     */
    void setWindowWidth(int readWidth);
    /**
     * Funkcja ustalaj¹ca wysokoœæ okna.
     * @param readHeight Nowa wysokoœæ okna.
     */
    void setWindowHeight(int readHeight);
    /**
     * Funkcja zwracaj¹ca, czy okno jest w trybie pe³noekranowym.
     * @return Flaga wskazuj¹ca, czy tryb pe³noekranowy jest w³¹czony.
     */
    bool ifFullscreen();
    /**
     * Funkcja ustalaj¹ca, czy okno ma byæ w trybie pe³noekranowym.
     * @param readFullscreen Flaga informuj¹ca, czy w³¹czyæ tryb pe³noekranowy.
     */
    void setFullscreen(bool readFullscreen);
private:
    /** Szerokoœæ okna */
    int windowWidth;
    /** Wysokoœæ okna */
    int windowHeight;
    /** Flaga informuj¹ca, czy tryb pe³noekranowy jest w³¹czony */
    bool fullscreen;
    /** Flaga informuj¹ca, czy bufor podwójny jest w³¹czony */
    bool doubleBuffer;
    /** Tytu³ okna programu */
    std::string programTitle;
};
