#pragma once
#include <string>
#include <vector>

struct CraftingItem
{
	enum ItemType
	{

	};

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


	CraftingItem* CraftingInterface[2];

	CraftingItem Craft();

};

