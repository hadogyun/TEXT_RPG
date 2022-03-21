#include "Event.h"

Event::Event()
{

}

string Event::EventName(int num)
{
	if (num == 1)
	{
		return "����";
	}
	else if (num == 2)
	{
		return "����";
	}
	else if (num == 3)
	{
		return "�߿�";
	}
	else if (num == 4)
	{
		return " ? ";
	}
}

void Event::NextStage()
{
	for (;;)
	{
		cout << endl;
		cout << "�����Ϸ��� 1�� �����ּ���" << endl;
		cout << endl;
		int input;

		cin >> input;
		if (input == 1)
		{
			break;
		}
	}
	system("cls");
}

void Event::NextScene()
{
	for (;;)
	{
		cout << endl;
		cout << "�����Ϸ��� 1�� �����ּ���" << endl;
		cout << endl;
		int input;
		cin >> input;
		if (input == 1)
		{
			break;
		}
	}
}

void Event::PrintBattleMenu(Player* player, Monster* monster)
{
	cout << endl;
	monster->PrintInfo(monster);
	cout << endl;
	cout << endl;
	player->PrintInfo(player);
	cout << endl;
	cout << endl;
	cout << "1. �ֻ��� ������" << endl;
	cout << "2. ����" << endl;
	cout << endl;
}

void Event::Battle(Player* player, Monster* monster, Inventory* inventory, Item* item)
{
	cout << monster->GetName() << "��(��) ��Ÿ����!" << endl;
	cout << endl;
	cout << "��������!" << endl;
	for (;;)
	{
		int inputA;
		PrintBattleMenu(player, monster);
		cin >> inputA;
		if (inputA == 1)
		{
			int resultA = monster->ThrowingDice(monster);
			NextScene();
			int resultB = player->ThrowingDice(player);
			NextScene();
			if (resultB > resultA)
			{
				monster->SetHp(monster->GetHp() - 1);
				PrintBattleMenu(player, monster);
				if (monster->Die(monster) == true)
				{
					player->SetGold(player->GetGold() + monster->GetdropGold());
					break;
				}
				NextStage();
			}
			else if (resultB < resultA)
			{
				player->SetHp(player->GetHp() - 1);
				PrintBattleMenu(player, monster);
				if (player->Die(player) == true)
				{
					exit(1);
				}
				NextStage();
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "����ϰ� ���� �������� ��ȣ�� �����ÿ�" << endl;
			cout << endl;
			int inputB;
			cin >> inputB;
			inventory->UseItem(inputB - 1);
			NextStage();
			system("cls");
		}
	}
	NextStage();
}
void Event::BossBattle(Player* player, BossMonster* bossmonster, Inventory* inventory, Item* item)
{
	cout << bossmonster->GetName() << "��(��) ��Ÿ����!" << endl;
	cout << endl;
	cout << "��������!" << endl;
	for (;;)
	{
		int inputA;
		PrintBattleMenu(player, bossmonster);
		cin >> inputA;
		if (inputA == 1)
		{
			int resultA = bossmonster->ThrowingDice(bossmonster);
			NextScene();
			int resultB = player->ThrowingDice(player);
			NextScene();
			if (resultB > resultA)
			{
				bossmonster->SetHp(bossmonster->GetHp() - 1);
				PrintBattleMenu(player, bossmonster);
				if (bossmonster->Die(bossmonster) == true)
				{
					player->SetMaxHp(player->GetMaxHp() + 1);
					player->SetHp(player->GetMaxHp());
					break;
				}
				NextStage();
			}
			else if (resultB < resultA)
			{
				player->SetHp(player->GetHp() - 1);
				PrintBattleMenu(player, bossmonster);
				if (player->Die(player) == true)
				{
					exit(1);
				}
				NextStage();
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "����ϰ� ���� �������� ��ȣ�� �����ÿ�" << endl;
			cout << endl;
			int inputB;
			cin >> inputB;
			inventory->UseItem(inputB - 1);
			NextStage();
			system("cls");
		}
	}
	NextStage();
}

void Event::Shopping(Player* player, Shop* shop, Inventory* inventory)
{
	cout << player->GetName() << "��(��) ������ �����ߴ�" << endl;
	cout << endl;
	for (;;)
	{
		shop->PrintShopInfo();
		cout << endl;
		cout << "������ ��ǰ�� ��ȣ�� �����ּ���" << endl;
		cout << endl;
		cout << "���� ��� : " << player->GetGold() << endl;
		int input;
		cin >> input;
		if (player->GetGold() >= shop->shopItems[input - 1]->GetPrice())
		{
			cout << item.GetName() << "�� �����ϼ̽��ϴ�" << endl;
			player->SetGold(player->GetGold() - shop->shopItems[input - 1]->GetPrice());
			inventory->AddItem(shop->shopItems[input - 1]);
			cout << "���� ��� : " << player->GetGold() << endl;
			cout << endl;
			cout << "�������� : �����մϴ�~" << endl;
			cout << endl;
		}
		else
		{
			cout << "��尡 �����մϴ�" << endl;
			cout << endl;
			break;
		}
	}
	NextStage();
}
void Event::Camping(Player* player)
{
	cout << player->GetName() << "��(��) �߿��� �� �ִ� ��Ҹ� �߰��ߴ�!" << endl;
	cout << endl;
	cout << player->GetName() << "��(��) ü���� 1 ȸ���ߴ�" << endl;
	player->SetHp(player->GetHp() + 1);
	player->PrintInfo(player);
	cout << endl;
	NextStage();
}

void Event::Chest(Player* player, Item* item)
{
	int input;
	cout << "���ڸ� �߰��ߴ�!" << endl;
	cout << "���ڸ� ���ðڽ��ϱ�?" << endl;
	cout << "1. ���ڴ� ������" << endl;
	cout << "2. � ������ ������ ���� �׳� ����" << endl;
	cin >> input;
	if (input == 1)
	{
		cout << item->GetName() << "��(��) �߰��ߴ�!" << endl;
		player->Looting(*item);
		NextStage();
	}
	else if (input == 2)
	{
		NextStage();
	}
}
void Event::Mimic(Player* player, Inventory* inventory, Item* item)
{
	int input;
	cout << "���ڸ� �߰��ߴ�!" << endl;
	cout << "���ڸ� ���ðڽ��ϱ�?" << endl;
	cout << "1. ���ڴ� ������" << endl;
	cout << "2. � ������ ������ ���� �׳� ����" << endl;
	cin >> input;
	if (input == 1)
	{
		Monster mimic;
		mimic.Set("�̹�", 2, 2, 400);
		Event::Battle(player, &mimic, inventory, item);
		player->SetGold(player->GetGold() + mimic.GetdropGold());
	}
	else if (input == 2)
	{
		NextStage();
	}
}
void Event::Trap(Player* player)
{
	cout << player->GetName() << "��(��) ������ ���� ���迡 ó�ߴ�!" << endl;
	cout << endl;
	cout << "�ֻ��� ���� ���� 7�̻��� ������ �������� �� �ִ�!" << endl;
	cout << endl;
	cout << "1. �ֻ��� ������" << endl;
	cout << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		int result = player->ThrowingDice(player);

		if (result < 7)
		{
			cout << "����!" << endl;
			cout << player->GetName() << "��(��) ������ �������ȴ�! ����...(ü�� - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			NextStage();
		}
		else
		{
			cout << "����!!" << endl;
			cout << player->GetName() << "��(��) ������ ������ �������Դ�! ��.." << endl;
			NextStage();
		}
	}
}
void Event::Demon(Player* player, Item* item)
{
	cout << player->GetName() << "��(��) �Ǹ��� ������!" << endl;
	cout << endl;
	cout << "�Ǹ� : �ֻ��� ���� ���� 8�̻��̸� �������� �ϳ� �ֵ��� ����" << endl;
	cout << "�Ǹ� : ������ �����ϸ� ���� ü���� ������ ���̴�" << endl;
	cout << "�Ǹ� : � �غ��ڳ�?" << endl;
	cout << endl;
	cout << "1. ���� ������ ����" << endl;
	cout << "2. �Ǹ��� ��Ȥ���� �����" << endl;

	int input;

	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result < 8)
		{
			cout << "����!" << endl;
			cout << player->GetName() << "�Ǹ��� �� ü���� ���Ѿư���! (ü�� - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			NextStage();
		}
		else
		{
			cout << "����!!" << endl;
			cout << player->GetName() << "��(��) " << item->GetName() << "��(��) �տ� �־���!" << endl;
			NextStage();
		}
	}
	else if (input == 2)
	{
		NextStage();
	}
}
void Event::PlusDice(Player* player)
{
	cout << endl;
	cout << player->GetName() << "��(��) �ֺ��� �ź��� ������� �������� ���� ������" << endl;
	cout << "���� : ��ſ��� ���� ���µ帮�ڽ��ϴ� ���� ��翩.." << endl;
	cout << player->GetName() << "�� �ֻ��� ������ �Ѱ� �þ���!!" << endl;
	cout << endl;
	player->SetDiceNum(player->GetDiceNum() + 1);
}

void Event::Surprise(Player* player, Monster* monster, Inventory* inventory, Item* item)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 5);
	int result = dis(gen);

	if (result == 1)
	{
		Event::Trap(player);
	}
	else if (result == 2)
	{
		Event::Mimic(player, inventory, item);
	}
	else if (result == 3)
	{
		Event::Demon(player, item);
	}
	else if (result == 4)
	{
		Event::Chest(player, item);
	}
	else if (result == 5)
	{
		Event::PlusDice(player);
	}
}


