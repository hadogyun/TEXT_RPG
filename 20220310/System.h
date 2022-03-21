#pragma once

#include "Header.h"
#include "Character.h"
#include "Event.h"
#include "Item.h"

class System
{
private:
	int Random();
public:
	Inventory* inventory;
	Player* player;
	Monster* monster;
	BossMonster* bossmonster;
	Item item;
	Event event;

	void Opening();
	void Menu(Player* player, Inventory* inventory);
	void BeginStory();
	void Explanation();
	void EventOccur(Player* player, Monster* monster, Shop* shop, Inventory* inventory, Item* item, int num);
	void ChooseOptions(Player* player, Monster* monster, Shop* shop, Inventory* inventory, Item* item);
	void Ending();
};
