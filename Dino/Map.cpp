#include"pch.h"

#include"Map.h"

namespace Dino
{
	void Map::LoadBackgroundImage(const std::string& fileName)
	{
		mBackground.LoadImage(fileName);

		mPassable.resize(mBackground.GetHeight());
		for (auto& row : mPassable)
			row.resize(mBackground.GetWidth(), true);
	}

	void Map::LoadBackgroundImage(std::string&& fileName)
	{
		mBackground.LoadImage(std::move(fileName));

		mPassable.resize(mBackground.GetHeight());
		for (auto& row : mPassable)
			row.resize(mBackground.GetWidth(), true);
	}

	void Map::LoadMapPassability(std::vector<std::vector<bool>> pixelPassability)
	{
		//assume backgrounds the user give are rectangle shaped
		if (pixelPassability.size() != mBackground.GetHeight() || pixelPassability.size() == 0 ||
			pixelPassability[0].size() != mBackground.GetWidth())
		{
			DINO_ERROR("ERROR: LoadMapPassability got bad paramaters!!!");
			return;
		}
		mPassable = std::move(pixelPassability);
	}

	void Map::LoadPixelPassability(Coordinates coords, bool isPassable)
	{
		if (coords.x >= mBackground.GetWidth() || coords.y >= mBackground.GetHeight())
		{
			DINO_ERROR("ERROR: LoadPixelPassability got out of range coordinates");
			return;
		}

		mPassable[coords.y][coords.x] = isPassable;
	}

	

	bool Map::GetPixelPassability(Coordinates coords) const
	{
		if (coords.y >= mPassable.size() || coords.x >= mPassable[0].size())
			return false;

		return mPassable[coords.y][coords.x];
	}

	int Map::GetWidth() const
	{
		return mBackground.GetWidth();
	}

	int Map::GetHeight() const
	{
		return mBackground.GetHeight();
	}
}