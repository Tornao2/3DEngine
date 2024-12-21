#pragma once
#include "stb_image.h"
#include <string>
#include <GL/glew.h>

/**
 * @class BitmapHandler
 * Klasa odpowiedzialna za �adowanie i usuwanie bitmap.
 */
class BitmapHandler {
public:
    /**
     * Funkcja �aduje bitmap� (tekstur�) z podanej �cie�ki i zwraca identyfikator tekstury.
     * @param readPath �cie�ka do pliku bitmapy.
     * @return Identyfikator tekstury.
     */
    int loadBitmap(std::string readPath);
    /**
     * Funkcja usuwa bitmap� (tekstur�) z pami�ci.
     * @param readTextureId Identyfikator tekstury do usuni�cia.
     */
    void deleteBitmap(int& readTextureId);
};
