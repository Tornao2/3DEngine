#pragma once

/** @class Textured
 *  Klasa bazowa umożliwiająca przypisanie tekstury do obiektów.
 */
class Textured {
protected:
    /** Identyfikator tekstury */
    int textureId;
public:
    /**
     * Funkcja ustawiająca identyfikator tekstury.
     * @param readTextureId Nowy identyfikator tekstury.
     */
    void setTextureId(int readTextureId);
    /**
     * Funkcja zwracająca identyfikator tekstury.
     * @return Identyfikator tekstury.
     */
    int getTextureId();
};
