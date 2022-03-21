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
		cout << "===================================" << endl;
		cout << "          Dice Adventure        " << endl;
		cout << "===================================" << endl;
		cout << endl;
		cout << endl;
		cout << "1. 시작하기" << endl;
		cout << "2. 종료" << endl;
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
		cout << "1. 진행하기" << endl;
		cout << "2. 플레이어 정보확인" << endl;
		cout << "3. 인벤토리 확인" << endl;
		cout << endl;
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
	cout << "왕국령 310년" << endl;
	cout << "몬스터들이 창궐하여 이 세계는 큰 혼란에 빠지게 된다" << endl;
	cout << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "그 때, 주신인 주사위 여신이 나타나 한 사람에게" << endl;
	cout << "주사위를 주며 이 세계를 구해달라고 한다" << endl;
	cout << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "여신 : 용사님 부디 주사위로 이 세계를 구원해주세요.." << endl;
	cout << endl;
	event.NextStage();
	system("cls");
	cout << endl;
	cout << "자, 모험을 시작해보자!" << endl;
	cout << endl;
	event.NextStage();
	system("cls");
}

void System::Explanation()
{
	cout << endl;
	cout << "◇   게임 진행방식 설명   ◇" << endl;
	cout << endl;
	cout << "기본적으로 주사위로 거의 모든걸 진행합니다" << endl;
	cout << "하나의 스테이지는 랜덤하게 발생한 두가지 이벤트들에서" << endl;
	cout << "하나를 골라서 진행하게 됩니다" << endl;
	cout << "10번의 이벤트 진행 후 보스전을 하게 되고" << endl;
	cout << "보스몬스터를 세 번 무찌르면 클리어하게 됩니다." << endl;
	cout << "전투는 서로 주사위들을 던져서 합이 더 높은 쪽이 승리합니다" << endl;
	cout << endl;
	cout << "그럼 건투를 빕니다" << endl;
	cout << endl;
	event.NextStage();
	system("cls");
}

void System::EventOccur(Player* player, Monster* monster, Shop* shop, Inventory* inventory, Item* item, int num)
{
	if (num == 1)
	{
		event.Battle(player, monster, inventory, item);
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
void System::ChooseOptions(Player* player, Monster* monster, Shop* shop, Inventory* inventory, Item* item)
{
	int input;

	int resultA = Random();
	int resultB = Random();

	for (; resultA == resultB;)
	{
		resultB = Random();
	}
	cout << "A" << resultA << endl;
	cout << "B" << resultB << endl;

	cout << "선택지를 골라주세요" << endl;
	cout << "1. " << event.EventName(resultA) << endl;
	cout << "2. " << event.EventName(resultB) << endl;
	cin >> input;

	if (input == 1)
	{
		EventOccur(player, monster, shop, inventory, item, resultA);
	}
	else if (input == 2)
	{
		EventOccur(player, monster, shop, inventory, item, resultB);
	}
}
void System::Ending()
{
	system("cls");
	cout << endl;
	cout << "축하드립니다 클리어하셨습니다!" << endl;
}
