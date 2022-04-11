#include "BossMonster.h"
#include "Monster.h"
#include "Player.h"

BossMonster::BossMonster()
{
	bossmonsters.push_back(new BossMonster("ŷ ������", 3, 2));
	bossmonsters.push_back(new BossMonster("��� �ε�", 3, 3));
	bossmonsters.push_back(new BossMonster("�巡��", 5, 3));
}
BossMonster::BossMonster(string name, int hp, int diceNum)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
}

void BossMonster::Set(string name, int hp, int diceNum)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
}

void BossMonster::PrintInfo()
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

void BossMonster::SetHp(int hp)
{
	this->hp = hp;
}

int BossMonster::ThrowingDice()
{
	int sum = 0;

	cout << "���������� ù��° �ֻ��� ���� ���� �ι谡 �ȴ�" << endl;
	cout << "���ʹ� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	int doubledice = dis(gen) * 2;
	Sleep(1000);
	cout << "1��° �ֻ��� ��(�ι�) : " << doubledice << endl;
	cout << endl;
	for (int i = 1; i < diceNum; i++)
	{
		temp = dis(gen);
		sum += temp;
		Sleep(1000);
		cout << i + 1 << "��° �ֻ��� �� : " << temp << endl;
		cout << endl;
	}
	cout << endl;
	Sleep(1000);
	cout << "�ֻ��� ���� �� : " << sum + doubledice << endl;
	cout << endl;
	return sum + doubledice;
}

BossMonster BossMonster::RandomBossMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, bossmonsters.size() - 1);

	return *bossmonsters[dis(gen)];
}

bool BossMonster::Die(BossMonster bossmonster)
{
	if (hp == 0)
	{
		cout << bossmonster.name << "��(��) �����߷ȴ�!" << endl;
		cout << endl;
		cout << "�ִ� ü���� + 1�ǰ� �ִ�� ȸ���˴ϴ�!" << endl;
		return true;
	}
}

string BossMonster::GetName()
{
	return name;
}

int BossMonster::GetDiceNum()
{
	return diceNum;
}

int BossMonster::GetHp()
{
	return hp;
}
