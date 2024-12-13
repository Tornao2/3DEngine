#include "ObjectManager.h"

ObjectManager::ObjectManager(Shader* readShader) {
	shader = readShader;
}

ObjectManager::ObjectManager() {
	shader = nullptr;
}

void ObjectManager::addPrimitive(Primitive* readPrimitive, int index) {
	if (index == -1 || index >= primitiveList.size())
		primitiveList.push_back(readPrimitive);
	else if (index >= 0)
		primitiveList.insert(primitiveList.begin() + index, readPrimitive);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removePrimitive(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return;
	primitiveList.erase(primitiveList.begin() + index);
	refreshBuffer();
}

Primitive* ObjectManager::getPrimitive(int index) {
	if (index == -1) index = primitiveList.size() - 1;
	if (primitiveList.size() <= index || index < 0)
		return nullptr;
	return primitiveList[index];
}

void ObjectManager::clearPrimitiveList() {
	primitiveList.clear();
	refreshBuffer();
}

void ObjectManager::drawAll() {
	bool refreshed = false;
	for (int i = 0; i < primitiveList.size(); i++) {
		if (primitiveList[i]->getIfRefresh()) {
			for (int j = i; j < primitiveList.size(); j++) 
				primitiveList[j]->setIfRefresh(false);
			refreshBuffer();
			refreshed = true;
			break;
		}
	}
	if (!refreshed) {
		for (int i = 0; i < figureList.size(); i++) {
			if (figureList[i]->getIfRefresh()) {
				for (int j = i; j < figureList.size(); j++)
					figureList[j]->setIfRefresh(false);
				refreshBuffer();
				break;
			}
		}
	}
	glDrawElements(GL_TRIANGLES, totalIndices.size(), GL_UNSIGNED_SHORT, (void*) totalIndices.data());
	int index = 0;
	for (int i = 0; i < figureList.size(); i++) 
		 index += figureList[i]->getDataCount()/3;
	for (int i = 0; i < primitiveList.size(); i++) {
		primitiveList[i]->drawFigure(index);
		primitiveList[i]->updateIndex(index);
	}
}

void ObjectManager::addFigure(Figure* readFigure, int index) {
	if (index == -1 || index >= figureList.size())
		figureList.push_back(readFigure);
	else if (index >= 0)
		figureList.insert(figureList.begin() + index, readFigure);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removeFigure(int index) {
	if (index == -1) index = figureList.size() - 1;
	if (figureList.size() <= index || index < 0)
		return;
	figureList.erase(figureList.begin() + index);
	refreshBuffer();
}

Figure* ObjectManager::getFigure(int index) {
	if (index == -1) index = figureList.size() - 1;
	if (figureList.size() <= index || index < 0)
		return nullptr;
	return figureList[index];
}

void ObjectManager::clearFigureList() {
	figureList.clear();
	refreshBuffer();
}

void ObjectManager::setShader(Shader* readShader) {
	shader = readShader;
}

void ObjectManager::refreshBuffer() {
	std::vector <glm::vec4> allFigures;
	totalIndices.clear();
	unsigned short int index = 0;
	for (int i = 0; i < figureList.size(); i++) {
		for (int j = 0; j < figureList[i]->getDataCount(); j++)
			allFigures.push_back(figureList[i]->getData()[j]);
		for (int j = 0; j < figureList[i]->getIndices().size(); j++) 
			totalIndices.push_back(figureList[i]->getIndices()[j] + index);
		figureList[i]->updateIndiceCount(index);
	}
	for (int i = 0; i < primitiveList.size(); i++)
		for (int j = 0; j < primitiveList[i]->getDataCount() * 3; j++)
			allFigures.push_back(primitiveList[i]->getData()[j]);
	glBindBuffer(GL_ARRAY_BUFFER, shader->getVBO());
	glBufferData(GL_ARRAY_BUFFER, allFigures.size() * sizeof(glm::vec4) , allFigures.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}