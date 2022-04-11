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
	cout << endl;
	cout << "�����Ϸ��� �ƹ� Ű�� �����ʽÿ�" << endl;
	_getch();
	system("cls");
}

void Event::NextScene()
{
	cout << "�����Ϸ��� �ƹ� Ű�� �����ʽÿ�" << endl;
	_getch();
	cout << endl;
}

void Event::PrintBattleMenu(Player* player, Monster monster)
{
	cout << endl;
	monster.PrintInfo();
	cout << endl;
	cout << endl;
	player->PrintInfo(player);
	cout << endl;
	cout << endl;
	cout << "1. �ֻ��� ������" << endl << endl;
	cout << "2. ����" << endl;
	cout << endl;
}

void Event::Battle(Player* player, Monster monster, Inventory* inventory, Item* item)
{
	cout << monster.GetName() << "��(��) ��Ÿ����!" << endl;
	cout << endl;
	cout << "��������!" << endl;
	for (;;)
	{
		int inputA;
		PrintBattleMenu(player, monster);
		cin >> inputA;
		if (inputA == 1)
		{
			int resultA = monster.ThrowingDice();
			NextScene();
			int resultB = player->ThrowingDice(player);
			NextScene();
			system("cls");
			if (resultB > resultA)
			{
				cout << "�¸�!" << endl;
				cout << endl;
				monster.SetHp(monster.GetHp() - 1);
				if (monster.Die(monster) == true)
				{
					cout << endl;
					player->SetGold(player->GetGold() + monster.GetdropGold());
					break;
				}
				NextStage();
			}
			else if (resultB < resultA)
			{
				cout << "�й�..." << endl;
				cout << endl;
				player->SetHp(player->GetHp() - 1);
				if (player->Die(player) == true)
				{
					exit(1);
				}
				NextStage();
			}
			else if (resultB == resultA)
			{
				cout << "�����ϴ�" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "����ϰ� ���� �������� ��ȣ�� �����ÿ�" << endl << endl;
			cout << "������ : 9" << endl;
			cout << endl;
			int inputB;
			cin >> inputB;
			if (inputB == 9)
			{
				break;
			}
			else
			{
				inventory->UseItem(player, &monster, inputB - 1);
				inventory->EraseItem(inputB - 1);
				if (monster.Die(monster) == true)
				{
					cout << endl;
					player->SetGold(player->GetGold() + monster.GetdropGold());
					break;
				}
			}
			NextScene();
			system("cls");
		}
	}
	player->SetDiceNum(player->GetDiceNum() - player->GetDecreaseDiceNum());
	player->SetDecreaseDiceNum(0);
	NextStage();
	system("cls");
}

void Event::BossBattle(Player* player, BossMonster bossmonster, Inventory* inventory, Item* item)
{
	cout << bossmonster.GetName() << "��(��) ��Ÿ����!" << endl;
	cout << endl;
	cout << "��������!" << endl;
	for (;;)
	{
		int inputA;
		PrintBattleMenu(player, bossmonster);
		cin >> inputA;
		if (inputA == 1)
		{
			int resultA = bossmonster.ThrowingDice();
			NextScene();
			int resultB = player->ThrowingDice(player);
			NextScene();
			system("cls");
			if (resultB > resultA)
			{
				cout << "�¸�!" << endl;
				cout << endl;
				bossmonster.SetHp(bossmonster.GetHp() - 1);
				if (bossmonster.Die(bossmonster) == true)
				{
					player->SetHp(player->GetMaxHp() + 1);
					break;
				}
				NextStage();
			}
			else if (resultB < resultA)
			{
				cout << "�й�..." << endl;
				cout << endl;
				player->SetHp(player->GetHp() - 1);
				if (player->Die(player) == true)
				{
					exit(1);
				}
				NextStage();
			}
			else if (resultB == resultA)
			{
				cout << "�����ϴ�" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "����ϰ� ���� �������� ��ȣ�� �����ÿ�" << endl << endl;
			cout << "������ : 9" << endl;
			cout << endl;
			int inputB;
			cin >> inputB;
			if (inputB == 9)
			{
				break;
			}
			else
			{
				inventory->UseItem(player, &bossmonster, inputB - 1);
				inventory->EraseItem(inputB - 1);
				if (bossmonster.Die(bossmonster) == true)
				{
					cout << endl;
					player->SetHp(player->GetMaxHp() + 1);
					break;
				}
			}
			NextScene();
			system("cls");
		}
	}
	player->SetDiceNum(player->GetDiceNum() - player->GetDecreaseDiceNum());
	player->SetDecreaseDiceNum(0);
	NextStage();
	system("cls");
}

void Event::Shopping(Player* player, Shop* shop, Inventory* inventory)
{
	system("cls");
	cout << player->GetName() << "��(��) ������ �����ߴ�" << endl;
	cout << endl;
	for (;;)
	{
		shop->PrintShopInfo();
		cout << endl;
		cout << "������ ��ǰ�� ��ȣ�� �����ּ���" << endl << endl;
		cout << "������ : 9" << endl;
		cout << endl;
		cout << "���� ��� : " << player->GetGold() << endl;
		int input;
		cin >> input;
		if (input == 9)
		{
			break;
		}
		else if (input == 7)
		{
			if (player->GetGold() >= 1000)
			{
				cout << "�ֻ����� �����ϼ̽��ϴ�" << endl;
				player->SetGold(player->GetGold() - 1000);
				player->SetDiceNum(player->GetDiceNum() + 1);
				cout << "���� ��� : " << player->GetGold() << endl;
				cout << endl;
				cout << "�������� : �����մϴ�~" << endl;
				cout << endl;
				NextStage();
			}
			else
			{
				cout << "��尡 �����մϴ�" << endl;
				cout << endl;
				break;
			}
		}
		else if (player->GetGold() >= shop->shopItems[input - 1]->GetPrice())
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

void Event::Chest(Player* player, Inventory* inventory)
{
	int input;
	cout << "���ڸ� �߰��ߴ�!" << endl << endl;
	cout << "���ڸ� ���ðڽ��ϱ�?" << endl << endl;
	cout << "1. ���ڴ� ������" << endl << endl;
	cout << "2. � ������ ������ ���� �׳� ����" << endl << endl;
	cin >> input;
	if (input == 1)
	{
		cout << "���������� �߰��ߴ�!" << endl;
		cout << endl;
		inventory->AddItem(new Potion("��������", 100, 4, 1));
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
	cout << "���ڸ� �߰��ߴ�!" << endl << endl;
	cout << "���ڸ� ���ðڽ��ϱ�?" << endl << endl;
	cout << "1. ���ڴ� ������" << endl << endl;
	cout << "2. � ������ ������ ���� �׳� ����" << endl << endl;
	cin >> input;
	if (input == 1)
	{
		Monster mimic;
		mimic.Set("�̹�", 2, 2, 400);
		Event::Battle(player, mimic, inventory, item);
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
			if (player->Die(player) == true)
			{
				exit(1);
			}
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
void Event::Demon(Player* player, Inventory* inventory)
{
	cout << player->GetName() << "��(��) �Ǹ��� ������!" << endl;
	cout << endl;
	cout << "�Ǹ� : �ֻ��� ���� ���� 8�̻��̸� �������� �ϳ� �ֵ��� ����" << endl << endl;
	cout << "�Ǹ� : ������ �����ϸ� ���� ü���� ������ ���̴�" << endl << endl;
	cout << "�Ǹ� : � �غ��ڳ�?" << endl << endl;
	cout << endl;
	cout << "1. ���� ������ ����" << endl << endl;
	cout << "2. �Ǹ��� ��Ȥ���� �����" << endl << endl;

	int input;

	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result < 8)
		{
			cout << "����!" << endl;
			cout << endl;
			cout << player->GetName() << "�Ǹ��� �� ü���� ���Ѿư���! (ü�� - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			if (player->Die(player) == true)
			{
				exit(1);
			}
			NextStage();
		}
		else
		{
			cout << "����!!" << endl;
			cout << endl;
			cout << player->GetName() << "��(��) " << "��ųī��.�����̽��� �տ� �־���!" << endl << endl;
			inventory->AddItem(new SkillCard("��ųī��.�����̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
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
	cout << player->GetName() << "��(��) �ֺ��� �ź��� ������� �������� ���� ������" << endl << endl;
	cout << "���� : ��ſ��� ���� ���µ帮�ڽ��ϴ� ��翩.." << endl << endl;
	cout << player->GetName() << "�� �ֻ��� ������ �Ѱ� �þ��!!" << endl << endl;
	cout << endl;
	player->SetDiceNum(player->GetDiceNum() + 1);
	NextStage();
}
void Event::GoldenGoblin(Player* player)
{
	cout << player->GetName() << "�� Ȳ�ݰ���� �߰��ߴ�!" << endl << endl;
	cout << "�ֻ����� ���� 9�̻��� ������ ��������?!" << endl << endl;
	cout << "1. �ֻ����� ������" << endl << endl;

	int input;
	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result >= 9)
		{
			cout << "����!!!" << endl;
			cout << endl;
			cout << "��! Ȳ�ݰ������ ��尡 ��������ɴϴ�!!" << endl;
			cout << endl;
			cout << "500��� ȹ��!" << endl;

			player->SetGold(player->GetGold() + 500);
		}
		else if (result < 9)
		{
			cout << "����..." << endl;
			cout << endl;
			cout << "Ȳ�ݰ���� ���� ������ ��Ż�� Ÿ�� �������ϴ�" << endl;
		}
	}
	NextStage();
}

void Event::Clone(Player* player, Inventory* inventory, Item* item)
{
	Doppelganger doppelganger;
	doppelganger.Set(player, 500);
	cout << "�������� ���� ��Ʋ�Ÿ����� " << player->GetName() << "�� ������� ���ߴ�!" << endl;
	cout << endl;
	cout << "��������!" << endl;
	for (;;)
	{
		int inputA;
		PrintBattleMenu(player, doppelganger);
		cin >> inputA;
		if (inputA == 1)
		{
			int resultA = doppelganger.ThrowingDice();
			NextScene();
			int resultB = player->ThrowingDice(player);
			NextScene();
			system("cls");
			if (resultB > resultA)
			{
				cout << "�¸�!" << endl;
				cout << endl;
				doppelganger.SetHp(doppelganger.GetHp() - 1);
				if (doppelganger.Die(doppelganger) == true)
				{
					player->SetGold(player->GetGold() + doppelganger.GetdropGold());
					break;
				}
				NextStage();
			}
			else if (resultB < resultA)
			{
				cout << "�й�..." << endl;
				cout << endl;
				player->SetHp(player->GetHp() - 1);
				if (player->Die(player) == true)
				{
					exit(1);
				}
				NextStage();
			}
			else if (resultB == resultA)
			{
				cout << "�����ϴ�" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "����ϰ� ���� �������� ��ȣ�� �����ÿ�" << endl << endl;
			cout << "������ : 9" << endl;
			cout << endl;
			int inputB;
			cin >> inputB;
			if (inputB == 9)
			{
				break;
			}
			else
			{
				inventory->UseItem(player, &doppelganger, inputB - 1);
				inventory->EraseItem(inputB - 1);
				if (doppelganger.Die(doppelganger) == true)
				{
					cout << endl;
					player->SetGold(player->GetGold() + doppelganger.GetdropGold());
					break;
				}
			}
			NextScene();
			system("cls");
		}
	}
	player->SetDiceNum(player->GetDiceNum() - player->GetDecreaseDiceNum());
	player->SetDecreaseDiceNum(0);
	NextStage();
	system("cls");
}

void Event::Surprise(Player* player, Monster* monster, Inventory* inventory, Item* item)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 7);
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
		Event::Demon(player, inventory);
	}
	else if (result == 4)
	{
		Event::Chest(player, inventory);
	}
	else if (result == 5)
	{
		Event::PlusDice(player);
	}
	else if (result == 6)
	{
		Event::GoldenGoblin(player);
	}
	else if (result == 7)
	{
		Event::Clone(player, inventory, item);
	}
}


