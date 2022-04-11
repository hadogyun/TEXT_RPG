#pragma once

#include "Header.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "BossMonster.h"

class Player;
class Monster;
class BossMonster;

class Inventory
{
private:
	vector<Item*> slots;
public:
	Inventory();
	
	void AddItem(Item* targetItem);
	void UseItem(Player* player, Monster* monster, int index);
	void UseItem(Player* player, BossMonster* bossmonster, int index);
	void EraseItem(int index);
	void PrintInventory(Inventory* inventory);

	int SearchId(int index);
};