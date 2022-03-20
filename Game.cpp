#pragma once

#include "Header.h"
#include "System.h"
#include "Character.h"
#include "Item.h"
#include "Event.h"
#include "Inventory.h"
#include "Shop.h"

void main()
{
	System system;
	Player player;
	Inventory inventory;
	Monster monster;
	BossMonster bossmonster;
	Shop shop;
	Event event;
	Item item;

#pragma region 초기아이템
	
	vector<Item*> bag;

	bag.push_back(new SkillCard("스킬카드.♠에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
	bag.push_back(new SkillCard("스킬카드.♥퀸", 200, 1, "상대 주사위 갯수를 하나 줄여준다"));
	bag.push_back(new Potion("빨강포션", 100, 4, 1));
	
#pragma endregion

#pragma region 아이템

	vector<Item*> items;
	
	//id가 제일 앞으로 오도록 변경해야할듯
	items.push_back(new SkillCard("스킬카드.♥퀸", 200, 1, "상대 주사위 갯수를 하나 줄여준다"));
	items.push_back(new SkillCard("스킬카드.♠에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
	items.push_back(new SkillCard("스킬카드.조커", 500, 3, "상대의 체력 - 1"));
	items.push_back(new Potion("빨강포션", 100, 4, 1));
	items.push_back(new Potion("주황포션", 200, 5, 2));
	items.push_back(new Potion("완전회복포션", 500, 6, 10));

#pragma region
	
	system.Opening();
	system.BeginStory();
	system.Explanation();
	player.SetName();
	player.Set(player.GetName(), 5, 2, 100);
	cout << endl;
	player.PrintInfo(&player);
	cout << endl;
	cout << endl;
	cout << player.GetName() << "은(는) 집구석을 뒤져서 쓸만한 아이템들을 찾았다!" << endl;
	cout << endl;
	inventory.AddItem(bag[0]);
	inventory.AddItem(bag[1]);
	inventory.AddItem(bag[2]);
	cout << endl;
	cout << player.GetName() << "은(는) 모험을 떠났다" << endl;
	cout << endl;

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << j + 1 << " - " << i + 1 << " 스테이지" << endl;
			cout << endl;
			system.Menu(&player, &inventory);
			system.ChooseOptions(&player, monster.RandomMonster(), &shop, &inventory, &item);
		}
		cout << j + 1 << "번째 보스전" << endl;
		cout << endl;
		event.BossBattle(&player, bossmonster.RandomBossMonster(), &inventory, &item);
	}
	system.Ending();
}