#pragma once
#include "Figures.h"

class DirectDraw: public Figures{
public:
	void virtual drawFigure(int index) {};
	void updateIndex(int& index);
};