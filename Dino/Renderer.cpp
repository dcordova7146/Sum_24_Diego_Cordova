#include"pch.h"
#include"Renderer.h"
#include"ThirdParty/codeOpenGL/RendererOpenGL.h"
#include"DinoWindow.h"

namespace Dino
{
	void Renderer::Init()
	{
		if (!mInstance)
			mInstance = std::shared_ptr<Renderer>{ new Renderer };
		
	}
	std::shared_ptr<Renderer> Renderer::Get()
	{
		return mInstance;
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shaders);
	}

	void Renderer::Draw(Image& pic, int xCoord, int yCoord)
	{
		//mDefaultShaders.SetUniform2Ints(
		//	"ScreenSize",
		//	DinoWindow::GetWindow()->GetWidth(),
		//	DinoWindow::GetWindow()->GetHeight());
		mImplementation->Draw(pic, xCoord, yCoord);
	}

	Renderer::Renderer()
	{
#ifdef DINO_OPENGL
		mImplementation = std::make_unique<RendererOpenGL>();
#else
		#ERROR_TABLE_OPENGL_ISNT_DEFINED
#endif

	}
}