#pragma once
#include <string>
#include <vector>

struct CraftingItem
{
	std::string name;
	int Type;
	bool isVital;
};

class Crafting
{
public:

	Crafting();
	~Crafting();


	CraftingItem* CraftingInterface[2];


};

