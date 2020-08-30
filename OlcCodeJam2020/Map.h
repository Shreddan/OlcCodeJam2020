#pragma once
#include <vector>
#include <ctime>

struct Room
{
	Room();
	static const int roomSize = 30;
	
	bool* exits = nullptr;
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

