#pragma once
#include <string>
#include <vector>

struct CraftingItem
{
	CraftingItem();
	CraftingItem(std::string name, int ID, bool Vital);
	std::string name;
	int ItemID;
	bool isVital;
};

class Crafting
{
public:

	Crafting();
	~Crafting();


	CraftingItem* GreatMachine[2];

	CraftingItem Craft();

};

