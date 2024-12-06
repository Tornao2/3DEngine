#pragma once
#include "Gl/glut.h"
#include "Color.h"

class Renderer {
private:
	void renderProper();
	void prepareView();
	static Renderer* instance;
	Color clearColor;
	bool enableZBuffer;
	bool orthogonalView;
public:
	Renderer(Color readClearColor = Color(), bool zBuffer = true, bool shouldOrthogonal = false);
	static void render();
	void setClearColor(Color readClearColor);
	Color getClearColor();
	void setZBuffer(bool should);
	bool getZBuffer();
	bool getOrthogonal();
	void setOrthogonal(bool shouldOrthogonal);
};