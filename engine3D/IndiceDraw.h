#pragma once
#include "Figures.h"

class IndiceDraw: public virtual Figures{
protected:
	std::vector<unsigned short int> indices;
public:
	std::vector<unsigned short int> getIndices();
	void setIndices(std::vector<unsigned short int> readIndices);
	void updateIndiceCount(unsigned short int& index);
};