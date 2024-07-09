#pragma once

#include"pch.h"
#include"Utils.h"
#include"Image.h"
#include"Renderer.h"

namespace Dino
{
	struct DINO_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
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

		friend class Renderer;
	private:
		Coordinates mCoords;
		Image mSprite;

	};
}