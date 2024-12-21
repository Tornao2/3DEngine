#pragma once

/** @class Refreshable
 *  Klasa bazowa umo�liwiaj�ca kontrolowanie, czy obiekt wymaga od�wie�enia.
 */
class Refreshable {
protected:
    /** Flaga wskazuj�ca, czy obiekt wymaga od�wie�enia */
    int callForRefresh;
public:
    /**
     * Funkcja zwracaj�ca, czy obiekt wymaga od�wie�enia.
     * @return Warto�� typu bool, wskazuj�ca czy od�wie�enie jest wymagane.
     */
    bool getIfRefresh();
    /**
     * Funkcja ustawiaj�ca, czy obiekt wymaga od�wie�enia.
     * @param readRefresh Flaga wskazuj�ca czy obiekt wymaga od�wie�enia.
     */
    void setIfRefresh(bool readRefresh);
};
