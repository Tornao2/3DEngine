#include "BitmapHandler.h"


int BitmapHandler::loadBitmap(std::string readPath) {
	int height, width, channels;
	unsigned char* temp = stbi_load(readPath.c_str(), &height, &width, &channels, 0);
	GLuint textureID;
	glGenTextures(1, &textureID);    
	glBindTexture(GL_TEXTURE_2D, textureID); 
	GLenum format = GL_RGB;
	if (channels == 4) 
		format = GL_RGBA;
	else if (channels == 3) 
		format = GL_RGB;
	else if (channels == 1) 
		format = GL_RED;
	else {
		stbi_image_free(temp);
		return -1;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, temp);
	glGenerateMipmap(GL_TEXTURE_2D); 
	stbi_image_free(temp);
	return textureID;
}

void BitmapHandler::deleteBitmap(int& readTextureId) {
	glDeleteTextures(1, (GLuint*) &readTextureId);
	readTextureId = 0;
}
