#pragma once

#include"pch.h"
#include"Utils.h"
#include"WindowImplementation.h"
#include"Events.h"

namespace Dino
{
	class DINO_API DinoWindow
	{
	public:
		static void Init();
		static std::shared_ptr<DinoWindow> GetWindow(); //shared pointers have overhead

		void CreateWindow(int width, int height, const std::string& windowName);
		void CreateWindow(int width, int height, std::string&& windowName);
		int GetWidth() const;
		int GetHeight() const;
		void SwapBuffers();
		void PollEvents();

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback);
		void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback);


	private: //class member should have name convention m lowercase before it
		DinoWindow();
		inline static std::shared_ptr<DinoWindow> mInstance{ nullptr };

		std::unique_ptr<WindowImplementation> mImplementation{nullptr};
	};
}