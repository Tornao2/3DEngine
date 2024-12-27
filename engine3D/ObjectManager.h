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
 * Klasa odpowiedzialna za zarz¹dzanie obiektami programu.
 */
class ObjectManager {
private:
    /** WskaŸnik na obiekt zajmuj¹cy siê shaderami. */
    Shader* shader;
    /** Lista obiektów do bezpoœredniego rysowania. */
    std::vector<DirectDraw*> directList;
    /** Lista obiektów rysowanych z u¿yciem indeksów. */
    std::vector<IndiceDraw*> indicedList;
    /** Lista obiektów rysowanych z u¿yciem tekstur i indeksów. */
    std::vector<IndiceDraw*> indicedTexturedList;
    /** Ca³kowita liczba indeksów dla obiektów. */
    std::vector<int> totalIndices;
    /** Ca³kowita liczba indeksów dla obiektów teksturowanych. */
    std::vector<int> totalIndicesTextured;
    /** WskaŸnik na kamerê. */
    Observer* camera;
public:
    /** Konstruktor domyœlny. */
    ObjectManager();
    /**
     * Dodaje obiekt do listy obiektów do bezpoœredniego rysowania.
     * @param readDirect WskaŸnik na obiekt do dodania.
     * @param index Opcjonalny indeks, w którym obiekt ma byæ dodany.
     */
    void addDirectDrawable(DirectDraw* readDirect, int index = -1);
    /**
     * Usuwa obiekt z listy obiektów do bezpoœredniego rysowania.
     * @param index Opcjonalny indeks obiektu do usuniêcia.
     */
    void removeDirectDrawable(int index = -1);
    /**
     * Zwraca obiekt z listy obiektów do bezpoœredniego rysowania.
     * @param index Opcjonalny indeks obiektu do zwrócenia.
     * @return WskaŸnik na obiekt.
     */
    DirectDraw* getDirectDrawable(int index = -1);
    /**
     * Dodaje obiekt z indeksami do listy obiektów.
     * @param readIndiced WskaŸnik na obiekt do dodania.
     * @param index Opcjonalny indeks, w którym obiekt ma byæ dodany.
     */
    void addIndicedDrawable(IndiceDraw* readIndiced, int index = -1);
    /**
     * Usuwa obiekt z listy obiektów z indeksami.
     * @param index Opcjonalny indeks obiektu do usuniêcia.
     */
    void removeIndicedDrawable(int index = -1);
    /**
     * Zwraca obiekt z listy obiektów z indeksami.
     * @param index Opcjonalny indeks obiektu do zwrócenia.
     * @return WskaŸnik na obiekt.
     */
    IndiceDraw* getIndicedDrawable(int index = -1);
    /**
     * Dodaje obiekt teksturowany do listy obiektów z indeksami.
     * @param readIndiced WskaŸnik na obiekt do dodania.
     * @param index Opcjonalny indeks, w którym obiekt ma byæ dodany.
     */
    void addIndicedDrawableTextured(IndiceDraw* readIndiced, int index = -1);
    /**
     * Usuwa obiekt teksturowany z listy obiektów z indeksami.
     * @param index Opcjonalny indeks obiektu do usuniêcia.
     */
    void removeIndicedDrawableTextured(int index = -1);
    /**
     * Zwraca obiekt teksturowany z listy obiektów z indeksami.
     * @param index Opcjonalny indeks obiektu do zwrócenia.
     * @return WskaŸnik na obiekt.
     */
    IndiceDraw* getIndicedDrawableTextured(int index = -1);
    /** Czyœci listê obiektów z indeksami. */
    void clearIndicedList();
    /** Czyœci listê obiektów do bezpoœredniego rysowania. */
    void clearDirectList();
    /** Czyœci listê obiektów teksturowanych z indeksami. */
    void clearIndicedTexturedList();
    /** Rysuje wszystkie obiekty. */
    void drawAll();
    /**
     * Ustawia obiekt obs³uguj¹cy shadery.
     * @param readShader WskaŸnik na obiekt obs³uguj¹cy shadery.
     */
    void setShader(Shader* readShader);
    /** Odœwie¿a bufory z danymi do rysowanaia. */
    void refreshBuffer();
    /**
     * Ustawia kamerê.
     * @param readCamera WskaŸnik na kamerê do ustawienia.
     */
    void setCamera(Observer* readCamera);
    /**
     * Zwraca wskaŸnik na kamerê.
     * @return WskaŸnik na kamerê.
     */
    Observer* getCamera();
};
