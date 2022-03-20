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

#pragma region �ʱ������
	
	vector<Item*> bag;

	bag.push_back(new SkillCard("��ųī��.�����̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
	bag.push_back(new SkillCard("��ųī��.����", 200, 1, "��� �ֻ��� ������ �ϳ� �ٿ��ش�"));
	bag.push_back(new Potion("��������", 100, 4, 1));
	
#pragma endregion

#pragma region ������

	vector<Item*> items;
	
	//id�� ���� ������ ������ �����ؾ��ҵ�
	items.push_back(new SkillCard("��ųī��.����", 200, 1, "��� �ֻ��� ������ �ϳ� �ٿ��ش�"));
	items.push_back(new SkillCard("��ųī��.�����̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
	items.push_back(new SkillCard("��ųī��.��Ŀ", 500, 3, "����� ü�� - 1"));
	items.push_back(new Potion("��������", 100, 4, 1));
	items.push_back(new Potion("��Ȳ����", 200, 5, 2));
	items.push_back(new Potion("����ȸ������", 500, 6, 10));

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
	cout << player.GetName() << "��(��) �������� ������ ������ �����۵��� ã�Ҵ�!" << endl;
	cout << endl;
	inventory.AddItem(bag[0]);
	inventory.AddItem(bag[1]);
	inventory.AddItem(bag[2]);
	cout << endl;
	cout << player.GetName() << "��(��) ������ ������" << endl;
	cout << endl;

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << j + 1 << " - " << i + 1 << " ��������" << endl;
			cout << endl;
			system.Menu(&player, &inventory);
			system.ChooseOptions(&player, monster.RandomMonster(), &shop, &inventory, &item);
		}
		cout << j + 1 << "��° ������" << endl;
		cout << endl;
		event.BossBattle(&player, bossmonster.RandomBossMonster(), &inventory, &item);
	}
	system.Ending();
}