#include "Figure.h"

std::vector<float>* Figure::getIndices() {
	return &indices;
}

void Figure::setIndices(std::vector<float> readIndices) {
	indices = readIndices;
}

std::vector<float>* Figure::getIndicesPerSide() {
	return &indicesPerSide;
}

void Figure::setIndicesPerSide(std::vector<float> readIndicesPerSide) {
	indicesPerSide = readIndicesPerSide;
}

std::vector<glm::vec4> Figure::getVector(vecType type) {
	if (type == col)
		return colVec;
	else if (type == nor)
		return norVec;
	else 
		return posVec;
}

void Figure::setVector(std::vector<glm::vec4> readVec, vecType type) {
	if (type == col)
		colVec = readVec;
	else if (type == nor)
		norVec = readVec;
	else
		posVec = readVec;
}

void Figure::changePoint(glm::vec4 point, int index, vecType type) {
	if (colVec.size() <= index || index < 0)
		return;
	glm::vec4* changedPoint;
	if (type == col) 
		changedPoint = &colVec[index];
	else if (type == nor) 
		changedPoint = &norVec[index];
	else 
		changedPoint = &posVec[index];
	(*changedPoint) = point;
}

glm::vec4 Figure::getPoint(int index, vecType type) {
	if (colVec.size() <= index || index < 0)
		return {};
	glm::vec4 realData;
	if (type == col) 
		realData = colVec[index];
	else if (type == nor) 
		realData = norVec[index];
	else 
		realData = posVec[index];
	return realData;
}