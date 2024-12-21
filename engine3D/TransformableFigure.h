#pragma once
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp>
#include "Figures.h"

/** @class TransformableFigure
 *  Klasa reprezentuj¹ca obiekt, który mo¿e zostaæ przekszta³cony.
 */
class TransformableFigure : public virtual Figures {
public:
    /**
     * Funkcja przesuwaj¹ca obiekt o zadany wektor.
     * @param readChange Wektor zmiany pozycji obiektu.
     */
    void translate(glm::vec3 readChange);
    /**
     * Funkcja obracaj¹ca obiekt o zadany k¹t wokó³ zadanej osi.
     * @param readAngle K¹t obrotu w stopniach.
     * @param readAxis Oœ, wokó³ której obiekt ma zostaæ obrócony.
     */
    void rotate(float readAngle, glm::vec3 readAxis);
    /**
     * Funkcja skaluj¹ca obiekt o zadany wspó³czynnik.
     * @param readScale Wspó³czynnik skali.
     */
    void scale(float readScale);
    /**
     * Funkcja stosuj¹ca dowoln¹ macierz transformacji do obiektu.
     * @param readMatrix Macierz transformacji typu glm::mat4.
     */
    void freeTransform(glm::mat4 readMatrix);
};
