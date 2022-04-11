#include "Player.h"
#include "Monster.h"
#include "BossMonster.h"

Player::Player()
{

}

Player::Player(string name, int hp, int diceNum, int gold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->gold = gold;
}

string Player::SetName()
{
	cout << endl;
	cout << "이름을 입력하세요" << endl;
	cin >> this->name;
	return name;
}
void Player::Set(string name, int hp, int diceNum, int gold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->gold = gold;
}

void Player::PrintInfo(Player* player)
{
	cout << "◇ 플레이어 정보 ◇" << endl;
	cout << endl;
	cout << "이름 : " << player->name << endl << endl;
	cout << "주사위 갯수 : " << player->diceNum << endl << endl;
	cout << "체력 : ";
	for (int i = 0; i < player->hp; i++)
	{
		cout << "●";
	};
	cout << endl << endl;
	cout << "골드 : " << player->GetGold() << endl << endl;
}

void Player::SetHp(int hp)
{
	this->hp = hp;
	if (hp > maxHp)
	{
		this->hp = maxHp;
	}
}
void Player::SetDecreaseDiceNum(int decreaseDiceNum)
{
	this->decreaseDiceNum = decreaseDiceNum;
}
void Player::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

void Player::SetDiceNum(int diceNum)
{
	this->diceNum = diceNum;
}

int Player::ThrowingDice(Player* player)
{
	int sum = 0;

	cout << "플레이어는 주사위를 던졌다" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < player->GetDiceNum(); i++)
	{
		temp = dis(gen);
		sum += temp;
		Sleep(1000);
		cout << i + 1 << "번째 주사위 눈 : " << temp << endl;
		cout << endl;
	}
	cout << endl;
	Sleep(1000);
	cout << "주사위 눈의 합 : " << sum << endl;
	cout << endl;
	return sum;
}

bool Player::Die(Player* player)
{
	if (player->hp == 0)
	{
		system("cls");
		cout << endl;
		cout << "  YOU DIE  " << endl;
		return true;
	}
}

void Player::BuyItem(Player* player, Item item)
{
	player->GetGold() - item.GetPrice();
}

string Player::GetName()
{
	return name;
}

int Player::GetDiceNum()
{
	return diceNum;
}

int Player::GetHp()
{
	return hp;
}
int Player::GetMaxHp()
{
	return maxHp;
}

int Player::GetDecreaseDiceNum()
{
	return decreaseDiceNum;
}

int Player::GetGold()
{
	return gold;
}

void Player::SetGold(int gold)
{
	this->gold = gold;
}
