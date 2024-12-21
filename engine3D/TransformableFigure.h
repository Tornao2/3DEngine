#pragma once
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include "Figures.h"

/** @class TransformableFigure
 *  Klasa reprezentuj�ca obiekt, kt�ry mo�e zosta� przekszta�cony.
 */
class TransformableFigure : public virtual Figures {
public:
    /**
     * Funkcja przesuwaj�ca obiekt o zadany wektor.
     * @param readChange Wektor zmiany pozycji obiektu.
     */
    void translate(glm::vec3 readChange);
    /**
     * Funkcja obracaj�ca obiekt o zadany k�t wok� zadanej osi.
     * @param readAngle K�t obrotu w stopniach.
     * @param readAxis O�, wok� kt�rej obiekt ma zosta� obr�cony.
     */
    void rotate(float readAngle, glm::vec3 readAxis);
    /**
     * Funkcja skaluj�ca obiekt o zadany wsp�czynnik.
     * @param readScale Wsp�czynnik skali.
     */
    void scale(float readScale);
    /**
     * Funkcja stosuj�ca dowoln� macierz transformacji do obiektu.
     * @param readMatrix Macierz transformacji typu glm::mat4.
     */
    void freeTransform(glm::mat4 readMatrix);
};
