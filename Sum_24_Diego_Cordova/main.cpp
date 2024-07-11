#include "Dino.h"
#include <iostream>
#include <vector>

class BestGame : public Dino::DinoApp
{
public:
	BestGame() 
	{
		SetKeyPressedCallback([this](const Dino::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
			});

		map.LoadBackgroundImage("../Dino/Assets/Images/Background.png");
		std::vector<std::vector<bool>> util;
		for (int i{ 0 }; i < 213; i++)
			util.push_back(std::vector<bool>(1000, false));

		for (int i{ 0 }; i < 587; i++)
			util.push_back(std::vector<bool>(1000, true));
		map.LoadMapPassability(util);
		
		//unit.SetSpeed({ 1,1 });
	}

	virtual void OnUpdate() override
	{
		physics.NextPosition(unit, map);
		Dino::Renderer::Get()->Draw(map);
		Dino::Renderer::Get()->Draw(unit);
	}

private:
	//Dino::Image pic{ "../Dino/Assets/Images/temp.png" };//background 213 pixel high floor
	Dino::Unit unit{ "../Dino/Assets/Images/temp.png", {300,400} };
	Dino::Map map;
	Dino::Physics physics;

	void MyKeyPressedCallback(const Dino::KeyPressedEvent& key) {
		if (key.GetKey() == DINO_KEY_RIGHT) {
			unit.UpdateXBy(40);
		}
		else if (key.GetKey() == DINO_KEY_UP) {
			unit.UpdateYBy(40);
		}
		else if (key.GetKey() == DINO_KEY_LEFT) {
			unit.UpdateXBy(-40);
		}
		else if (key.GetKey() == DINO_KEY_DOWN) {
			unit.UpdateYBy(-40);
		}
	}
};

DINO_GAME_START(BestGame);