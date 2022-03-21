#include "Item.h"

Item::Item()
{
	items.push_back(new SkillCard("�� ��", 200, 1, "��� �ֻ��� ������ �ϳ� �ٿ��ش�"));
	items.push_back(new SkillCard("�� ���̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
	items.push_back(new SkillCard("��Ŀ", 300, 3, "����� ü�� - 1"));
	items.push_back(new Potion("��������", 100, 1, 4));
	items.push_back(new Potion("��Ȳ����", 200, 2, 5));
	items.push_back(new Potion("����ȸ������", 500, 10, 6));
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
	cout << name << " ���" << endl;
}
void SkillCard::Use(int id)
{
	Item::Use(id);
	cout << effect << endl;
}
void Potion::Use(int id)
{
	Item::Use(id);
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
