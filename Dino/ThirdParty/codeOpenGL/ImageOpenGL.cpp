#include"pch.h"

#include"ImageOpenGL.h"
#include"glad/glad.h"
#include"stb_image.h"
#include"Utils.h"

namespace Dino
{
	ImageOpenGL::ImageOpenGL(const std::string& fileName)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);
		//set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(fileName.c_str(), &mWidth, &mHeight, &mNumOfChannels, 0); 
		if (data)
		{
			if(mNumOfChannels==4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); 
			else
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			DINO_ERROR("ERROR: Failed to load texture");

		}
		stbi_image_free(data);
	}

	ImageOpenGL::ImageOpenGL(std::string&& fileName)
	{

		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);
		//set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(fileName.c_str(), &mWidth, &mHeight, &mNumOfChannels, 0);
		if (data)
		{
			if (mNumOfChannels == 4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			else
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			DINO_ERROR("ERROR: Failed to load texture");

		}
		stbi_image_free(data);
	}

	ImageOpenGL::~ImageOpenGL()
	{
		glDeleteTextures(1, &mTexture);
	}

	void ImageOpenGL::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}

	int ImageOpenGL::GetWidth()
	{
		return mWidth;
	}

	int ImageOpenGL::GetHeight()
	{
		return mHeight;
	}
}