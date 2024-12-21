#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    /** ID programu shadera dla g³adkiego cieniowania. */
    GLuint smoothProgramID;
    /** ID programu shadera dla cieniowania p³askiego. */
    GLuint flatProgramID;
    /** ID shadera wierzcho³ków. */
    GLuint vertexShaderID;
    /** ID shadera fragmentów. */
    GLuint fragmentShaderID;
    /** ID bufora wierzcho³ków (VBO). */
    GLuint VBO;
    /** ID obiektu przestrzeni wierzcho³ków (VAO). */
    GLuint VAO;
    /**
     * Kompiluje shader z pliku.
     * @param readPath Œcie¿ka do pliku shadera.
     * @param readShaderType Typ shadera (wierzcho³kowy lub fragmentowy).
     * @return ID skompilowanego shadera.
     */
    GLuint compileShader(const char* readPath, GLenum readShaderType);
    /** Tworzy program shaderów dla p³askiego cieniowania. */
    void createFlatProgram();
    /** Tworzy program shaderów dla cieniowania g³adkiego. */
    void createSmoothProgram();
    /** Tworzy obiekt przestrzeni wierzcho³ków (VAO). */
    void createVAO();
    /** Flaga okreœlaj¹ca, czy u¿ywany jest g³adki shading. */
    bool isSmooth;
public:
    /** Konstruktor domyœlny klasy Shader. */
    Shader();
    /**
     * U¿ywa programu shaderów do renderowania.
     */
    void use();
    /**
     * Zwraca ID programu shadera.
     * @return ID programu shadera.
     */
    int getProgramId();
    /**
     * Zwraca ID bufora wierzcho³ków (VBO).
     * @return ID bufora wierzcho³ków.
     */
    int getVBO();
    /**
     * Zwraca ID obiektu przestrzeni wierzcho³ków (VAO).
     * @return ID obiektu przestrzeni wierzcho³ków.
     */
    int getVAO();
    /**
     * Prze³¹cza miêdzy p³askim cieniowaniem a g³adkim cieniowaniem.
     */
    void switchShading();
};
