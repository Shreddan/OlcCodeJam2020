#pragma once
#include <string>
#include "Crafting.h"

class Player
{
public:
	Player();
	~Player();

	std::string name;
	int x;
	int y;
	std::vector<CraftingItem> inventory;

};

