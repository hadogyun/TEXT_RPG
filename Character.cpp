#include "Character.h"

Monster::Monster()
{
	monsters.push_back(new Monster("������", 1, 1, 100));
	monsters.push_back(new Monster("���", 2, 1, 200));
	monsters.push_back(new Monster("��ũ", 2, 2, 300));
	monsters.push_back(new Monster("�̳�Ÿ��ν�", 3, 1, 200));
	monsters.push_back(new Monster("�����ΰ�", 1, 3, 300));
	monsters.push_back(new Monster("�����̾�", 1, 3, 400));
}
Player::Player()
{

}
BossMonster::BossMonster()
{
	bossmonsters.push_back(new BossMonster("-ŷ-������", 3, 2));
	bossmonsters.push_back(new BossMonster("��� �ε�", 3, 3));
	bossmonsters.push_back(new BossMonster("�巡��", 5, 3));
}
Monster::Monster(string name, int hp, int diceNum, int dropGold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->dropGold = dropGold;
}
BossMonster::BossMonster(string name, int hp, int diceNum)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
}
Player::Player(string name, int hp, int diceNum, int gold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->gold = gold;
}

void Monster::Set(string name, int hp, int diceNum, int dropGold)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
	this->dropGold = dropGold;
}
void BossMonster::SetIncreaseDiceNum(int increaseDiceNum)
{
	this->increaseDiceNum = increaseDiceNum;
}
void BossMonster::Set(string name, int hp, int diceNum)
{
	this->name = name;
	this->diceNum = diceNum;
	this->hp = hp;
}

string Player::SetName()
{
	cout << "�̸��� �Է��ϼ���" << endl;
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

void Monster::PrintInfo(Monster* monster)
{
	cout << "��  ���� ����  ��" << endl;
	cout << "�̸� : " << monster->name << endl;
	cout << "�ֻ��� ���� : " << monster->diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < monster->hp; i++)
	{
		cout << "��"; 
	};
}
void BossMonster::PrintInfo(BossMonster* bossmonster)
{
	cout << "��  ���� ����  ��" << endl;
	cout << "�̸� : " << bossmonster->name << endl;
	cout << "�ֻ��� ���� : " << bossmonster->diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < bossmonster->hp; i++)
	{
		cout << "��";
	};
}
void Player::PrintInfo(Player* player)
{
	cout << "�� �÷��̾� ���� ��" << endl;
	cout << "�̸� : " << player->name << endl;
	cout << "�ֻ��� ���� : " << player->diceNum << endl;
	cout << "ü�� : ";
	for (int i = 0; i < player->hp; i++)
	{
		cout << "��";
	};
	cout << endl;
	cout << "��� : " << player->GetGold() << endl;
}

void Monster::SetHp(int hp)
{
	this->hp = hp;
}
void BossMonster::SetHp(int hp)
{
	this->hp = hp;
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

void Monster::SetDiceNum(int diceNum)
{
	this->diceNum = diceNum;
}
void Monster::SetIncreaseDiceNum(int increaseDiceNum)
{
	this->increaseDiceNum = increaseDiceNum;
}
void Monster::SetIncreaseHp(int increaseHp)
{
	this->increaseHp = increaseHp;
}
void BossMonster::SetDiceNum(int diceNum)
{
	this->diceNum = diceNum;
}
void BossMonster::SetIncreaseHp(int hp)
{
	this->increaseHp = increaseHp;
}
void Player::SetDiceNum(int diceNum)
{
	this->diceNum = diceNum;
}

int Monster::ThrowingDice(Monster* monster)
{
	int sum = 0;
	
	cout << "���ʹ� �ֻ����� ������" << endl;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);
	
	int temp = 0;

	for (int i = 0; i < monster->GetDiceNum(); i++)
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
int BossMonster::ThrowingDice(BossMonster* bossmonster)
{
	int sum = 0;

	cout << "���������� ù��° �ֻ��� ���� ���� �ι谡 �ȴ�" << endl;
	cout << "���ʹ� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	int doubledice = dis(gen) * 2;
	cout << "1��° �ֻ��� ��(�ι�) : " << doubledice << endl;
	for (int i = 1; i < bossmonster->GetDiceNum(); i++)
	{
		temp = dis(gen);
		sum += temp;
		cout << i + 1 << "��° �ֻ��� �� : " << temp << endl;
	}
	cout << endl;
	cout << "�ֻ��� ���� �� : " << sum + doubledice << endl;
	cout << endl;
	return sum + doubledice;
}
int Player::ThrowingDice(Player* player)
{
	int sum = 0;

	cout << "�÷��̾�� �ֻ����� ������" << endl;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);

	int temp = 0;

	for (int i = 0; i < player->GetDiceNum(); i++)
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

Monster* Monster::RandomMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, monsters.size() - 1);

	return monsters[dis(gen)];
}
BossMonster* BossMonster::RandomBossMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, bossmonsters.size() - 1);

	return bossmonsters[dis(gen)];
}

bool Monster::Die(Monster* monster)
{
	if (monster->hp == 0)
	{
		cout << monster->GetName() << "��(��) �����߷ȴ�!" << endl;
		cout << endl;
		cout << monster->GetdropGold() << "��� ȹ��!" << endl;
		return true;
	}
}
bool BossMonster::Die(BossMonster* bossmonster)
{
	if (bossmonster->hp == 0)
	{
		cout << bossmonster->GetName() << "��(��) �����߷ȴ�!" << endl;
		cout << endl;
		cout << "�ִ� ü���� + 1�ǰ� �ִ�� ȸ���˴ϴ�!" << endl;
		return true;
	}
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

void Player::Looting(Item lootItem)
{
	inventory.AddItem(&lootItem);
}
void Player::BuyItem(Player* player, Item item)
{
	player->GetGold() - item.GetPrice();
}

void Player::UseItem(Player* player, Monster* monster, int id)
{
	if (id == 1)
	{
		player->SetDiceNum(player->GetDiceNum() + 1);
		player->SetDecreaseDiceNum(player->GetDecreaseDiceNum() + 1);
	}
	else if (id == 2)
	{
		monster->SetDiceNum(monster->GetDiceNum() - 1);
		monster->SetDiceNum(monster->GetDiceNum() + 1);
	}
	else if (id == 3)
	{
		monster->SetHp(monster->GetHp() - 1);
		monster->SetIncreaseHp(monster->GetIncreaseHp() + 1);
	}
	else if (id == 4)
	{
		player->SetHp(player->GetHp() + 1);
	}
	else if (id == 5)
	{
		player->SetHp(player->GetHp() + 2);
	}
	else if (id == 6)
	{
		player->SetHp(player->GetHp() + 10);
	}
}

void Player::UseItem(Player* player, BossMonster* bossmonster, int id)
{
	if (id == 1)
	{
		player->SetDiceNum(player->GetDiceNum() + 1);
		player->SetDecreaseDiceNum(player->GetDecreaseDiceNum() + 1);
	}
	else if (id == 2)
	{
		bossmonster->SetDiceNum(bossmonster->GetDiceNum() - 1);
		bossmonster->SetDiceNum(bossmonster->GetDiceNum() + 1);
	}
	else if (id == 3)
	{
		bossmonster->SetHp(bossmonster->GetHp() - 1);
		bossmonster->SetIncreaseHp(bossmonster->GetIncreaseHp() + 1);
	}
	else if (id == 4)
	{
		player->SetHp(player->GetHp() + 1);
	}
	else if (id == 5)
	{
		player->SetHp(player->GetHp() + 2);
	}
	else if (id == 6)
	{
		player->SetHp(player->GetHp() + 10);
	}
}

string Monster::GetName()
{
	return name;
}
string BossMonster::GetName()
{
	return name;
}
string Player::GetName()
{
	return name;
}

int Monster::GetDiceNum()
{
	return diceNum;
}
int BossMonster::GetDiceNum()
{
	return diceNum;
}
int BossMonster::GetIncreaseDiceNum()
{
	return increaseDiceNum;
}
int BossMonster::GetIncreaseHp()
{
	return increaseHp;
}
int Player::GetDiceNum()
{
	return diceNum;
}

int Monster::GetHp()
{
	return hp;
}
int BossMonster::GetHp()
{
	return hp;
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

int Monster::GetdropGold()
{
	return dropGold;
}

int Monster::GetIncreaseDiceNum()
{
	return increaseDiceNum;
}

int Monster::GetIncreaseHp()
{
	return increaseHp;
}

int Player::GetGold()
{
	return gold;
}

void Player::SetGold(int gold)
{
	this->gold = gold;
}
