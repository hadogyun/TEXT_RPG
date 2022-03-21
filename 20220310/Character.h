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
	int dropGold;
	vector<Monster*> monsters;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetdropGold();

	Monster();
	Monster(string name, int hp, int diceNum, int dropGold);
	void Set(string name, int hp, int diceNum, int dropGold);
	void PrintInfo(Monster* mosnter);
	int ThrowingDice(Monster* monster);
	void SetHp(int hp);
	void SetDiceNum(int diceNum);
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

	BossMonster();
	BossMonster(string name, int hp, int diceNum);
	void Set(string name, int hp, int diceNum);
	void PrintInfo(BossMonster* mosnter);
	int ThrowingDice(BossMonster* bossmonster);
	void SetHp(int hp);
	void SetDiceNum(int diceNum);
	bool Die(BossMonster* bossmonster);
	BossMonster* RandomBossMonster();
};

class Player : public Character
{
private:
	int gold;
	int maxHp = 5;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetGold();
	int GetMaxHp();
	Item item;
	Inventory inventory;

	Player();
	Player(string name, int hp, int diceNum, int gold);

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

	void UseSkillCard(Player* player, Monster* monster, int id);

	void UsePotion(Player* player, int id);
};