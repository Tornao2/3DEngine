#pragma once
#include "stb_image.h"
#include <string>
#include <GL/glew.h>

/**
 * @class BitmapHandler
 * Klasa odpowiedzialna za ³adowanie i usuwanie bitmap.
 */
class BitmapHandler {
public:
    /**
     * Funkcja ³aduje bitmapê (teksturê) z podanej œcie¿ki i zwraca identyfikator tekstury.
     * @param readPath Œcie¿ka do pliku bitmapy.
     * @return Identyfikator tekstury.
     */
    int loadBitmap(std::string readPath);
    /**
     * Funkcja usuwa bitmapê (teksturê) z pamiêci.
     * @param readTextureId Identyfikator tekstury do usuniêcia.
     */
    void deleteBitmap(int& readTextureId);
};
