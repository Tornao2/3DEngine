#include "DirectDraw.h"

void DirectDraw::updateIndex(int& index) {
	index += (int) data.size()/3;
}
