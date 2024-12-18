#include "QuadsTextured.h"

QuadsTextured::QuadsTextured(std::vector <glm::vec4> readData) : Quads(readData){
	isTextured = true;
}