#include "Dino.h"
#include <iostream>

class BestGame : public Dino::DinoApp
{
public:
	BestGame() 
	{
		SetKeyPressedCallback([this](const Dino::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
			});
	}

	virtual void OnUpdate() override
	{
		Dino::Renderer::Get()->Draw(pic, x, 200);
	}

private:
	Dino::Image pic{ "../Dino/Assets/Images/temp.png" };

	int x{ 100 };

	void MyKeyPressedCallback(const Dino::KeyPressedEvent& key) {
		if (key.GetKey() == DINO_KEY_RIGHT)
			x += 40;
	}
};

DINO_GAME_START(BestGame);