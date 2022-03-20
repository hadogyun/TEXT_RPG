#include "Item.h"

Item::Item()
{
	
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
void SkillCard::Set(string name, int price, int id, string effect)
{
	Item::Set();
	this->effect = effect;
}
void Potion::Set(string name, int price, int id, int healValue)
{
	Item::Set();
	this->healValue = healValue;
}

void Item::PrintUse(int id)
{
	cout << name << " 사용" << endl;
}
void SkillCard::PrintUse(int id)
{
	Item::PrintUse(id);
	cout << effect << endl;
}
void Potion::PrintUse(int id)
{
	Item::PrintUse(id);
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
