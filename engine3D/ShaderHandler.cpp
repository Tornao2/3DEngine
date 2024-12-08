#include "ShaderHandler.h"

Shader::Shader() {
    programID = glCreateProgram();
    vertexShaderID = compileShader("shader.vert", GL_VERTEX_SHADER);
    fragmentShaderID = compileShader("shader.frag", GL_FRAGMENT_SHADER);
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);
    GLint success;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[4096];
        glGetProgramInfoLog(programID, sizeof(infoLog), NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << std::endl;
    }
    setupBuffers();
}

void Shader::use() {
    glUseProgram(programID);
}

GLuint Shader::compileShader(const char* path, GLenum shaderType) {
    std::string shaderCode;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        std::cerr << "ERROR::SHADER::FILE_NOT_READABLE: " << path << std::endl;
    }
    const char* shaderCodeCStr = shaderCode.c_str();
    GLuint shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &shaderCodeCStr, NULL);
    glCompileShader(shaderID);
    GLint success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shaderID;
}

int Shader::getProgramId() {
    return programID;
}

void Shader::setupBuffers() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (GLvoid*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int Shader::getVBO() {
    return VBO;
}

int Shader::getVAO() {
    return VAO;
}