#pragma once

#include "Header.h"
#include "Character.h"
#include "Shop.h"

class Event
{
public:
	Event();

	Player* player;
	Monster* monster;
	Inventory* inventory;
	Item item;
	Shop* shop;

	string EventName(int num);

	void NextStage();
	void NextScene();

	void PrintBattleMenu(Player* player, Monster* monster);
	void Battle(Player* player, Monster* monster, Inventory* inventory, Item* item);
	void BossBattle(Player* player, BossMonster* bossmonster, Inventory* inventory, Item* item);
	void Shopping(Player* player, Shop* shop, Inventory* inventory);
	void Camping(Player* player);

	void Chest(Player* player, Item* item);
	void Mimic(Player* player, Inventory* inventory, Item* item);
	void Trap(Player* player);
	void Demon(Player* player, Item* item);
	void PlusDice(Player* player);
	void Surprise(Player* player, Monster* monster, Inventory* inventory, Item* item);
};
