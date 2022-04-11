#include "Monster.h"
#include "Player.h"

Monster::Monster()
{
	monsters.push_back(new Monster("������", 1, 1, 100));
	monsters.push_back(new Monster("���", 2, 1, 200));
	monsters.push_back(new Monster("��ũ", 2, 2, 300));
	monsters.push_back(new Monster("�̳�Ÿ��ν�", 3, 1, 200));
	monsters.push_back(new Monster("�����ΰ�", 1, 3, 300));
	monsters.push_back(new Monster("�����̾�", 1, 3, 400));
}

Monster::Monster(string name, int hp, int diceNum, int dropGold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->dropGold = dropGold;
}

void Monster::Set(string name, int hp, int diceNum, int dropGold)
{
	Character::Set(name, hp, diceNum);
	this->dropGold = dropGold;
}

void Monster::PrintInfo()
{
	cout << "��  ���� ����  ��" << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ֻ��� ���� : " << diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "��";
	};
	cout << endl;
}

void Monster::SetHp(int hp)
{
	this->hp = hp;
}

int Monster::ThrowingDice()
{
	int sum = 0;

	cout << "���ʹ� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < diceNum; i++)
	{
		temp = dis(gen);
		sum += temp;
		Sleep(1000);
		cout << i + 1 << "��° �ֻ��� �� : " << temp << endl;
		cout << endl;
	}
	cout << endl;
	Sleep(1000);
	cout << "�ֻ��� ���� �� : " << sum << endl;
	cout << endl;
	return sum;
}

Monster Monster::RandomMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, monsters.size() - 1);

	return *monsters[dis(gen)];
}

bool Monster::Die(Monster monster)
{
	if (hp == 0)
	{
		cout << monster.name << "��(��) �����߷ȴ�!" << endl;
		cout << endl;
		cout << monster.dropGold << "��� ȹ��!" << endl;
		return true;
	}
}

string Monster::GetName()
{
	return name;
}

int Monster::GetDiceNum()
{
	return diceNum;
}

int Monster::GetHp()
{
	return hp;
}

int Monster::GetdropGold()
{
	return dropGold;
}

Doppelganger::Doppelganger()
{
	
}

Doppelganger::Doppelganger(Player* player, int dropGold)
{
	this->name = player->GetName();
	this->hp = player->GetMaxHp();
	this->diceNum = player->GetDiceNum();
	this->dropGold = dropGold;
}

void Doppelganger::Set(Player* player, int dropGold)
{
	this->name = player->GetName();
	this->hp = player->GetMaxHp();
	this->diceNum = player->GetDiceNum();
	this->dropGold = dropGold;
}

void Doppelganger::PrintInfo()
{
	cout << "��  ���� ����  ��" << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ֻ��� ���� : " << diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "��";
	};
	cout << endl;
}

int Doppelganger::ThrowingDice()
{
	int sum = 0;

	cout << "���ʹ� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < diceNum; i++)
	{
		temp = dis(gen);
		sum += temp;
		cout << i + 1 << "��° �ֻ��� �� : " << temp << endl;
	}
	cout << endl;
	cout << "�ֻ��� ���� �� : " << sum << endl;
	cout << endl;
	return sum;
}
