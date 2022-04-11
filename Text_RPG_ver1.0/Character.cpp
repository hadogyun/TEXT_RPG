#include "Character.h"

string Character::GetName()
{
	return name;
}
int Character::GetHp()
{
	return hp;
}
int Character::GetDiceNum()
{
	return diceNum;
}

void Character::Set(string name, int hp, int diceNum)
{
	this->name = name;
	this->hp = hp;
	this->diceNum = diceNum;
}
void Character::SetHp(int hp)
{
	this->hp = hp;
}
void Character::SetDiceNum(int diceNum)
{
	this->diceNum = diceNum;
}

void Character::PrintInfo()
{
	cout << "◇ 플레이어 정보 ◇" << endl;
	cout << "이름 : " << name << endl;
	cout << "주사위 갯수 : " << diceNum << endl;
	cout << "체력 : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "●";
	};
	cout << endl;
}
int Character::ThrowingDice()
{
	int sum = 0;

	cout << "플레이어는 주사위를 던졌다" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < GetDiceNum(); i++)
	{
		temp = dis(gen);
		sum += temp;
		cout << i + 1 << "번째 주사위 눈 : " << temp << endl;
	}
	cout << endl;
	cout << "주사위 눈의 합 : " << sum << endl;
	cout << endl;
	return sum;
}
bool Character::Die()
{
	if (hp == 0)
	{
		system("cls");
		cout << endl;
		cout << "  캐릭터 죽음  " << endl;
		return true;
	}
}
