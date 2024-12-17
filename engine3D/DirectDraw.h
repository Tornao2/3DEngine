#pragma once
#include "Figures.h"

class DirectDraw: public virtual Figures{
public:
	void virtual drawDirect(int index) {};
	void updateIndex(int& index);
};