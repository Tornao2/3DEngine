#include "TransformableFigure.h"

void TransformableFigure::translate(glm::vec3 readChange) {
    for (int i = 0; i < data.size(); i += 3) {
        data[i].x += readChange.x;
        data[i].y += readChange.y;
        data[i].z += readChange.z;
    }
    callForRefresh = true;
}

void TransformableFigure::rotate(float readAngle, glm::vec3 readAxis) {
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(readAngle), readAxis);
    for (int i = 0; i < data.size(); i += 3)
        data[i] = rotationMatrix * data[i];
    callForRefresh = true;
}

void TransformableFigure::scale(float readScale) {
    if (readScale < 0) readScale = 1;
        for (int i = 0; i < data.size(); i += 3) {
            data[i].x *= readScale;
            data[i].y *= readScale;
            data[i].z *= readScale;
        }
        callForRefresh = true;
}

void TransformableFigure::freeTransform(glm::mat4 readMatrix) {
    for (int i = 0; i < data.size(); i += 3)
        data[i] = readMatrix * data[i];
    callForRefresh = true;
}