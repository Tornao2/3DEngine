#pragma once

/** @class Textured
 *  Klasa bazowa umo�liwiaj�ca przypisanie tekstury do obiekt�w.
 */
class Textured {
protected:
    /** Identyfikator tekstury */
    int textureId;
public:
    /**
     * Funkcja ustawiaj�ca identyfikator tekstury.
     * @param readTextureId Nowy identyfikator tekstury.
     */
    void setTextureId(int readTextureId);
    /**
     * Funkcja zwracaj�ca identyfikator tekstury.
     * @return Identyfikator tekstury.
     */
    int getTextured();
};
