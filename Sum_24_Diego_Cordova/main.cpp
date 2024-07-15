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
		SetKeyReleasedCallback([this](const Dino::KeyReleasedEvent& key) {
			MyKeyReleasedCallback(key);
			});

		map.LoadBackgroundImage("../Dino/Assets/Images/Background2.png");
		std::vector<std::vector<bool>> util;
		for (int i{ 0 }; i < 213; i++)
			util.push_back(std::vector<bool>(1000, false));

		for (int i{ 0 }; i < 587; i++)
			util.push_back(std::vector<bool>(1000, true));
		map.LoadMapPassability(util);
		
		unit.SetHero();
		//use time to have unique seed for a unique game each time
		unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		srand(seed);

		//rock1.SetCoordinates({ 120,700 });
		rock1.SetInvisible();
		//rock2.SetCoordinates({ 320,700 });
		rock2.SetInvisible();
		//rock3.SetCoordinates({ 520,700 });
		rock3.SetInvisible();
		//rock4.SetCoordinates({ 720,700 });
		rock4.SetInvisible();
		//rock5.SetCoordinates({ 920,700 });
		rock5.SetInvisible();
		
		cross1.SetInvisible();
		cross2.SetInvisible();
		cross3.SetInvisible();

		GameOver.UpdateXBy(-(GameOver.GetWidth() / 2));
		GameOver.UpdateYBy(-(GameOver.GetHeight() / 2));
	
	}

	virtual void OnUpdate() override
	{
		if (hits < 3) {
			Dino::Renderer::Get()->Draw(map);

			//input handle based on state
			unit.Act();
			rock1.Act();
			rock2.Act();
			rock3.Act();
			rock4.Act();
			rock5.Act();

			//check collisions
			checkCollisions(rock1);
			checkCollisions(rock2);
			checkCollisions(rock3);
			checkCollisions(rock4);
			checkCollisions(rock5);
			
			//try re activate inactive meteor
			trySpawnMeteor(rock1);
			trySpawnMeteor(rock2);
			trySpawnMeteor(rock3);
			trySpawnMeteor(rock4);
			trySpawnMeteor(rock5);

			Dino::Renderer::Get()->Draw(rock1);
			Dino::Renderer::Get()->Draw(rock2);
			Dino::Renderer::Get()->Draw(rock3);
			Dino::Renderer::Get()->Draw(rock4);
			Dino::Renderer::Get()->Draw(rock5);

			Dino::Renderer::Get()->Draw(unit);

			Dino::Renderer::Get()->Draw(cross1);
			Dino::Renderer::Get()->Draw(cross2);
			Dino::Renderer::Get()->Draw(cross3);
		}
		else
		{
			//when die show game over screen
			Dino::Renderer::Get()->ClearScreen();
			Dino::Renderer::Get()->Draw(GameOver);
		}
	
	}

private:
	//Dino::Image pic{ "../Dino/Assets/Images/temp.png" };//background 213 pixel high floor
	Dino::Map map;
	Dino::Unit unit{ "../Dino/Assets/Images/dio.png", {400,215} };

	Dino::Unit rock1{ "../Dino/Assets/Images/rock1.png", { 100, 700}};
	Dino::Unit rock2{ "../Dino/Assets/Images/rock2.png", { 300, 700}};
	Dino::Unit rock3{ "../Dino/Assets/Images/rock1.png", { 500, 700}};
	Dino::Unit rock4{ "../Dino/Assets/Images/rock3.png", { 700, 700}};
	Dino::Unit rock5{ "../Dino/Assets/Images/rock2.png", { 900, 700}};

	Dino::Unit cross1{ "../Dino/Assets/Images/x.png", {780,70} }; //64x49
	Dino::Unit cross2{ "../Dino/Assets/Images/x.png", {860,70} }; 
	Dino::Unit cross3{ "../Dino/Assets/Images/x.png", {940,70} };

	Dino::Unit GameOver{ "../Dino/Assets/Images/gameover.png", {500,400} };

	int hits = 0;
	int framesSinceGameStart = 0;
	int difficulty = 0; //raised every second based on frames since start

	Dino::Physics physics;
	int framesSinceStart = 0;
	std::vector<std::string> meteorVariations{
		"../Dino/Assets/Images/rock1.png",
		"../Dino/Assets/Images/rock2.png"
		"../Dino/Assets/Images/rock3.png"
	};


	void MyKeyPressedCallback(const Dino::KeyPressedEvent& key) 
	{
		if (key.GetKey() == DINO_KEY_RIGHT) {
			unit.SetState(Dino::Unit::State::moving);
			unit.SetDir(Dino::Unit::Direction::right);
			//unit.UpdateXBy(40);
		}
		else if (key.GetKey() == DINO_KEY_LEFT) {
			unit.SetState(Dino::Unit::State::moving);
			unit.SetDir(Dino::Unit::Direction::left);
			//unit.UpdateXBy(-40);
		}
	}

	void MyKeyReleasedCallback(const Dino::KeyReleasedEvent& key)
	{
		unit.SetState(Dino::Unit::State::idle);
	}

	void trySpawnMeteor(Dino::Unit& rock) {
		if (2 >= rand() % 1000)
		{
			if (rock.GetState() == Dino::Unit::State::idle)
			{
				rock.SetVisible();
				rock.SetState(Dino::Unit::State::Active);
			}
		}
		/* attempt for random area
		int chance = rand() % 100;
		DINO_LOG("Spawning rock");
		if (chance <= 2)
		{
			DINO_LOG("Rock Spawn");
			//Dino::Unit rock("../Dino/Assets/Images/dio.png",
			//Dino::Coordinates(map.GetHeight(), rand() % map.GetWidth()));
			//rock.SetSpeed(Dino::Speed(1, -1));
			index++;
			meteors.emplace_back(Dino::Unit(
				meteorVariations[index % meteorVariations.size()],
				Dino::Coordinates(rand() % map.GetWidth()-50, map.GetHeight()-50)));
			//return rock;
		}
		*/
	}

	void checkCollisions(Dino::Unit& rock) {
		if (rock.GetState() == Dino::Unit::State::Active)
		{
			if (rock.OverlapsWith(unit)) {
				rock.UpdateYBy(500);
				rock.SetState(Dino::Unit::State::idle);
				rock.SetInvisible();
				takeLife();
			}
			if (rock.GetCoordinates().y <= 215) {
				rock.UpdateYBy(490);
				rock.SetState(Dino::Unit::State::idle);
				rock.SetInvisible();
			}

		}
	}

	void takeLife()
	{
		hits += 1;
		if (hits == 1) {
			cross1.SetVisible();
		}if (hits == 2) {
			cross2.SetVisible();
		}if (hits == 3) {
			cross3.SetVisible();
		}
	}


};


DINO_GAME_START(BestGame);