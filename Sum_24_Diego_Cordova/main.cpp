#include "Dino.h"
#include <iostream>

class BestGame : public Dino::DinoApp
{
public:

	virtual void OnUpdate() override
	{
		Dino::Renderer::Get()->Draw(pic, x, 200);
		x += 2;
	}

private:
	Dino::Image pic{ "../Dino/Assets/Images/temp.png" };

	int x{ 100 };
};

DINO_GAME_START(BestGame);