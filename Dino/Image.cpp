#include"pch.h"

#include"Image.h"
#include"ThirdParty/codeOpenGL/ImageOpenGL.h"

namespace Dino
{
	Image::Image(const std::string& fileName)
	{
#ifdef DINO_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>{ fileName };
#else
		#ERROR_DINO_OPENGL_ISNT_DEFINED //fake error for precomplier
#endif
	}

	Image::Image(std::string&& fileName)
	{
#ifdef DINO_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>{ std::move(fileName) };
#else
		#ERROR_DINO_OPENGL_ISNT_DEFINED //fake error for precomplier
#endif
	}

	void Image::Bind()
	{
		mImplementation->Bind();
	}

	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}


	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
}

