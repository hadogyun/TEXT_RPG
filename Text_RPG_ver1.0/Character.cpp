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
	cout << "�� �÷��̾� ���� ��" << endl;
	cout << "�̸� : " << name << endl;
	cout << "�ֻ��� ���� : " << diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "��";
	};
	cout << endl;
}
int Character::ThrowingDice()
{
	int sum = 0;

	cout << "�÷��̾�� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < GetDiceNum(); i++)
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
bool Character::Die()
{
	if (hp == 0)
	{
		system("cls");
		cout << endl;
		cout << "  ĳ���� ����  " << endl;
		return true;
	}
}
