#include "ObjectManager.h"

void ObjectManager::addFigure(Primitive readFigure, int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return;
	primitiveList.insert(primitiveList.begin() + index, readFigure);
}

void ObjectManager::removeFigure(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return;
	primitiveList.erase(primitiveList.begin() + index);
}

Primitive* ObjectManager::getFigure(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return nullptr;
	return &primitiveList[index];
}

void ObjectManager::clearList() {
	primitiveList.clear();
}

void ObjectManager::drawAll() {
	for (int i = 0; i < primitiveList.size(); i++) 
		primitiveList[i].drawFigure();
}