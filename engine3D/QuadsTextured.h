#pragma once
#include "Quads.h"
#include "Textured.h"

/** @class QuadsTextured
 *  Klasa reprezentuj�ca czworok�ty z tekstur�.
 */
class QuadsTextured : public Quads, public Textured {
public:
    /**
     * Konstruktor tworz�cy obiekt czworok�ta z tekstur�.
     * @param readData Dane reprezentuj�ce czworok�ty.
     */
    QuadsTextured(std::vector<glm::vec4> readData);
};
