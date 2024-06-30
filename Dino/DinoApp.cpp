#include "pch.h"
#include "DinoApp.h"
#include"DinoWindow.h"

namespace Dino {
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		DinoWindow::Init();
		DinoWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		while (true) {
			OnUpdate();
			DinoWindow::GetWindow()->SwapBuffers();
			DinoWindow::GetWindow()->PollEvents();
		}
	}
}