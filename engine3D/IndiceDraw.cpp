#include "IndiceDraw.h"

void IndiceDraw::updateIndiceCount(unsigned short int& index) {
	index += (unsigned short)data.size() / 3;
}

std::vector<unsigned short int> IndiceDraw::getIndices() {
	return indices;
}

void IndiceDraw::setIndices(std::vector<unsigned short int> readIndices) {
	indices = readIndices;
	callForRefresh = true;
}


