#include "Crafting.h"

Crafting::Crafting()
{
}

Crafting::~Crafting()
{
}

CraftingItem Crafting::Craft()
{
    switch(CraftingInterface[0]->ItemID)
    {

    }
}

CraftingItem::CraftingItem()
{
}

CraftingItem::CraftingItem(std::string name, int ID, bool Vital)
{
    this->name = name;
    this->ItemID = ID;
    this->isVital = Vital;
}
