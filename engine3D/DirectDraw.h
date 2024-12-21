#pragma once
#include "Figures.h"

/** @class DirectDraw
 *  Klasa obiekt�w rysowanych za pomoc� glDrawArrays
 */
class DirectDraw: public virtual Figures{
public:
    /**
     * Wirtualna funkcja rysuj�ca wywo�uj�ca dostosowane do figury glDrawArrays
     * @param index Numer pierwszego wierzcho�ka danej figury w buferze
     */
	void virtual drawDirect(int index) {};
};

