#include "pch.h"
#include "DinoApp.h"

namespace Dino {
	void DinoApp::OnUpdate()
	{

	}

	void DinoApp::Run()
	{
		while (true) {
			OnUpdate();
		}
	}
}