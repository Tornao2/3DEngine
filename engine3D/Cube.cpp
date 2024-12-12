#include "Cube.h"

Cube::Cube(std::vector <glm::vec4> readData, std::vector<float> readIndices) {
	for (int i = 0; i < readData.size(); i += 3) {
		posVec.push_back(readData[i]);
	}
	indices = readIndices;
	for (int i = 0; i < 5; i++)
		indicesPerSide.push_back(6);
}

void Cube::drawFigure() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(4, GL_FLOAT, 0, posVec.data());
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, norVec.data());
	glEnableClientState(GL_COLOR_ARRAY);	
	glColorPointer(4, GL_FLOAT, 0, posVec.data());
	glDrawElements(GL_TRIANGLES, sizeof(indices.size()), GL_UNSIGNED_BYTE, indices.data());
}

