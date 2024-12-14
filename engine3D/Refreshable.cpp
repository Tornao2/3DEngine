#include "Refreshable.h"

bool Refreshable::getIfRefresh() {
	return callForRefresh;
}

void Refreshable::setIfRefresh(bool readRefresh) {
	callForRefresh = readRefresh;
}