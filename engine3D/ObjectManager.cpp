#include "ObjectManager.h"

void ObjectManager::addFigure(Primitive* readFigure, int index) {
	if (index == -1 || index >= primitiveList.size()) {
		primitiveList.push_back(readFigure);
	}
	else if (index >= 0) {
		primitiveList.insert(primitiveList.begin() + index, readFigure);
	}
	else {
		return;
	}
	std::vector<float> vertexData;
	for (Primitive* figure : primitiveList) {
		float* vertexArray = figure->getVertex();
		int vertexCount = figure->getVerticeSize();
		vertexData.insert(vertexData.end(), vertexArray, vertexArray + vertexCount);
	}
	glBindBuffer(GL_ARRAY_BUFFER, shader->getVBO());
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
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
	return primitiveList[index];
}

void ObjectManager::clearList() {
	primitiveList.clear();
}

void ObjectManager::drawAll() {
	for (int i = 0; i < primitiveList.size(); i++) 
		primitiveList[i]->drawFigure(shader);
}

void ObjectManager::setShader(Shader* readShader) {
	shader = readShader;
}