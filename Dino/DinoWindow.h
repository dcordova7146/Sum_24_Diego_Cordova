#pragma once

#include"pch.h"
#include "Utils.h"

namespace Dino
{
	class DINO_API DinoWindow
	{
	public:

		void CreateWindow(int width, int height, const std::string& windowName);
		void CreateWindow(int width, int height, std::string&& windowName);
		int GetWidth() const;
		int GetHeight() const;


	private: //class member should have name convention m lowercase before it
		std::unique_ptr<WindowImplementation> mImplementation{nullptr};
	};
}