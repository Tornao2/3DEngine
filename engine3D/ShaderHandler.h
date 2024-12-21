#pragma once
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
    /** ID programu shadera dla g�adkiego cieniowania. */
    GLuint smoothProgramID;
    /** ID programu shadera dla cieniowania p�askiego. */
    GLuint flatProgramID;
    /** ID shadera wierzcho�k�w. */
    GLuint vertexShaderID;
    /** ID shadera fragment�w. */
    GLuint fragmentShaderID;
    /** ID bufora wierzcho�k�w (VBO). */
    GLuint VBO;
    /** ID obiektu przestrzeni wierzcho�k�w (VAO). */
    GLuint VAO;
    /**
     * Kompiluje shader z pliku.
     * @param readPath �cie�ka do pliku shadera.
     * @param readShaderType Typ shadera (wierzcho�kowy lub fragmentowy).
     * @return ID skompilowanego shadera.
     */
    GLuint compileShader(const char* readPath, GLenum readShaderType);
    /** Tworzy program shader�w dla p�askiego cieniowania. */
    void createFlatProgram();
    /** Tworzy program shader�w dla cieniowania g�adkiego. */
    void createSmoothProgram();
    /** Tworzy obiekt przestrzeni wierzcho�k�w (VAO). */
    void createVAO();
    /** Flaga okre�laj�ca, czy u�ywany jest g�adki shading. */
    bool isSmooth;
public:
    /** Konstruktor domy�lny klasy Shader. */
    Shader();
    /**
     * U�ywa programu shader�w do renderowania.
     */
    void use();
    /**
     * Zwraca ID programu shadera.
     * @return ID programu shadera.
     */
    int getProgramId();
    /**
     * Zwraca ID bufora wierzcho�k�w (VBO).
     * @return ID bufora wierzcho�k�w.
     */
    int getVBO();
    /**
     * Zwraca ID obiektu przestrzeni wierzcho�k�w (VAO).
     * @return ID obiektu przestrzeni wierzcho�k�w.
     */
    int getVAO();
    /**
     * Prze��cza mi�dzy p�askim cieniowaniem a g�adkim cieniowaniem.
     */
    void switchShading();
};
