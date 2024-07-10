#include"pch.h"
#include"Physics.h"

namespace Dino
{
	Physics::Physics()
	{
	}

	Physics::Physics(int gravity): mGravity(gravity)
	{
	}

	void Physics::NextPosition(Unit& unit, const Map& map)
	{
		int numOfIterations{ 0 };
		float xComponent{ (float)unit.GetSpeed().xSpeed };
		float yComponent{ (float)unit.GetSpeed().ySpeed };

		if (std::abs(xComponent) > std::abs(yComponent))
			numOfIterations = std::abs(unit.GetSpeed().xSpeed);
		else
			numOfIterations = std::abs(unit.GetSpeed().ySpeed);

		xComponent /= numOfIterations;
		yComponent /= numOfIterations;

		float currentX{ (float)unit.GetCoordinates().x };
		float currentY{ (float)unit.GetCoordinates().y };

		for (int i{ 0 }; i < numOfIterations; i++)
			if (PositionIsPossible(unit, map,
				{ int(currentX + xComponent), int(currentY + yComponent) }))
			{
				currentX += xComponent;
				currentY += yComponent;
			}
			else
				break;

		unit.SetCoordinates({(int)currentX, (int)currentY});
		
	}

	bool Physics::PositionIsPossible(const Unit& unit, const Map& map, Coordinates coords)
	{
		for(int i {0}; i< unit.GetHeight(); i++)
			for (int j{ 0 }; j < unit.GetWidth(); j++)
			{
				int x{ coords.x + j };
				int y{ coords.y + i };
				if (!map.GetPixelPassability({x,y}))
					return false;
			}

		return true;
	}

	void ApplyGravity(Unit& unit)
	{
		Speed speed{ unit.GetSpeed() };
		speed.ySpeed -= mGravity;
		unit.SetSpeed(speed);
	}

	int Physics::GetGravity() const
	{
		return mGravity;
	}

	void Physics::SetGravity(int newGravity)
	{
		mGravity = newGravity;
	}


}