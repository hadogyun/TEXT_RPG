#pragma once

#include "Header.h"
#include "Item.h"

class Inventory
{
private:
	vector<Item*> slots;
public:
	Inventory();
	Item item;
	
	void AddItem(Item* targetItem);
	void UseItem(int index);
	void PrintInventory(Inventory* inventory);

	int SearchId(int index);
};