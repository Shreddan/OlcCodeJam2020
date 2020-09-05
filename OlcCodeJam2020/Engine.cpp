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
				player.x = currentMap->rooms[y * currentMap->mapWidth + x].x + (Room::roomSize / 3);
				player.y = currentMap->rooms[y * currentMap->mapWidth + x].y + (Room::roomSize / 3);
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
	items.emplace_back("KeyCard", 0, true);
	items.emplace_back("Impact Hammer", 1, false);
	items.emplace_back("Hammer", 2, true);
	items.emplace_back("Unknown Mechanism", 3, false);
	items.emplace_back("Gear", 4, false);
	items.emplace_back("Spanner", 5, true);
	items.emplace_back("Fuse", 6, false);
	items.emplace_back("Unknown Circuit", 7, false);
	items.emplace_back("", 8, false);
	items.emplace_back("", 9, false);
	items.emplace_back("", 10, false);
	items.emplace_back("", 11, false);
	items.emplace_back("", 12, false);
	items.emplace_back("", 13, false);
	items.emplace_back("", 14, false);
	items.emplace_back("", 15, false);
	items.emplace_back("", 16, false);
	items.emplace_back("", 17, false);
	items.emplace_back("", 18, false);
	items.emplace_back("", 19, false);
	items.emplace_back("Invalid Item", 20, false);
}

void Engine::drawMap()
{
	visibTileX = ScreenWidth() / Room::roomSize;
	visibTileY = ScreenHeight() / Room::roomSize;

	offsetX = CamX - (float)visibTileX / 2.0f;
	offsetY = CamY - (float)visibTileY / 2.0f;

	for (int x = 0; x < currentMap->mapWidth; x++)
	{
		for (int y = 0; y < currentMap->mapHeight; y++)
		{
			WorldtoScreen(currentMap->rooms[y * currentMap->mapWidth + x].x, currentMap->rooms[y * currentMap->mapWidth + x].y, pixelSX, pixelSY);
			
			if (currentMap->rooms[y * currentMap->mapWidth + x].isStart)
			{
				FillRect(olc::vi2d(pixelSX, pixelSY), olc::vi2d(Room::roomSize, Room::roomSize), olc::GREEN);
			}
			else
			{
				FillRect(olc::vi2d(pixelSX, pixelSY), olc::vi2d(Room::roomSize, Room::roomSize), olc::Pixel(135, 206, 235));
			}
			DrawRect(olc::vi2d(pixelSX, pixelSY), olc::vi2d(Room::roomSize, Room::roomSize), olc::BLACK);
		}
	}

	
}

void Engine::updateViewport()
{
	CamX = player.x;
	CamY = player.y;
}

void Engine::drawPlayer()
{
	WorldtoScreen(player.x, player.y, offplayX, offplayY);
	FillRect(olc::vi2d(offplayX, offplayY), olc::vi2d(25, 25), olc::YELLOW);
}
