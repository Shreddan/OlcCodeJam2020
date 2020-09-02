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
	pixelSX = 0;
	pixelSY = 0;
	currentMap = new Map(10, 10);
	currentMap->setupRooms();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	if (splash.AnimateSplashScreen(fElapsedTime)) return true;
	splash.SetDuration(2.0f);
	Clear(olc::BLACK);
	inputHandler(fElapsedTime);
	drawMap();
	return true;
}

void Engine::WorldtoScreen(float worldX, float worldY, int &screenX, int &screenY)
{
	screenX = (int)(worldX - offsetX);
	screenY = (int)(worldY - offsetY);
}

void Engine::ScreentoWorld(int screenX, int screenY, float &worldX, float &worldY)
{
	worldX = (float)(screenX) + offsetX;
	worldY = (float)(screenY) + offsetY;
}

void Engine::inputHandler(float fElapsedTime)
{

	if (GetMouse(0).bPressed)
	{
		PanX = GetMouseX();
		PanY = GetMouseY();
	}

	if (GetMouse(0).bHeld)
	{
		offsetX -= (GetMouseX() - PanX) * (fElapsedTime * 4);
		offsetY -= (GetMouseY() - PanY) * (fElapsedTime * 4);

		PanX = GetMouseX();
		PanY = GetMouseY();
	}
}

void Engine::drawMap()
{
	for (int x = 0; x < currentMap->mapWidth; x++)
	{
		for (int y = 0; y < currentMap->mapHeight; y++)
		{
			WorldtoScreen(x, y, pixelSX, pixelSY);
			DrawRect(olc::vi2d((pixelSX * Room::roomSize) + roomGap, (pixelSY * Room::roomSize) + roomGap),olc::vi2d(Room::roomSize - roomGap, Room::roomSize - roomGap), olc::BLUE);
		}
	}
}

void Engine::drawPlayer()
{
	
}
