#include "Shop.h"

Shop::Shop()
{
	shopItems.push_back(new SkillCard("��ųī��.����", 200, 1, "��� �ֻ��� ������ �ϳ� �ٿ��ش�"));
	shopItems.push_back(new SkillCard("��ųī��.�����̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
	shopItems.push_back(new SkillCard("��ųī��.��Ŀ", 500, 3, "����� ü�� - 1"));
	shopItems.push_back(new Potion("��������", 100, 4, 1));
	shopItems.push_back(new Potion("��Ȳ����", 200, 5, 2));
	shopItems.push_back(new Potion("����ȸ������", 500, 6, 10));
}
void Shop::PrintShopInfo()
{
	cout << "��      ����      ��" << endl;
	for (int i = 0; i < shopItems.size(); i++)
	{
		cout << i + 1 << ". " << endl;
		shopItems[i]->PrintInfo();
	}
}