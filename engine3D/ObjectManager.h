#pragma once
#include "ShaderHandler.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "PoliLine.h"
#include "TriangleStrip.h"
#include "TriangleFan.h"
#include "QuadsTextured.h"
#include "CubeTextured.h"
#include "FigureE.h"
#include "Player.h"
#include "Observer.h"

/**
 * @class ObjectManager
 * Klasa odpowiedzialna za zarz�dzanie obiektami programu.
 */
class ObjectManager {
private:
    /** Wska�nik na obiekt zajmuj�cy si� shaderami. */
    Shader* shader;
    /** Lista obiekt�w do bezpo�redniego rysowania. */
    std::vector<DirectDraw*> directList;
    /** Lista obiekt�w rysowanych z u�yciem indeks�w. */
    std::vector<IndiceDraw*> indicedList;
    /** Lista obiekt�w rysowanych z u�yciem tekstur i indeks�w. */
    std::vector<IndiceDraw*> indicedTexturedList;
    /** Ca�kowita liczba indeks�w dla obiekt�w. */
    std::vector<int> totalIndices;
    /** Ca�kowita liczba indeks�w dla obiekt�w teksturowanych. */
    std::vector<int> totalIndicesTextured;
    /** Wska�nik na kamer�. */
    Observer* camera;
public:
    /** Konstruktor domy�lny. */
    ObjectManager();
    /**
     * Dodaje obiekt do listy obiekt�w do bezpo�redniego rysowania.
     * @param readDirect Wska�nik na obiekt do dodania.
     * @param index Opcjonalny indeks, w kt�rym obiekt ma by� dodany.
     */
    void addDirectDrawable(DirectDraw* readDirect, int index = -1);
    /**
     * Usuwa obiekt z listy obiekt�w do bezpo�redniego rysowania.
     * @param index Opcjonalny indeks obiektu do usuni�cia.
     */
    void removeDirectDrawable(int index = -1);
    /**
     * Zwraca obiekt z listy obiekt�w do bezpo�redniego rysowania.
     * @param index Opcjonalny indeks obiektu do zwr�cenia.
     * @return Wska�nik na obiekt.
     */
    DirectDraw* getDirectDrawable(int index = -1);
    /**
     * Dodaje obiekt z indeksami do listy obiekt�w.
     * @param readIndiced Wska�nik na obiekt do dodania.
     * @param index Opcjonalny indeks, w kt�rym obiekt ma by� dodany.
     */
    void addIndicedDrawable(IndiceDraw* readIndiced, int index = -1);
    /**
     * Usuwa obiekt z listy obiekt�w z indeksami.
     * @param index Opcjonalny indeks obiektu do usuni�cia.
     */
    void removeIndicedDrawable(int index = -1);
    /**
     * Zwraca obiekt z listy obiekt�w z indeksami.
     * @param index Opcjonalny indeks obiektu do zwr�cenia.
     * @return Wska�nik na obiekt.
     */
    IndiceDraw* getIndicedDrawable(int index = -1);
    /**
     * Dodaje obiekt teksturowany do listy obiekt�w z indeksami.
     * @param readIndiced Wska�nik na obiekt do dodania.
     * @param index Opcjonalny indeks, w kt�rym obiekt ma by� dodany.
     */
    void addIndicedDrawableTextured(IndiceDraw* readIndiced, int index = -1);
    /**
     * Usuwa obiekt teksturowany z listy obiekt�w z indeksami.
     * @param index Opcjonalny indeks obiektu do usuni�cia.
     */
    void removeIndicedDrawableTextured(int index = -1);
    /**
     * Zwraca obiekt teksturowany z listy obiekt�w z indeksami.
     * @param index Opcjonalny indeks obiektu do zwr�cenia.
     * @return Wska�nik na obiekt.
     */
    IndiceDraw* getIndicedDrawableTextured(int index = -1);
    /** Czy�ci list� obiekt�w z indeksami. */
    void clearIndicedList();
    /** Czy�ci list� obiekt�w do bezpo�redniego rysowania. */
    void clearDirectList();
    /** Czy�ci list� obiekt�w teksturowanych z indeksami. */
    void clearIndicedTexturedList();
    /** Rysuje wszystkie obiekty. */
    void drawAll();
    /**
     * Ustawia obiekt obs�uguj�cy shadery.
     * @param readShader Wska�nik na obiekt obs�uguj�cy shadery.
     */
    void setShader(Shader* readShader);
    /** Od�wie�a bufory z danymi do rysowanaia. */
    void refreshBuffer();
    /**
     * Ustawia kamer�.
     * @param readCamera Wska�nik na kamer� do ustawienia.
     */
    void setCamera(Observer* readCamera);
    /**
     * Zwraca wska�nik na kamer�.
     * @return Wska�nik na kamer�.
     */
    Observer* getCamera();
};
