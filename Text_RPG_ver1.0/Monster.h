#pragma once

#include "Header.h"
#include "Character.h"

class Player;

class Monster : public Character
{
private:
	vector<Monster*> monsters;
protected:
	int dropGold;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();
	int GetdropGold();

	Monster();
	Monster(string name, int hp, int diceNum, int dropGold);

	virtual void Set(string name, int hp, int diceNum, int dropGold);
	virtual void PrintInfo();
	virtual int ThrowingDice();
	virtual void SetHp(int hp);
	virtual bool Die(Monster monster);
	Monster RandomMonster();
};

class Doppelganger : public Monster
{
public:
	Doppelganger();
	Doppelganger(Player* player, int dropGold);

	void Set(Player* player, int dropGold);
	void PrintInfo();
	int ThrowingDice();
};
