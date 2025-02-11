#pragma once
#include "Quads.h"
#include "Textured.h"

/** @class QuadsTextured
 *  Klasa reprezentująca czworokąty z teksturą.
 */
class QuadsTextured : public Quads, public Textured {
public:
    /**
     * Konstruktor tworzący obiekt czworokąta z teksturą.
     * @param readData Dane reprezentujące czworokąty.
     */
    QuadsTextured(std::vector<glm::vec4> readData);
};
