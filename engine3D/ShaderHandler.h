#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint VBO;
    GLuint VAO;
    GLuint compileShader(const char* path, GLenum shaderType);
public:
    Shader();
    void use();
    int getProgramId();
    int getVBO();
    int getVAO();
};