#pragma once

#include"pch.h"
#include "Utils.h"

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

	private:
		int mFrameRate{ 0 }; //measured in frames per second

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration;
	};
}