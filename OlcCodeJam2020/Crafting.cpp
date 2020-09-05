#include "Crafting.h"

Crafting::Crafting()
{
}

Crafting::~Crafting()
{
}

CraftingItem Crafting::Craft()
{
    switch(GreatMachine[0]->ItemID)
    {
        case 0:
        {
            switch (GreatMachine[1]->ItemID)
            {
                case 0:
                {
                    return CraftingItem("Invalid Item", 20, false);
                    break;
                }
            }
            break;
        }

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
