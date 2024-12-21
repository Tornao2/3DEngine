#pragma once
#include "Quads.h"
#include "Textured.h"

/** @class QuadsTextured
 *  Klasa reprezentuj¹ca czworok¹ty z tekstur¹.
 */
class QuadsTextured : public Quads, public Textured {
public:
    /**
     * Konstruktor tworz¹cy obiekt czworok¹ta z tekstur¹.
     * @param readData Dane reprezentuj¹ce czworok¹ty.
     */
    QuadsTextured(std::vector<glm::vec4> readData);
};
