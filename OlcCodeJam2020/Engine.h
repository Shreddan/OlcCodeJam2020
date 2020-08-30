#pragma once
#include <olcPixelGameEngine.h>
#include "Map.h"


class Engine : public olc::PixelGameEngine
{
public:
	Engine();
	~Engine();

	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);

	void WorldtoScreen(float worldX, float worldY, int screenX, int screenY);
	void ScreentoWorld(int screenX, int screenY, float worldX, float worldY);

	void drawMap();


	float offsetX = 0.0f;
	float offsetY = 0.0f;

	Map* currentMap = nullptr;
};
