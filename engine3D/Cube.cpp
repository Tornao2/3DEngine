#include "Cube.h"

Cube::Cube(float rSideLength, float rx, float ry, float rz, std::vector <glm::vec4> colors) {
    sideLength = rSideLength;
    x = rx;
    y = ry;
    z = rz;
    data = {
    { x, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, colors[0],
    { x + sideLength, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, colors[1],
    { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, colors[2],
    { x,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, colors[3],
    { x, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, colors[4],
    { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, colors[5],
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, colors[6],
    { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, colors[7],
    { x, y, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, colors[8],
    { x, y, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, colors[9],
    { x,  y + sideLength, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, colors[10],
    { x,  y + sideLength, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, colors[11],
    { x + sideLength, y, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, colors[12],
    { x + sideLength, y, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, colors[13],
    { x + sideLength,  y + sideLength, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, colors[14],
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, colors[15],
    { x, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, colors[16],
    { x + sideLength, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, colors[17],
    { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, colors[18],
    { x, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, colors[19],
    { x,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, colors[20],
    { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, colors[21],
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, colors[22],
    { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, colors[23]
    };
    indices = {
        0, 1, 2,  0, 2, 3,
        4, 5, 6,  4, 6, 7,
        8, 9, 10, 8, 10, 11,
        12, 13, 14, 12, 14, 15,
        16, 17, 18, 16, 18, 19,
        20, 21, 22, 20, 22, 23
    };
}
