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

		SetWindowCloseCallback([this](const WindowCloseEvent& event) {DefautWindowCloseCallback(event); });
	}
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue) 
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

	void DinoApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		DinoWindow::GetWindow()->SetKeyPressedCallBack(newCallback);
	}

	void DinoApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		DinoWindow::GetWindow()->SetKeyReleasedCallBack(newCallback);
	}

	void DinoApp::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		DinoWindow::GetWindow()->SetWindowCloseCallBack(newCallback);
		
	}

	void DinoApp::DefautWindowCloseCallback(const WindowCloseEvent& event)
	{
		mShouldContinue = false;
	}
}