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
	cout << endl;
	cout << "진행하려면 아무 키나 누르십시오" << endl;
	_getch();
	system("cls");
}

void Event::NextScene()
{
	cout << "진행하려면 아무 키나 누르십시오" << endl;
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
	cout << "1. 주사위 던지기" << endl << endl;
	cout << "2. 가방" << endl;
	cout << endl;
}

void Event::Battle(Player* player, Monster monster, Inventory* inventory, Item* item)
{
	cout << monster.GetName() << "이(가) 나타났다!" << endl;
	cout << endl;
	cout << "전투시작!" << endl;
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
				cout << "승리!" << endl;
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
				cout << "패배..." << endl;
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
				cout << "비겼습니다" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "사용하고 싶은 아이템의 번호를 누르시오" << endl << endl;
			cout << "나가기 : 9" << endl;
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
	cout << bossmonster.GetName() << "이(가) 나타났다!" << endl;
	cout << endl;
	cout << "전투시작!" << endl;
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
				cout << "승리!" << endl;
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
				cout << "패배..." << endl;
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
				cout << "비겼습니다" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "사용하고 싶은 아이템의 번호를 누르시오" << endl << endl;
			cout << "나가기 : 9" << endl;
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
	cout << player->GetName() << "은(는) 상점에 도착했다" << endl;
	cout << endl;
	for (;;)
	{
		shop->PrintShopInfo();
		cout << endl;
		cout << "구입할 상품의 번호를 눌러주세요" << endl << endl;
		cout << "나가기 : 9" << endl;
		cout << endl;
		cout << "남은 골드 : " << player->GetGold() << endl;
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
				cout << "주사위를 구입하셨습니다" << endl;
				player->SetGold(player->GetGold() - 1000);
				player->SetDiceNum(player->GetDiceNum() + 1);
				cout << "남은 골드 : " << player->GetGold() << endl;
				cout << endl;
				cout << "상점주인 : 감사합니다~" << endl;
				cout << endl;
				NextStage();
			}
			else
			{
				cout << "골드가 부족합니다" << endl;
				cout << endl;
				break;
			}
		}
		else if (player->GetGold() >= shop->shopItems[input - 1]->GetPrice())
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

void Event::Chest(Player* player, Inventory* inventory)
{
	int input;
	cout << "상자를 발견했다!" << endl << endl;
	cout << "상자를 여시겠습니까?" << endl << endl;
	cout << "1. 상자는 못참지" << endl << endl;
	cout << "2. 어떤 위험이 있을지 몰라 그냥 가자" << endl << endl;
	cin >> input;
	if (input == 1)
	{
		cout << "빨강포션을 발견했다!" << endl;
		cout << endl;
		inventory->AddItem(new Potion("빨강포션", 100, 4, 1));
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
	cout << "상자를 발견했다!" << endl << endl;
	cout << "상자를 여시겠습니까?" << endl << endl;
	cout << "1. 상자는 못참지" << endl << endl;
	cout << "2. 어떤 위험이 있을지 몰라 그냥 가자" << endl << endl;
	cin >> input;
	if (input == 1)
	{
		Monster mimic;
		mimic.Set("미믹", 2, 2, 400);
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
	cout << player->GetName() << "은(는) 함정에 빠질 위험에 처했다!" << endl;
	cout << endl;
	cout << "주사위 눈의 합이 7이상이 나오면 빠져나올 수 있다!" << endl;
	cout << endl;
	cout << "1. 주사위 던진다" << endl;
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
			if (player->Die(player) == true)
			{
				exit(1);
			}
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
void Event::Demon(Player* player, Inventory* inventory)
{
	cout << player->GetName() << "은(는) 악마를 만났다!" << endl;
	cout << endl;
	cout << "악마 : 주사위 눈의 합이 8이상이면 아이템을 하나 주도록 하지" << endl << endl;
	cout << "악마 : 하지만 실패하면 너의 체력을 빼앗을 것이다" << endl << endl;
	cout << "악마 : 어때 해보겠나?" << endl << endl;
	cout << endl;
	cout << "1. 운을 시험해 본다" << endl << endl;
	cout << "2. 악마의 유혹에서 벗어난다" << endl << endl;

	int input;

	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result < 8)
		{
			cout << "실패!" << endl;
			cout << endl;
			cout << player->GetName() << "악마가 내 체력을 빼앗아갔다! (체력 - 1)" << endl;
			player->SetHp(player->GetHp() - 1);
			if (player->Die(player) == true)
			{
				exit(1);
			}
			NextStage();
		}
		else
		{
			cout << "성공!!" << endl;
			cout << endl;
			cout << player->GetName() << "은(는) " << "스킬카드.♠에이스를 손에 넣었다!" << endl << endl;
			inventory->AddItem(new SkillCard("스킬카드.♠에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
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
	cout << player->GetName() << "은(는) 주변이 신비한 기운으로 가득차는 것을 느꼈다" << endl << endl;
	cout << "여신 : 당신에게 힘을 보태드리겠습니다 용사여.." << endl << endl;
	cout << player->GetName() << "의 주사위 갯수가 한개 늘어났다!!" << endl << endl;
	cout << endl;
	player->SetDiceNum(player->GetDiceNum() + 1);
	NextStage();
}
void Event::GoldenGoblin(Player* player)
{
	cout << player->GetName() << "은 황금고블린을 발견했다!" << endl << endl;
	cout << "주사위를 던져 9이상이 나오면 좋을지도?!" << endl << endl;
	cout << "1. 주사위를 던진다" << endl << endl;

	int input;
	cin >> input;

	if (input == 1)
	{
		int result = player->ThrowingDice(player);
		if (result >= 9)
		{
			cout << "성공!!!" << endl;
			cout << endl;
			cout << "와! 황금고블린에서 골드가 쏟아져나옵니다!!" << endl;
			cout << endl;
			cout << "500골드 획득!" << endl;

			player->SetGold(player->GetGold() + 500);
		}
		else if (result < 9)
		{
			cout << "실패..." << endl;
			cout << endl;
			cout << "황금고블린은 낄낄 웃으며 포탈을 타고 도망갑니다" << endl;
		}
	}
	NextStage();
}

void Event::Clone(Player* player, Inventory* inventory, Item* item)
{
	Doppelganger doppelganger;
	doppelganger.Set(player, 500);
	cout << "구석에서 무언가 꿈틀거리더니 " << player->GetName() << "의 모습으로 변했다!" << endl;
	cout << endl;
	cout << "전투시작!" << endl;
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
				cout << "승리!" << endl;
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
				cout << "패배..." << endl;
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
				cout << "비겼습니다" << endl;
			}
			system("cls");
		}
		else if (inputA == 2)
		{
			inventory->PrintInventory(inventory);
			cout << endl;
			cout << "사용하고 싶은 아이템의 번호를 누르시오" << endl << endl;
			cout << "나가기 : 9" << endl;
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


