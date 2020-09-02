#include "Map.h"

Map::Map(size_t Width, size_t Height)
{
	this->mapWidth = Width;
	this->mapHeight = Height;
	this->rooms = new Room[(size_t)mapWidth * mapHeight];
}

Map::~Map()
{
}

void Map::setupRooms()
{
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			rooms[y * mapWidth + x].x = x * Room::roomSize;
			rooms[y * mapWidth + x].y = y * Room::roomSize;
			rooms[y * mapWidth + x].exits[0] = true;
			rooms[y * mapWidth + x].exits[1] = rand() % 1;
			rooms[y * mapWidth + x].exits[2] = rand() % 1;
			rooms[y * mapWidth + x].exits[3] = rand() % 1;
		}
	}
}

Room::Room()
{
	this->exits = new bool[4]{false, false, false ,false};
}
