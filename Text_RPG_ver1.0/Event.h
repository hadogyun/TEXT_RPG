#pragma once

#include "Header.h"
#include "Character.h"
#include "Shop.h"

class Event
{
public:
	Event();

	Player player;
	Monster monster;
	BossMonster bossmonster;
	Doppelganger doppelganger;
	Inventory* inventory;
	Item item;
	Shop* shop;

	string EventName(int num);

	void NextStage();
	void NextScene();

	void PrintBattleMenu(Player* player, Monster monster);
	void Battle(Player* player, Monster monster, Inventory* inventory, Item* item);
	void BossBattle(Player* player, BossMonster bossmonster, Inventory* inventory, Item* item);
	void Shopping(Player* player, Shop* shop, Inventory* inventory);
	void Camping(Player* player);

	void Chest(Player* player, Inventory* inventory);
	void Mimic(Player* player, Inventory* inventory, Item* item);
	void Trap(Player* player);
	void Demon(Player* player, Inventory* inventory);
	void PlusDice(Player* player);
	void GoldenGoblin(Player* player);
	void Clone(Player* player, Inventory* inventory, Item* item);
	void Surprise(Player* player, Monster* monster, Inventory* inventory, Item* item);
};
