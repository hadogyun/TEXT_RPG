#pragma once

#include "Header.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "BossMonster.h"

class Player;
class Item
{
private:
protected:
	string name;
	int price;
	int id;
public:
	Item();
	Item(string name, int price, int id);
	string GetName();
	int GetPrice();
	int GetId();

	virtual void Set();
	virtual void PrintUse(int id);
	virtual void PrintInfo();
};

class Potion : public Item
{
private:
	int healValue;
public:
	Potion();
	Potion(string name, int price, int id, int healValue);
	int GetHealValue();
	int GetId();

	void Set(string name, int price, int id, int healValue);
	void PrintUse(int id);
	void PrintInfo();
};

class SkillCard : public Item
{	
protected:
	string effect;
public:
	SkillCard();
	SkillCard(string name, int price, int id, string effect);
	string GetEffect();
	int GetId();

	void Set(string name, int price, int id, string effect);
	void PrintUse(int id);
	void PrintInfo();
};
