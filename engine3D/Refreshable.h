#pragma once

/** @class Refreshable
 *  Klasa bazowa umo¿liwiaj¹ca kontrolowanie, czy obiekt wymaga odœwie¿enia.
 */
class Refreshable {
protected:
    /** Flaga wskazuj¹ca, czy obiekt wymaga odœwie¿enia */
    int callForRefresh;
public:
    /**
     * Funkcja zwracaj¹ca, czy obiekt wymaga odœwie¿enia.
     * @return Wartoœæ typu bool, wskazuj¹ca czy odœwie¿enie jest wymagane.
     */
    bool getIfRefresh();
    /**
     * Funkcja ustawiaj¹ca, czy obiekt wymaga odœwie¿enia.
     * @param readRefresh Flaga wskazuj¹ca czy obiekt wymaga odœwie¿enia.
     */
    void setIfRefresh(bool readRefresh);
};
