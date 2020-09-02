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
	currentMap->rooms[rand() % (currentMap->mapWidth * currentMap->mapHeight)].isStart = true;

	for (int x = 0; x < currentMap->mapWidth; x++)
	{
		for (int y = 0; y < currentMap->mapHeight; y++)
		{
			if (currentMap->rooms[y * currentMap->mapWidth + x].isStart)
			{
				player.x = currentMap->rooms[y * currentMap->mapWidth + x].x + (Room::roomSize / 2);
				player.y = currentMap->rooms[y * currentMap->mapWidth + x].y + (Room::roomSize / 2);
			}
		}
	}
	return true;
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
	if (splash.AnimateSplashScreen(fElapsedTime)) return true;
	splash.SetDuration(2.0f);
	Clear(olc::BLACK);
	StateManager();
	inputHandler(fElapsedTime);
	return true;
}

void Engine::StateManager()
{
	switch (gameState)
	{
		case Begin:
		{

			gameState = Main;
			break;
		}
		case Main:
		{
			drawMap();
			drawPlayer();
			break;
		}
		case Pause:
		{
			break;
		}
		case End:
		{
			break;
		}
		default:
			break;
	}
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

}

void Engine::drawMap()
{
	for (int x = 0; x < currentMap->mapWidth; x++)
	{
		for (int y = 0; y < currentMap->mapHeight; y++)
		{
			WorldtoScreen(currentMap->rooms[y * currentMap->mapWidth + x].x, currentMap->rooms[y * currentMap->mapWidth + x].y, pixelSX, pixelSY);

			if (currentMap->rooms[y * currentMap->mapWidth + x].isStart)
			{
				FillRect(olc::vi2d((pixelSX * Room::roomSize) + roomGap, (pixelSY * Room::roomSize) + roomGap), olc::vi2d(Room::roomSize - roomGap, Room::roomSize - roomGap), olc::GREEN);
			}
			else
			{
				FillRect(olc::vi2d((pixelSX * Room::roomSize) + roomGap, (pixelSY * Room::roomSize) + roomGap), olc::vi2d(Room::roomSize - roomGap, Room::roomSize - roomGap), olc::BLUE);
			}
		}
	}
}

void Engine::updateViewport()
{
	PanX = player.x;
	PanY = player.y;

	offsetX -= (player.x - PanX);
	offsetY -= (player.y - PanY);
}

void Engine::drawPlayer()
{
	Draw(olc::vi2d(player.x, player.y), olc::YELLOW);
}
