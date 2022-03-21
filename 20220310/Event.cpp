#include "Event.h"

Event::Event()
{

}

string Event::EventName(int num)
{
	if (num == 1)
	{
		return "몬스터";
	}
	else if (num == 2)
	{
		return "상점";
	}
	else if (num == 3)
	{
		return "야영";
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
		cout << "진행하려면 1을 눌러주세요" << endl;
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
		cout << "진행하려면 1을 눌러주세요" << endl;
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
	cout << "1. 주사위 던지기" << endl;
	cout << "2. 가방" << endl;
	cout << endl;
}

void Event::Battle(Player* player, Monster* monster, Inventory* inventory, Item* item)
{
	cout << monster->GetName() << "이(가) 나타났다!" << endl;
	cout << endl;
	cout << "전투시작!" << endl;
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
			cout << "사용하고 싶은 아이템의 번호를 누르시오" << endl;
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
	cout << bossmonster->GetName() << "이(가) 나타났다!" << endl;
	cout << endl;
	cout << "전투시작!" << endl;
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
			cout << "사용하고 싶은 아이템의 번호를 누르시오" << endl;
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
	cout << player->GetName() << "은(는) 상점에 도착했다" << endl;
	cout << endl;
	for (;;)
	{
		shop->PrintShopInfo();
		cout << endl;
		cout << "구입할 상품의 번호를 눌러주세요" << endl;
		cout << endl;
		cout << "남은 골드 : " << player->GetGold() << endl;
		int input;
		cin >> input;
		if (player->GetGold() >= shop->shopItems[input - 1]->GetPrice())
		{
			cout << item.GetName() << "을 구입하셨습니다" << endl;
			player->SetGold(player->GetGold() - shop->shopItems[input - 1]->GetPrice());
			inventory->AddItem(shop->shopItems[input - 1]);
			cout << "남은 골드 : " << player->GetGold() << endl;
			cout << endl;
			cout << "상점주인 : 감사합니다~" << endl;
			cout << endl;
		}
		else
		{
			cout << "골드가 부족합니다" << endl;
			cout << endl;
			break;
		}
	}
	NextStage();
}
void Event::Camping(Player* player)
{
	cout << player->GetName() << "은(는) 야영할 수 있는 장소를 발견했다!" << endl;
	cout << endl;
	cout << player->GetName() << "은(는) 체력을 1 회복했다" << endl;
	player->SetHp(player->GetHp() + 1);
	player->PrintInfo(player);
	cout << endl;
	NextStage();
}

void Event::Chest(Player* player, Item* item)
{
	int input;
	cout << "상자를 발견했다!" << endl;
	cout << "상자를 여시겠습니까?" << endl;
	cout << "1. 상자는 못참지" << endl;
	cout << "2. 어떤 위험이 있을지 몰라 그냥 가자" << endl;
	cin >> input;
	if (input == 1)
	{
		cout << item->GetName() << "을(를) 발견했다!" << endl;
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
	cout << "상자를 발견했다!" << endl;
	cout << "상자를 여시겠습니까?" << endl;
	cout << "1. 상자는 못참지" << endl;
	cout << "2. 어떤 위험이 있을지 몰라 그냥 가자" << endl;
	cin >> input;
	if (input == 1)
	{
		Monster mimic;
		mimic.Set("미믹", 2, 2, 400);
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
	cout << player->GetName() << "은(는) 함정에 빠질 위험에 처했다!" << endl;
	cout << endl;
	cout << "주사위 눈의 합이 7이상이 나오면 빠져나올 수 있다!" << endl;
	cout << endl;
	cout << "1. 주사위 던지기" << endl;
	cout << endl;
	int input;
	cin >> input;
	if (input == 1)
	{
		int result = player->ThrowingDice(player);

		if (result < 7)
		{
			cout << "실패!" << endl;
			cout << player->GetName() << "은(는) 함정에 빠져버렸다! 으윽...(체력 - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			NextStage();
		}
		else
		{
			cout << "성공!!" << endl;
			cout << player->GetName() << "은(는) 함정을 무사히 빠져나왔다! 휴.." << endl;
			NextStage();
		}
	}
}
void Event::Demon(Player* player, Item* item)
{
	cout << player->GetName() << "은(는) 악마를 만났다!" << endl;
	cout << endl;
	cout << "악마 : 주사위 눈의 합이 8이상이면 아이템을 하나 주도록 하지" << endl;
	cout << "악마 : 하지만 실패하면 너의 체력을 빼앗을 것이다" << endl;
	cout << "악마 : 어때 해보겠나?" << endl;
	cout << endl;
	cout << "1. 운을 시험해 본다" << endl;
	cout << "2. 악마의 유혹에서 벗어난다" << endl;

	int input;

	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result < 8)
		{
			cout << "실패!" << endl;
			cout << player->GetName() << "악마가 내 체력을 빼앗아갔다! (체력 - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			NextStage();
		}
		else
		{
			cout << "성공!!" << endl;
			cout << player->GetName() << "은(는) " << item->GetName() << "을(를) 손에 넣었다!" << endl;
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
	cout << player->GetName() << "은(는) 주변이 신비한 기운으로 가득차는 것을 느꼈다" << endl;
	cout << "여신 : 당신에게 힘을 보태드리겠습니다 나의 용사여.." << endl;
	cout << player->GetName() << "의 주사위 갯수가 한개 늘었다!!" << endl;
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


