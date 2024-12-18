#include "CubeTextured.h"

CubeTextured::CubeTextured(float rSideLength, float rx, float ry, float rz) {
    sideLength = rSideLength;
    x = rx;
    y = ry;
    z = rz;
    data = {
    { x, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength, y, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, {1.0f, 1.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z, 1.0f }, {  0.0f,  0.0f, -1.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f},
    { x, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, {1.0f, 1.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  0.0f,  1.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f},
    { x, y, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x, y, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, {1.0f, 1.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z + sideLength, 1.0f }, { -1.0f,  0.0f,  0.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f},
    { x + sideLength, y, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength, y, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, {1.0f, 1.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  1.0f,  0.0f,  0.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f},
    { x, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength, y, z, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f },{1.0f, 1.0f, 0.0f, 0.0f},
    { x, y, z + sideLength, 1.0f }, {  0.0f, -1.0f,  0.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, {0.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, {1.0f, 0.0f, 0.0f, 0.0f},
    { x + sideLength,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, {1.0f, 1.0f, 0.0f, 0.0f},
    { x,  y + sideLength, z + sideLength, 1.0f }, {  0.0f,  1.0f,  0.0f, 0.0f }, {0.0f, 1.0f, 0.0f, 0.0f}
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