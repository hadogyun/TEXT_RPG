#include "Inventory.h"

Inventory::Inventory()
{

}
void Inventory::AddItem(Item* targetItem)
{
	cout << targetItem->GetName() << "을 가방에 넣었다" << endl;
	slots.push_back(targetItem);
}
void Inventory::UseItem(Player* player, Monster* monster, int index)
{
	int result = SearchId(index);
	slots[index]->PrintUse(result);
	if (result == 1)
	{
		monster->SetDiceNum(monster->GetDiceNum() - 1);
	}
	else if (result == 2)
	{
		player->SetDiceNum(player->GetDiceNum() + 1);
		player->SetDecreaseDiceNum(player->GetDecreaseDiceNum() + 1);
	}
	else if (result == 3)
	{
		monster->SetHp(monster->GetHp() - 1);
	}
	else if (result == 4)
	{
		player->SetHp(player->GetHp() + 1);
	}
	else if (result == 5)
	{
		player->SetHp(player->GetHp() + 2);
	}
	else if (result == 6)
	{
		player->SetHp(player->GetHp() + 10);
	}
}
void Inventory::UseItem(Player* player, BossMonster* bossmonster, int index)
{
	int result = SearchId(index);
	slots[index]->PrintUse(result);
	if (result == 1)
	{
		bossmonster->SetDiceNum(bossmonster->GetDiceNum() - 1);
	}
	else if (result == 2)
	{
		player->SetDiceNum(player->GetDiceNum() + 1);
		player->SetDecreaseDiceNum(player->GetDecreaseDiceNum() + 1);
	}
	else if (result == 3)
	{
		bossmonster->SetHp(bossmonster->GetHp() - 1);
	}
	else if (result == 4)
	{
		player->SetHp(player->GetHp() + 1);
	}
	else if (result == 5)
	{
		player->SetHp(player->GetHp() + 2);
	}
	else if (result == 6)
	{
		player->SetHp(player->GetHp() + 10);
	}
}
void Inventory::EraseItem(int index)
{
	slots.erase(slots.begin() + index);
}
void Inventory::PrintInventory(Inventory* inventory)
{
	cout << "-----------인벤토리------------" << endl;
	for (int i = 0; i < slots.size(); i++)
	{
		cout << i + 1 << "." << endl;
		slots[i]->PrintInfo();
	}
	cout << "--------------------------------" << endl;
}

int Inventory::SearchId(int index)
{
	return slots[index]->GetId();
}
