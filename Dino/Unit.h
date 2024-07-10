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

		friend class Renderer;

	private:
		Coordinates mCoords;
		Image mSprite;
		bool mIsVisible{ true };
		Speed mSpeed;

	};
}