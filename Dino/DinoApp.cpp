#include "pch.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "DinoApp.h"
#include"DinoWindow.h"
#include"Image.h"
#include"Shaders.h"
#include"stb_image.h"
#include"Renderer.h"

namespace Dino {
	DinoApp::DinoApp()
	{
		DinoWindow::Init();
		DinoWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		Renderer::Init();

		SetFrameRate(DEFAULT_FRAME_RATE);
	}
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) 
		{
			Renderer::Get()->ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			DinoWindow::GetWindow()->SwapBuffers();
			DinoWindow::GetWindow()->PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
	void DinoApp::SetFrameRate(int newFrameRate)
	{
		mFrameRate = newFrameRate;
		mFrameDuration = std::chrono::milliseconds{ 1000 } / mFrameRate;
	}
}