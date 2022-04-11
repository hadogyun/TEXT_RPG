#pragma once

#include "Header.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"

class Monster;

class Player : public Character
{
private:
	int gold;
	int maxHp = 5;
	int decreaseDiceNum = 0;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetGold();
	int GetMaxHp();
	int GetDecreaseDiceNum();

	Player();
	Player(string name, int hp, int diceNum, int gold);

	void SetDecreaseDiceNum(int decreaseDiceNum);
	void SetMaxHp(int maxHp);
	void SetDiceNum(int diceNum);
	string SetName();
	void SetGold(int gold);
	void Set(string name, int hp, int diceNum, int gold);
	void PrintInfo(Player* player);
	int ThrowingDice(Player* player);
	void SetHp(int hp);
	bool Die(Player* player);
	void BuyItem(Player* player, Item item);
};
