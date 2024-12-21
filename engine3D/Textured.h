#pragma once

/** @class Textured
 *  Klasa bazowa umo¿liwiaj¹ca przypisanie tekstury do obiektów.
 */
class Textured {
protected:
    /** Identyfikator tekstury */
    int textureId;
public:
    /**
     * Funkcja ustawiaj¹ca identyfikator tekstury.
     * @param readTextureId Nowy identyfikator tekstury.
     */
    void setTextureId(int readTextureId);
    /**
     * Funkcja zwracaj¹ca identyfikator tekstury.
     * @return Identyfikator tekstury.
     */
    int getTextured();
};
