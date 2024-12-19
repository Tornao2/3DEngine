#include "ObjectManager.h"

ObjectManager::ObjectManager() {
	shader = nullptr;
}

void ObjectManager::addDirectDrawable(DirectDraw* readDirect, int index) {
	if (index == -1 || index >= directList.size())
		directList.push_back(readDirect);
	else if (index >= 0)
		directList.insert(directList.begin() + index, readDirect);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removeDirectDrawable(int index) {
	if (index == -1) index = (int) directList.size() - 1;
	if (directList.size() <= index || index < 0)
		return;
	directList.erase(directList.begin() + index);
	refreshBuffer();
}

DirectDraw* ObjectManager::getDirectDrawable(int index) {
	if (index == -1) index = (int) directList.size() - 1;
	if (directList.size() <= index || index < 0)
		return nullptr;
	return directList[index];
}

void ObjectManager::clearDirectList() {
	directList.clear();
	refreshBuffer();
}

void ObjectManager::drawAll() {
	glBindVertexArray(shader->getVAO());
	bool refreshed = false;
	for (int i = 0; i < directList.size(); i++) {
		if (directList[i]->getIfRefresh()) {
			for (int j = i; j < directList.size(); j++) 
				directList[j]->setIfRefresh(false);
			refreshBuffer();
			refreshed = true;
			break;
		}
	}
	if (!refreshed) {
		for (int i = 0; i < indicedList.size(); i++) {
			if (indicedList[i]->getIfRefresh()) {
				for (int j = i; j < indicedList.size(); j++)
					indicedList[j]->setIfRefresh(false);
				refreshBuffer();
				refreshed = true;
				break;
			}
		}
	}
	if (!refreshed) {
		for (int i = 0; i < indicedTexturedList.size(); i++) {
			if (indicedTexturedList[i]->getIfRefresh()) {
				for (int j = i; j < indicedTexturedList.size(); j++)
					indicedTexturedList[j]->setIfRefresh(false);
				refreshBuffer();
				break;
			}
		}
	}
	glUniform1i(glGetUniformLocation(shader->getProgramId(), "useTexture"), 1);
	glDrawElements(GL_TRIANGLES, (GLsizei)totalIndicesTextured.size(), GL_UNSIGNED_SHORT, (void*)totalIndicesTextured.data());
	glUniform1i(glGetUniformLocation(shader->getProgramId(), "useTexture"), 0);
	glDrawRangeElements(GL_TRIANGLES, (GLsizei)totalIndicesTextured.size(), (GLsizei)totalIndicesTextured.size() + (GLsizei)totalIndices.size(), (GLsizei) totalIndices.size(), GL_UNSIGNED_SHORT, (void*) totalIndices.data());
	int index = 0;
	for (int i = 0; i < indicedList.size(); i++) 
		 index += indicedList[i]->getDataCount();
	for (int i = 0; i < indicedTexturedList.size(); i++)
		index += indicedTexturedList[i]->getDataCount();
	for (int i = 0; i < directList.size(); i++) {
		if (directList[i]->getTextured())
			glUniform1i(glGetUniformLocation(shader->getProgramId(), "useTexture"), 1);
		else
			glUniform1i(glGetUniformLocation(shader->getProgramId(), "useTexture"), 0);
		directList[i]->drawDirect(index);
		directList[i]->updateIndex(index);
	}
	glBindVertexArray(0);
}

void ObjectManager::addIndicedDrawable(IndiceDraw* readIndiced, int index) {
	if (index == -1 || index >= indicedList.size())
		indicedList.push_back(readIndiced);
	else if (index >= 0)
		indicedList.insert(indicedList.begin() + index, readIndiced);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removeIndicedDrawable(int index) {
	if (index == -1) index = (int) indicedList.size() - 1;
	if (indicedList.size() <= index || index < 0)
		return;
	indicedList.erase(indicedList.begin() + index);
	refreshBuffer();
}

IndiceDraw* ObjectManager::getIndicedDrawable(int index) {
	if (index == -1) index = (int) indicedList.size() - 1;
	if (indicedList.size() <= index || index < 0)
		return nullptr;
	return indicedList[index];
}

void ObjectManager::clearIndicedList() {
	indicedList.clear();
	totalIndices.clear();
	refreshBuffer();
}

void ObjectManager::setShader(Shader* readShader) {
	shader = readShader;
}

void ObjectManager::refreshBuffer() {
	std::vector <glm::vec4> allFigures;
	totalIndices.clear();
	unsigned short int index = 0;
	for (int i = 0; i < indicedTexturedList.size(); i++) {
		for (int j = 0; j < indicedTexturedList[i]->getDataCount()*3; j++)
			allFigures.push_back(indicedTexturedList[i]->getData()[j]);
		for (int j = 0; j < indicedTexturedList[i]->getIndices().size(); j++)
			totalIndicesTextured.push_back(indicedTexturedList[i]->getIndices()[j] + index);
		indicedTexturedList[i]->updateIndiceCount(index);
	}
	for (int i = 0; i < indicedList.size(); i++) {
		for (int j = 0; j < indicedList[i]->getDataCount()*3; j++)
			allFigures.push_back(indicedList[i]->getData()[j]);
		for (int j = 0; j < indicedList[i]->getIndices().size(); j++) 
			totalIndices.push_back(indicedList[i]->getIndices()[j] + index);
		indicedList[i]->updateIndiceCount(index);
	}
	for (int i = 0; i < directList.size(); i++)
		for (int j = 0; j < directList[i]->getDataCount() * 3; j++)
			allFigures.push_back(directList[i]->getData()[j]);
	glBindBuffer(GL_ARRAY_BUFFER, shader->getVBO());
	glBufferData(GL_ARRAY_BUFFER, allFigures.size() * sizeof(glm::vec4) , allFigures.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ObjectManager::setCamera(Observer* readCamera) {
	camera = readCamera;
}

Observer* ObjectManager::getCamera() {
	return camera;
}

void ObjectManager::clearIndicedTexturedList() {
	indicedTexturedList.clear();
	totalIndicesTextured.clear();
	refreshBuffer();
}

void ObjectManager::addIndicedDrawableTextured(IndiceDraw* readIndiced, int index) {
	if (index == -1 || index >= indicedTexturedList.size())
		indicedTexturedList.push_back(readIndiced);
	else if (index >= 0)
		indicedTexturedList.insert(indicedTexturedList.begin() + index, readIndiced);
	else
		return;
	refreshBuffer();
}

void ObjectManager::removeIndicedDrawableTextured(int index) {
	if (index == -1) index = (int)indicedTexturedList.size() - 1;
	if (indicedTexturedList.size() <= index || index < 0)
		return;
	indicedTexturedList.erase(indicedTexturedList.begin() + index);
	refreshBuffer();
}

IndiceDraw* ObjectManager::getIndicedDrawableTextured(int index) {
	if (index == -1) index = (int)indicedTexturedList.size() - 1;
	if (indicedTexturedList.size() <= index || index < 0)
		return nullptr;
	return indicedTexturedList[index];
}