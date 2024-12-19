#include "Quads.h"

Quads::Quads(std::vector <glm::vec4> readData) {
	data = readData;
}

void Quads::drawDirect(int index) {
	glDrawArrays(GL_QUADS, index, 4);
}