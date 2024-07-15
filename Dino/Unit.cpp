#include"pch.h"
#include"Unit.h"

namespace Dino
{
	Coordinates::Coordinates(): x(0), y(0)
	{
	}

	Coordinates::Coordinates(int xVal, int yVal): x(xVal), y(yVal)
	{
	}

	Unit::Unit(const std::string& fileName, Coordinates newCoordinates): mCoords(newCoordinates)
	{
		LoadSprite(fileName);
		misHero = false;
		mState = State::idle;
		
	}

	Unit::Unit(std::string&& fileName, Coordinates newCoordinates): mCoords(newCoordinates)
	{
		LoadSprite(std::move(fileName));
		mState = State::idle;
		misHero = false;

	}

	void Unit::SetCoordinates(Coordinates newCoordinates)
	{
		mCoords = newCoordinates;
	}

	Coordinates Unit::GetCoordinates() const
	{
		return mCoords;
	}

	void Unit::LoadSprite(const std::string& fileName)
	{
		mSprite.LoadImage(fileName);
	}

	void Unit::LoadSprite(std::string&& fileName)
	{
		mSprite.LoadImage(std::move(fileName));
	}

	bool Unit::OverlapsWith(const Unit& other) const
	{
		bool overlapsOnX{
			(mCoords.x >= other.mCoords.x && mCoords.x <= other.mCoords.x + other.GetWidth()) ||
			(mCoords.x <= other.mCoords.x && other.mCoords.x <= mCoords.x + GetWidth() )
		};


		bool overlapsOnY{ 
			(mCoords.y >= other.mCoords.y && mCoords.y <= other.mCoords.y + other.GetHeight()) ||
			(mCoords.y <= other.mCoords.y && other.mCoords.y <= mCoords.y + GetHeight()) 
		};


		return overlapsOnX && overlapsOnY;
	}

	void Unit::UpdateXBy(int amount)
	{
		mCoords.x += amount;
	}

	void Unit::UpdateYBy(int amount)
	{
		mCoords.y += amount;
	}

	int Unit::GetHeight() const
	{
		return mSprite.GetHeight();
	}

	int Unit::GetWidth() const
	{
		return mSprite.GetWidth();
	}

	Speed Unit::GetSpeed() const
	{
		return mSpeed;
	}

	void Unit::SetSpeed(Speed newSpeed)
	{
		mSpeed = newSpeed;
	}

	void Unit::UpdateSpeed(int xChange, int yChange)
	{
		mSpeed.xSpeed += xChange;
		mSpeed.ySpeed += yChange;
	}

	bool Unit::IsVisible() const
	{
		return mIsVisible;
	}

	void Unit::SetVisible()
	{
		mIsVisible = true;
	}

	void Unit::SetInvisible()
	{
		mIsVisible = false;
	}

	void Unit::SetState(State newState)
	{
		mState = newState;
	}

	Dino::Unit::State Unit::GetState() const
	{
		return mState;
	}

	void Unit::SetDir(Direction newDir)
	{
		mDir = newDir;
	}

	Dino::Unit::Direction Unit::GetDir() const
	{
		return Direction();
	}

	void Unit::SetHero()
	{
		misHero = true;
	}

	void Unit::Act()
	{
		if (misHero)
		{
			if (mState == State::moving)
			{
				if (mDir == Direction::left)
					mCoords.x -= 25;

				else if (mDir == Direction::right)
					mCoords.x += 25;
			}
		}
		else
		{
			if (mState == State::Active)
				mCoords.y -= 10;
		}

	}

	Speed::Speed()
	{
	}

	Speed::Speed(int xComponent, int yComponent): xSpeed(xComponent), ySpeed(yComponent)
	{
	}
}

