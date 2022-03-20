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
	cout << name << " ���" << endl;
}
void SkillCard::PrintUse(int id)
{
	Item::PrintUse(id);
	cout << effect << endl;
}
void Potion::PrintUse(int id)
{
	Item::PrintUse(id);
	cout << healValue << "��ŭ ü�� ȸ��" << endl;
}

void Item::PrintInfo()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << price << endl;
}

void SkillCard::PrintInfo()
{
	Item::PrintInfo();
	cout << "ȿ�� : " << effect << endl;
}

void Potion::PrintInfo()
{
	Item::PrintInfo();
	cout << "ȸ���� : " << healValue << endl;
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
