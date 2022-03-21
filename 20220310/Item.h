#pragma once

#include "Header.h"
#include "Character.h"

class Character;

class Item
{
private:
protected:
	string name;
	int price;
	int id;
public:
	vector<Item*> items;
	Item();
	Item(string name, int price, int id);
	string GetName();
	int GetPrice();
	int GetId();

	virtual void Set();
	virtual void Use(int id);
	virtual void PrintInfo();
};

class SkillCard : public Item
{	
private:
	string effect;
public:
	SkillCard();
	SkillCard(string name, int price, int id, string effect);
	string GetEffect();
	int GetId();

	void Set();
	void Use(int id);
	void PrintInfo();
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

	void Set();
	void Use(int id);
	void PrintInfo();
};
