#pragma once

#include"pch.h"
#include"Utils.h"
#include"Image.h"

namespace Dino
{
	struct DINO_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
	};

	struct DINO_API Speed
	{
		int xSpeed{ 0 };
		int ySpeed{ 0 };

		Speed();
		Speed(int xComponent, int yComponent);
	};

	class DINO_API Unit
	{
	public:
		enum class State
		{
			Active, idle, moving
		};

		enum class Direction
		{
			left, right
		};

		Unit(const std::string& fileName, Coordinates newCoordinates);
		Unit(std::string&& fileName, Coordinates newCoordinates);
		//Unit(std::vector<std::string> fileNames, Coordinates newCoordinates, bool isHero);

		void SetCoordinates(Coordinates newCoordinates);
		Coordinates GetCoordinates() const;

		void LoadSprite(const std::string& fileName);
		void LoadSprite(std::string&& fileName);

		bool OverlapsWith(const Unit& other) const;
		
		void UpdateXBy(int amount);
		void UpdateYBy(int amount);
		
		int GetHeight() const;
		int GetWidth() const;

		Speed GetSpeed() const;
		void SetSpeed(Speed newSpeed);
		void UpdateSpeed(int xChange, int yChange);

		bool IsVisible() const;
		void SetVisible();
		void SetInvisible();

		void SetState(State newState);
		State GetState() const;

		void SetDir(Direction newDir);
		Direction GetDir() const;

		/// 
		void SetHero();
		void Act();


		friend class Renderer;

	private:
		Coordinates mCoords;
		std::vector<Image> mSpriteSheet;
		Image mSprite;
		bool mIsVisible{ true };
		Speed mSpeed;

		///
		bool misHero;
		State mState;
		Direction mDir;
			
	};
}