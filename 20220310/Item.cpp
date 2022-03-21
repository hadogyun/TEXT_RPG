#include "Item.h"

Item::Item()
{
	items.push_back(new SkillCard("♥ 퀸", 200, 1, "상대 주사위 갯수를 하나 줄여준다"));
	items.push_back(new SkillCard("♠ 에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
	items.push_back(new SkillCard("조커", 300, 3, "상대의 체력 - 1"));
	items.push_back(new Potion("빨강포션", 100, 1, 4));
	items.push_back(new Potion("주황포션", 200, 2, 5));
	items.push_back(new Potion("완전회복포션", 500, 10, 6));
}
SkillCard::SkillCard()
{
	
}
Potion::Potion()
{
	
}
Item::Item(string name, int price, int id)
{
	this->name = name;
	this->price = price;
	this->id = id;
}
SkillCard::SkillCard(string name, int price, int id, string effect)
{
	this->name = name;
	this->price = price;
	this->id = id;
	this->effect = effect;
}
Potion::Potion(string name, int price, int id, int healValue)
{
	this->name = name;
	this->price = price;
	this->healValue = healValue;
}

void Item::Set()
{
	this->name = name;
	this->price = price;
}
void SkillCard::Set()
{
	Item::Set();
	this->effect = effect;
}
void Potion::Set()
{
	Item::Set();
	this->healValue = healValue;
}

void Item::Use(int id)
{
	cout << name << " 사용" << endl;
}
void SkillCard::Use(int id)
{
	Item::Use(id);
	cout << effect << endl;
}
void Potion::Use(int id)
{
	Item::Use(id);
	cout << healValue << "만큼 체력 회복" << endl;
}

void Item::PrintInfo()
{
	cout << "이름 : " << name << endl;
	cout << "가격 : " << price << endl;
}

void SkillCard::PrintInfo()
{
	Item::PrintInfo();
	cout << "효과 : " << effect << endl;
}

void Potion::PrintInfo()
{
	Item::PrintInfo();
	cout << "회복량 : " << healValue << endl;
}

string Item::GetName()
{
	return name;
}
int Item::GetPrice()
{
	return price;
}
string SkillCard::GetEffect()
{
	return effect;
}
int Potion::GetHealValue()
{
	return healValue;
}

int Item::GetId()
{
	return id;
}
int SkillCard::GetId()
{
	return id;
}
int Potion::GetId()
{
	return id;
}
