#pragma once
#include "Figures.h"

class IndiceDraw: public virtual Figures{
protected:
	std::vector<unsigned short int> indices;
public:
	void updateIndiceCount(unsigned short int& index);
	std::vector<unsigned short int> getIndices();
	void setIndices(std::vector<unsigned short int> readIndices);
};