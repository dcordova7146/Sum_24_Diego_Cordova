#include "pch.h"
#include "DinoApp.h"
#include"DinoWindow.h"

namespace Dino {
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		DinoWindow window;
		window.CreateWindow(1000, 800, "Test");

		while (true) {
			OnUpdate();
			window.SwapBuffers();
			window.PollEvents();
		}
	}
}