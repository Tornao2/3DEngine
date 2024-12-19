#include "Cube.h"

Cube::Cube(float readSideLength, float readX, float readY, float readZ, std::vector <glm::vec4> readColors) {
    sideLength = readSideLength;
    x = readX;
    y = readY;
    z = readZ;
    if (readColors.size()) {
        data = {
        { x, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, readColors[0],
        { x + sideLength, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, readColors[1],
        { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, readColors[2],
        { x,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, readColors[3],
        { x, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, readColors[4],
        { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, readColors[5],
        { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, readColors[6],
        { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, readColors[7],
        { x, y, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, readColors[8],
        { x, y, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, readColors[9],
        { x,  y + sideLength, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, readColors[10],
        { x,  y + sideLength, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, readColors[11],
        { x + sideLength, y, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, readColors[12],
        { x + sideLength, y, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, readColors[13],
        { x + sideLength,  y + sideLength, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, readColors[14],
        { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, readColors[15],
        { x, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, readColors[16],
        { x + sideLength, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, readColors[17],
        { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, readColors[18],
        { x, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, readColors[19],
        { x,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, readColors[20],
        { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, readColors[21],
        { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, readColors[22],
        { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, readColors[23]
        };
    }
    indices = {
        0, 1, 2,  0, 2, 3,
        4, 5, 6,  4, 6, 7,
        8, 9, 10, 8, 10, 11,
        12, 13, 14, 12, 14, 15,
        16, 17, 18, 16, 18, 19,
        20, 21, 22, 20, 22, 23
    };
}