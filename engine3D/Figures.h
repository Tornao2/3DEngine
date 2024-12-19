#pragma once
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Refreshable.h"
#include "EngineObject.h"

typedef enum vecType {
	pos,
	col,
	nor
}vecType;

class Figures: public virtual Refreshable, public virtual EngineObject {
protected:
	bool isTextured;
	std::vector <glm::vec4> data;
public:
	int getDataCount();
	std::vector <glm::vec4> getData();
	void setData(std::vector <glm::vec4> readData);
	void changePoint(std::vector <glm::vec4> point, int index);
	std::vector <glm::vec4> getPoint(int index);
	bool getTextured();
	void setTextured(bool readVal);
};