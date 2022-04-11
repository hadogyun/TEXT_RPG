#pragma once

#include "Header.h"
#include "Item.h"

class Shop
{
private:
public:
	Item item;
	vector<Item*> shopItems;
	
	Shop();
	void PrintShopInfo();
};
