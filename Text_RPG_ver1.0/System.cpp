#include "System.h"

int System::Random()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 4);

	return dis(gen);
}

void System::Opening()
{
	for (;;)
	{
		system("cls");
		cout << endl;
		cout << "==================================================" << endl;
		cout << endl;
		cout << "          D I C E	A D V E N T U R E        " << endl;
		cout << endl;
		cout << "==================================================" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "		   1. �����ϱ�" << endl;
		cout << endl;
		cout << "		   2. ����" << endl;
		cout << endl;
		cout << endl;
		int input;
		cin >> input;
		if (input == 1)
		{
			break;
		}
		else if (input == 2)
		{
			exit(1);
		}
	}
}
void System::Menu(Player* player, Inventory* inventory)
{
	for (;;)
	{
		cout << endl;
		cout << "1. �����ϱ�" << endl << endl;
		cout << "2. �÷��̾� ����Ȯ��" << endl << endl;
		cout << "3. �κ��丮 Ȯ��" << endl << endl;
		int input;
		cin >> input;
		if (input == 1)
		{
			event.NextStage();
			break;
		}
		else if (input == 2)
		{
			player->PrintInfo(player);
		}
		else if (input == 3)
		{
			inventory->PrintInventory(inventory);
		}
	}
}

void System::BeginStory()
{
	system("cls");
	cout << endl;
	cout << "�ձ��� 310��" << endl << endl;
	cout << "���͵��� ��Ÿ�� �� ����� ū ȥ���� ������ �ȴ�" << endl << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "�� ��, �ֽ��� �ֻ��� ������ ��Ÿ�� �� �������" << endl << endl;
	cout << "�ֻ����� �ָ� �� ���踦 ���ش޶�� �Ѵ�" << endl << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "���� : ���� �ε� �ֻ����� �� ���踦 �������ּ���.." << endl << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "��, ������ �����غ���!" << endl << endl;
	event.NextStage();
	system("cls");
}

void System::Explanation()
{
	cout << endl;
	cout << "��   ���� ������ ����   ��" << endl;
	cout << endl;
	cout << "�⺻������ �ֻ����� ���� ���� �����մϴ�" << endl << endl;
	cout << "�ϳ��� ���������� �����ϰ� �߻��� �ΰ��� �̺�Ʈ�鿡��" << endl << endl;
	cout << "�ϳ��� ��� �����ϰ� �˴ϴ�" << endl << endl;
	cout << "10���� �̺�Ʈ ���� �� �������� �ϰ� �ǰ�" << endl << endl;
	cout << "�������͸� �� �� ����� Ŭ�����ϰ� �˴ϴ�" << endl << endl;
	cout << "(���������� �¸��� �� �ִ�ü���� + 1�ʰ� ���ÿ� Ǯ�� ä���ݴϴ�)" << endl << endl;
	cout << "������ ���� �ֻ������� ������ ���� �� ���� ���� �¸��մϴ�" << endl << endl;
	cout << "�׷� ������ ���ϴ�" << endl;
	cout << endl;
	event.NextStage();
	system("cls");
}

void System::EventOccur(Player* player, Monster* monster, Shop* shop, Inventory* inventory, Item* item, int num)
{
	if (num == 1)
	{
		event.Battle(player, *monster, inventory, item);
	}
	else if (num == 2)
	{
		event.Shopping(player, shop, inventory);
	}
	else if (num == 3)
	{
		event.Camping(player);
	}
	else if (num == 4)
	{
		event.Surprise(player, monster, inventory, item);
	}
}
void System::ChooseOptions(Player* player, Monster monster, Shop* shop, Inventory* inventory, Item* item)
{
	int input;

	int resultA = Random();
	int resultB = Random();

	for (; resultA == resultB;)
	{
		resultB = Random();
	}

	cout << endl;
	cout << "�������� ����ּ���" << endl;
	cout << endl << endl;
	cout << "1. " << event.EventName(resultA) << endl;
	cout << endl;
	cout << "2. " << event.EventName(resultB) << endl;
	cout << endl;
	cin >> input;

	if (input == 1)
	{
		system("cls");
		EventOccur(player, &monster, shop, inventory, item, resultA);
	}
	else if (input == 2)
	{
		system("cls");
		EventOccur(player, &monster, shop, inventory, item, resultB);
	}
}
void System::Ending()
{
	system("cls");
	cout << endl;
	cout << "���ϵ帳�ϴ� Ŭ�����ϼ̽��ϴ�!" << endl;
}