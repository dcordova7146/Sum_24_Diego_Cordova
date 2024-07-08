#pragma once

#include"Utils.h"


namespace Dino
{
	class DINO_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKey() const;

	private:
		int mKeyCode{ -1 };
	};

	class DINO_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int keyCode);
		int GetKey() const;

	private:
		int mKeyCode{ -1 };
	};

	class DINO_API WindowCloseEvent
	{

	};
}