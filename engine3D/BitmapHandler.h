#pragma once
#include "stb_image.h"
#include <string>
#include <GL/glew.h>

class BitmapHandler {
public:
	int loadBitmap(std::string readPath);
	void deleteBitmap(int& readTextureId);
};