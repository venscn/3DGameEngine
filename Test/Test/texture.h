#ifndef TEXTURE_H
#define TEXTURE_H

#if defined(__APPLE__) || defined(__MACH__)
#define OS_MACOSX
#endif

#ifdef OS_MACOSX
#include "glew.h"
#else
#include <GL/glew.h>
#endif

#include "referenceCounter.h"
#include <string>
#include <map>

class TextureData : public ReferenceCounter
{
public:
	TextureData(GLenum textureTarget);
	virtual ~TextureData();
	
	inline GLenum GetTextureTarget() { return m_textureTarget; }
	inline GLuint GetTextureID() { return m_textureID; }
protected:	
private:
	TextureData(TextureData& other) {}
	void operator=(TextureData& other) {}

	GLenum m_textureTarget;
	GLuint m_textureID;
};

class Texture
{
public:
	Texture(const std::string& fileName, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	Texture(int width = 0, int height = 0, unsigned char* data = 0, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	virtual ~Texture();

	void Bind(unsigned int unit = 0) const;	
protected:
private:
	static std::map<std::string, TextureData*> s_resourceMap;
	static const TextureData* s_lastBind;

	Texture(Texture& texture) {}
	void operator=(Texture& texture) {}

	TextureData* m_textureData;
	std::string m_fileName;

	void InitTexture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter);
};

#endif