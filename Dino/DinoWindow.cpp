#include"pch.h"

#include"DinoWindow.h"
#include"ThirdParty/codeGLFW/WindowGLFW.h"

namespace Dino
{
	DinoWindow::DinoWindow()
	{
#ifdef DINO_GLFW
			mImplementation = std::unique_ptr<WindowGLFW>{ new WindowGLFW };
#else
			#ERROR_DINO_GLFW_ISNT_DEFINED //fake error for precompiler
#endif
	}


	void DinoWindow::Init()
	{
		if (!mInstance)
			mInstance = std::make_shared<DinoWindow>(new DinoWindow);
	}

	std::shared_ptr<DinoWindow> DinoWindow::GetWindow()
	{
		return mInstance;
	}

	void DinoWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mImplementation->CreateWindow(width, height, windowName);
	}

	void DinoWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mImplementation->CreateWindow(width, height, std::move(windowName));
	}

	int DinoWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int DinoWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void DinoWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void DinoWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}

}