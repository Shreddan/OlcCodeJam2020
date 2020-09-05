#pragma once
#include <vector>
#include <ctime>

#include "Crafting.h"

struct Room
{
	Room();
	int x, y;
	static const int roomSize = 75;
	bool isStart = false;
	bool* exits = nullptr;
	std::vector<CraftingItem> floor;
};

class Map
{
public:
	Map(size_t mapWidth, size_t mapHeight);
	~Map();

	size_t mapWidth;
	size_t mapHeight;

	Room* rooms = nullptr;

	void setupRooms();

};

