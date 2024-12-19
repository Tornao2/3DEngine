#include "ShaderHandler.h"

Shader::Shader() {
    createFlatProgram();
    createSmoothProgram();
    glGenBuffers(1, &VBO);
    createVAO();
    isSmooth = true;
}

void Shader::createVAO() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 12, (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 12, (GLvoid*)(sizeof(float) * 4));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 12, (GLvoid*)(sizeof(float) * 8));
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Shader::createFlatProgram() {
    vertexShaderID = compileShader("flatShader.vert", GL_VERTEX_SHADER);
    fragmentShaderID = compileShader("flatShader.frag", GL_FRAGMENT_SHADER);
    flatProgramID = glCreateProgram();
    glAttachShader(flatProgramID, vertexShaderID);
    glAttachShader(flatProgramID, fragmentShaderID);
    glLinkProgram(flatProgramID);
    GLint success;
    glGetProgramiv(flatProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[4096];
        glGetProgramInfoLog(flatProgramID, sizeof(infoLog), NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << std::endl;
    }
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void Shader::createSmoothProgram() {
    vertexShaderID = compileShader("shader.vert", GL_VERTEX_SHADER);
    fragmentShaderID = compileShader("shader.frag", GL_FRAGMENT_SHADER);
    smoothProgramID = glCreateProgram();
    glAttachShader(smoothProgramID, vertexShaderID);
    glAttachShader(smoothProgramID, fragmentShaderID);
    glLinkProgram(smoothProgramID);
    GLint success;
    glGetProgramiv(smoothProgramID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[4096];
        glGetProgramInfoLog(smoothProgramID, sizeof(infoLog), NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED " << infoLog << std::endl;
    }
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void Shader::use() {
    if (isSmooth)
        glUseProgram(smoothProgramID);
    else 
        glUseProgram(flatProgramID);
}

GLuint Shader::compileShader(const char* readPath, GLenum readShaderType) {
    std::string shaderCode;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(readPath);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        std::cerr << "ERROR::SHADER::FILE_NOT_READABLE: " << e.what() << readPath << std::endl;
    }
    const char* shaderCodeCStr = shaderCode.c_str();
    GLuint shaderID = glCreateShader(readShaderType);
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

int Shader::getVBO() {
    return VBO;
}

int Shader::getVAO() {
    return VAO;
}

int Shader::getProgramId() {
    if (isSmooth)
        return smoothProgramID;
    else
        return flatProgramID;
}

void Shader::switchShading() {
    isSmooth = !isSmooth;
}