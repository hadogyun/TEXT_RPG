#include "Inventory.h"

Inventory::Inventory()
{

}
void Inventory::AddItem(Item* targetItem)
{
	cout << targetItem->GetName() << "�� ���濡 �־���" << endl;
	slots.push_back(targetItem);
}
void Inventory::UseItem(int index)
{
	slots[index]->Use(SearchId(index));
	slots.erase(slots.begin() + index);
}
void Inventory::PrintInventory(Inventory* inventory)
{
	cout << "-----------�κ��丮------------" << endl;
	for (int i = 0; i < slots.size(); i++)
	{
		slots[i]->PrintInfo();
	}
	cout << "--------------------------------" << endl;
}

int Inventory::SearchId(int index)
{
	return slots[index]->GetId();
}
