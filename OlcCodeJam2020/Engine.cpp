#include "Engine.h"

Engine::Engine()
{
	sAppName = "OLC CodeJam 2020";
}
Engine::~Engine()
{
	OnUserDestroy();
}

bool Engine::OnUserCreate()
{
	srand(time(NULL));
	currentMap = new Map(10, 10);
	currentMap->setupRooms();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);
	drawMap();
	return true;
}

void Engine::WorldtoScreen(float worldX, float worldY, int screenX, int screenY)
{
	screenX = (int)(worldX - offsetX);
	screenY = (int)(worldY - offsetY);
}

void Engine::ScreentoWorld(int screenX, int screenY, float worldX, float worldY)
{
	worldX = (float)(screenX + offsetX);
	worldY = (float)(screenY + offsetY);
}

void Engine::drawMap()
{
	for (int x = 0; x < currentMap->mapWidth; x++)
	{
		for (int y = 0; y < currentMap->mapHeight; y++)
		{
			DrawRect(olc::vi2d(x, y), olc::vi2d(x * Room::roomSize, y * Room::roomSize), olc::BLUE);
			//DrawLine(olc::vi2d(x * Room::roomSize, y * Room::roomSize), olc::vi2d(x * Room::roomSize + Room::roomSize, y * Room::roomSize + Room::roomSize), olc::RED);
		}
	}
}
