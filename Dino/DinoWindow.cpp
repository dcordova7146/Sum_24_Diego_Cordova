#include"pch.h"

#include"DinoWindow.h"

namespace Dino
{
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

}