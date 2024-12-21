#pragma once
#include "Figures.h"

/** @class DirectDraw
 *  Klasa obiektów rysowanych za pomoc¹ glDrawArrays
 */
class DirectDraw: public virtual Figures{
public:
    /**
     * Wirtualna funkcja rysuj¹ca wywo³uj¹ca dostosowane do figury glDrawArrays
     * @param index Numer pierwszego wierzcho³ka danej figury w buferze
     */
	void virtual drawDirect(int index) {};
};

