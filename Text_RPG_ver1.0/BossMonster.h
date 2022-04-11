#pragma once

#include "Header.h"
#include "Monster.h"

class BossMonster : public Monster
{
private:
	vector<BossMonster*> bossmonsters;
public:
	string GetName();
	int GetHp();
	int GetDiceNum();

	BossMonster();
	BossMonster(string name, int hp, int diceNum);

	void Set(string name, int hp, int diceNum);
	void PrintInfo();
	int ThrowingDice();
	void SetHp(int hp);
	bool Die(BossMonster bossmonster);
	BossMonster RandomBossMonster();
};
