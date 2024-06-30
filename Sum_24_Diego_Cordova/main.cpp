#include "Dino.h"
#include <iostream>

class BestGame : public Dino::DinoApp 
{
	virtual void OnUpdate() override
	{
		//DINO_LOG("Running"<<"\n")
	}

};

DINO_GAME_START(BestGame);