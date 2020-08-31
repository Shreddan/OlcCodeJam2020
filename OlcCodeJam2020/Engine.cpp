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
	//offsetX = ScreenWidth() / 2;
	//offsetY = ScreenHeight() / 2;
	currentMap = new Map(10, 10);
	currentMap->setupRooms();
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	if (splash.AnimateSplashScreen(fElapsedTime)) return true;
	splash.SetDuration(4.0f);
	Clear(olc::BLACK);
	inputHandler();
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
	worldX = (float)(screenX + offsetX);
	worldY = (float)(screenY + offsetY);
}

void Engine::inputHandler()
{
	if (GetMouse(0).bPressed)
	{
		PanX = GetMouseX();
		PanY = GetMouseY();
	}

	if (GetMouse(0).bHeld)
	{
		offsetX -= (GetMouseX() - PanX);
		offsetY -= (GetMouseY() - PanY);

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
