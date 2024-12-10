#pragma once
#include <GL/glut.h>
#include <vector>
#include <glm/glm.hpp>

class Primitive {
protected:
	std::vector <glm::vec4> data;
	int size;
	int callForRefresh;
public:
	std::vector <glm::vec4> getData();
	void setData(std::vector <glm::vec4> readData);
	void virtual drawFigure(int index) {};
	int getSize();
	void setSize(int readSize);
	int getDataCount();
	void updateIndex(int& index);
	bool getIfRefresh();
	void setIfRefresh(bool readRefresh);
};