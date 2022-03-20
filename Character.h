#pragma once

#include "Header.h"
#include "Inventory.h"

class Character
{
protected:
	string name;
	int hp;
	int diceNum;
};

class Monster : public Character
{
private:
	vector<Monster*> monsters;
protected:
	int dropGold;
	int increaseDiceNum = 0;
	int increaseHp = 0;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetdropGold();
	int GetIncreaseDiceNum();
	int GetIncreaseHp();

	Monster();
	Monster(string name, int hp, int diceNum, int dropGold);

	void Set(string name, int hp, int diceNum, int dropGold);
	void PrintInfo(Monster* mosnter);
	int ThrowingDice(Monster* monster);
	void SetHp(int hp);
	void SetDiceNum(int diceNum);
	void SetIncreaseDiceNum(int increaseDiceNum);
	void SetIncreaseHp(int hp);
	bool Die(Monster* monster);
	Monster* RandomMonster();
};

class BossMonster : public Monster
{
private:
	vector<BossMonster*> bossmonsters;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetIncreaseDiceNum();
	int GetIncreaseHp();

	BossMonster();
	BossMonster(string name, int hp, int diceNum);

	void SetIncreaseDiceNum(int increaseDiceNum);
	void Set(string name, int hp, int diceNum);
	void PrintInfo(BossMonster* mosnter);
	int ThrowingDice(BossMonster* bossmonster);
	void SetHp(int hp);
	void SetDiceNum(int diceNum);
	void SetIncreaseHp(int hp);
	bool Die(BossMonster* bossmonster);
	BossMonster* RandomBossMonster();
};

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
	Item item;
	Inventory inventory;

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
	void Looting(Item lootItem);
	void BuyItem(Player* player, Item item);

	void UseItem(Player* player, Monster* monster, int id);
	void UseItem(Player* player, BossMonster* bossmonster, int id);
};