#pragma once

#include"pch.h"
#include"Utils.h"
#include"Events.h"

namespace Dino 
{	
	constexpr int DEFAULT_FRAME_RATE{ 60 };
	class DINO_API DinoApp
	{
	public:
		DinoApp();

		virtual void OnUpdate();
		void Run();
		void SetFrameRate(int newFrameRate);

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback);
		void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback);

	private:
		int mFrameRate{ 0 }; //measured in frames per second

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration;

		bool mShouldContinue{ true };

		void DefautWindowCloseCallback(const WindowCloseEvent& event);
	};
}