#include "ObjectManager.h"

ObjectManager::ObjectManager(Shader* readShader) {
	shader = readShader;
}

ObjectManager::ObjectManager() {
	shader = nullptr;
}

void ObjectManager::addFigure(Primitive* readFigure, int index) {
	if (index == -1 || index >= primitiveList.size())
		primitiveList.push_back(readFigure);
	else if (index >= 0)
		primitiveList.insert(primitiveList.begin() + index, readFigure);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removeFigure(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return;
	primitiveList.erase(primitiveList.begin() + index);
	refreshBuffer();
}

Primitive* ObjectManager::getFigure(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return nullptr;
	return primitiveList[index];
}

void ObjectManager::clearList() {
	primitiveList.clear();
	refreshBuffer();
}

void ObjectManager::drawAll() {
	for (int i = 0; i < primitiveList.size(); i++) {
		if (primitiveList[i]->getIfRefresh()) {
			for (int j = i; j < primitiveList.size(); j++) 
				primitiveList[j]->setIfRefresh(false);
			refreshBuffer();
			break;
		}
	}
	int index = 0;
	for (int i = 0; i < primitiveList.size(); i++) {
		primitiveList[i]->drawFigure(index);
		primitiveList[i]->updateIndex(index);
	}
}

void ObjectManager::setShader(Shader* readShader) {
	shader = readShader;
}

void ObjectManager::refreshBuffer() {
	std::vector <glm::vec4> allFigures;
	for (int i = 0; i < primitiveList.size(); i++)
		for (int j = 0; j < primitiveList[i]->getDataCount() * 3; j++)
			allFigures.push_back(primitiveList[i]->getData()[j]);
	glBindBuffer(GL_ARRAY_BUFFER, shader->getVBO());
	glBufferData(GL_ARRAY_BUFFER, allFigures.size() * sizeof(glm::vec4), allFigures.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}