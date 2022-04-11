#include "BossMonster.h"
#include "Monster.h"
#include "Player.h"

BossMonster::BossMonster()
{
	bossmonsters.push_back(new BossMonster("킹 슬라임", 3, 2));
	bossmonsters.push_back(new BossMonster("고블린 로드", 3, 3));
	bossmonsters.push_back(new BossMonster("드래곤", 5, 3));
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
	cout << "◇  몬스터 정보  ◇" << endl;
	cout << "이름 : " << name << endl;
	cout << "주사위 갯수 : " << diceNum << endl;
	cout << "체력 : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "●";
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

	cout << "보스몬스터의 첫번째 주사위 눈의 값은 두배가 된다" << endl;
	cout << "몬스터는 주사위를 던졌다" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	int doubledice = dis(gen) * 2;
	Sleep(1000);
	cout << "1번째 주사위 눈(두배) : " << doubledice << endl;
	cout << endl;
	for (int i = 1; i < diceNum; i++)
	{
		temp = dis(gen);
		sum += temp;
		Sleep(1000);
		cout << i + 1 << "번째 주사위 눈 : " << temp << endl;
		cout << endl;
	}
	cout << endl;
	Sleep(1000);
	cout << "주사위 눈의 합 : " << sum + doubledice << endl;
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
		cout << bossmonster.name << "을(를) 쓰러뜨렸다!" << endl;
		cout << endl;
		cout << "최대 체력이 + 1되고 최대로 회복됩니다!" << endl;
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
