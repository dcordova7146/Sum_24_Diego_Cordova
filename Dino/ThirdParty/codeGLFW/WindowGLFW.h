#pragma once

#include"WindowImplementation.h"

namespace Dino
{
	class WindowGLFW : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		~WindowGLFW();
	private:
		 
		 

	};
}