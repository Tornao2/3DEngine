#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>

typedef enum vecType {
	pos,
	col,
	nor
}vecType;

class Figure {
protected:
	std::vector<float> indices;
	std::vector<float> indicesPerSide;
	std::vector<glm::vec4>posVec;
	std::vector<glm::vec4>colVec;
	std::vector<glm::vec4>norVec;
public:
	std::vector<float>* getIndices();
	void setIndices(std::vector<float> readIndices);
	std::vector<float>* getIndicesPerSide();
	void setIndicesPerSide(std::vector<float> readIndicesPerSide);
	std::vector<glm::vec4> getVector(vecType type);
	void setVector(std::vector<glm::vec4> readVec, vecType type);
	void changePoint(glm::vec4 point, int index, vecType type);
	glm::vec4 getPoint(int index, vecType type);
	void virtual drawFigure() {};
};