#pragma once
#include "Gl/glut.h"
#include "chrono"

typedef struct Color {
	double r, g, b, a;
	Color(double red, double green, double blue, double alpha = 1.0f) : r(red), g(green), b(blue), a(alpha) {}
	Color() : r(0), g(0), b(0), a(1){}
}Color;

class Renderer {
private:
	void renderProper();
	static Renderer* instance;
	Color clearColor;
	bool enableZBuffer;
	bool enableDoubleBuffer;
public:
	Renderer(Color readClearColor = Color(), bool zBuffer = false, bool doubleBuffer = true);
	static void render();
	void setClearColor(Color readClearColor);
	Color getClearColor();
	void setZBuffer(bool should);
	void setDoubleBuffer(bool should);
	bool getZBuffer();
	bool getDoubleBuffer();
};