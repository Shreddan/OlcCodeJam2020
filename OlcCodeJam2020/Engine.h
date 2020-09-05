#pragma once
#include <olcPixelGameEngine.h>
#include <Extensions/olcPGEX_SplashScreen.h>
#include "Map.h"
#include "Player.h"

enum gState
{
	Begin,
	Main,
	Pause,
	End
};


class Engine : public olc::PixelGameEngine
{
public:
	Engine();
	~Engine();

	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);

	void StateManager();

	void WorldtoScreen(float worldX, float worldY, int &screenX, int &screenY);
	void ScreentoWorld(int screenX, int screenY, float &worldX, float &worldY);

	void inputHandler(float fElapsedTime);

	void CreateItems();

	void drawMap();
	//void updateViewport();
	void drawPlayer();

	olcPGEX_SplashScreen splash;


	float CamX;
	float CamY;

	float offsetX = 0.0f;
	float offsetY = 0.0f;

	Map* currentMap = nullptr;

	Player player;

	int roomGap = 20;

	int gameState = 0;

	std::string name = "Player";

	std::vector<CraftingItem> items;
};

