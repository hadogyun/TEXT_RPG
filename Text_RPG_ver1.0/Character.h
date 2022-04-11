#pragma once

#include "Header.h"

class Inventory;
class Item;

class Character
{
protected:
	string name;
	int hp;
	int diceNum;
public:
	virtual string GetName();
	virtual int GetHp();
	virtual int GetDiceNum();

	virtual void Set(string name, int hp, int diceNum);
	virtual void SetHp(int hp);
	virtual void SetDiceNum(int diceNum);
	virtual void PrintInfo();
	virtual int ThrowingDice();
	virtual bool Die();
};
