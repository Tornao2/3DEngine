#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>

typedef enum vecType {
	pos,
	col,
	nor
}vecType;

class Figure{
protected:
	std::vector<unsigned short int> indices;
	std::vector <glm::vec4> data;
	int callForRefresh;
public:
	std::vector<unsigned short int> getIndices();
	void setIndices(std::vector<unsigned short int> readIndices);
	std::vector <glm::vec4> getData();
	void setData(std::vector <glm::vec4> readData);
	void updateIndiceCount(unsigned short int& index);
	int getDataCount();
	bool getIfRefresh();
	void setIfRefresh(bool readRefresh);
	void changePoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
};