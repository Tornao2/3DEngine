 #include "CameraHandler.h"

CameraHandler::CameraHandler(Shader* readHandler){
	shader = readHandler;
	cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	yaw = 0.0f;
	pitch = 0.0f;
    lastX = 0.0;
    lastY = 0.0;
}

void CameraHandler::updateCamera() {
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    target = cameraPos + direction;
    modelViewMatrix = glm::lookAt(cameraPos, target, up);
    GLint modelViewLoc = glGetUniformLocation(shader->getProgramId(), "modelViewMatrix");
    glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, glm::value_ptr(modelViewMatrix));
}