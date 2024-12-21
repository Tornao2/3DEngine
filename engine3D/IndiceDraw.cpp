#include "IndiceDraw.h"

std::vector<int> IndiceDraw::getIndices() {
	return indices;
}

void IndiceDraw::setIndices(std::vector<int> readIndices) {
	indices = readIndices;
	callForRefresh = true;
}