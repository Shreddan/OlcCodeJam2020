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

	//updateViewport();
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
			updateViewport();
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

void Engine::WorldtoScreen(float worldX, float worldY, int& screenX, int& screenY)
{
	screenX = (int)(worldX - offsetX);
	screenY = (int)(worldY - offsetY);
}

void Engine::ScreentoWorld(int screenX, int screenY, float& worldX, float& worldY)
{
	worldX = (float)(screenX)+offsetX;
	worldY = (float)(screenY)+offsetY;
}

void Engine::inputHandler(float fElapsedTime)
{
	if (GetKey(olc::RIGHT).bPressed)
	{
		player.x += Room::roomSize;
	}
	else if (GetKey(olc::LEFT).bPressed)
	{
		player.x -= Room::roomSize;
	}

	if (GetKey(olc::UP).bPressed)
	{
		player.y -= Room::roomSize;
	}
	else if (GetKey(olc::DOWN).bPressed)
	{
		player.y += Room::roomSize;
	}
}

void Engine::CreateItems()
{
	items.emplace_back("Torch", 0, true);
	items.emplace_back("Battery", 1, false);
	items.emplace_back("Spade", 2, true);
	items.emplace_back("", 3, false);
	items.emplace_back("", 4, false);
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
	items.emplace_back();
}

void Engine::drawMap()
{

	
}

//void Engine::updateViewport()
//{
//	CamX = player.x / Room::roomSize;
//	CamY = player.y / Room::roomSize;;
//}

void Engine::drawPlayer()
{
	FillRect(olc::vi2d(player.x, player.y), olc::vi2d(25, 25), olc::YELLOW);
}
