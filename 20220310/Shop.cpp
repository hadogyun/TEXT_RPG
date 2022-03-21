#include "Shop.h"

Shop::Shop()
{
	shopItems.push_back(new SkillCard("�� ��", 200, 1, "��� �ֻ��� ������ �ϳ� �ٿ��ش�"));
	shopItems.push_back(new SkillCard("�� ���̽�", 200, 2, "�� �ֻ��� ������ �ϳ� �÷��ش�"));
	shopItems.push_back(new Potion("��������", 100, 1, 4));
	shopItems.push_back(new Potion("��Ȳ����", 200, 2, 5));
	shopItems.push_back(new Potion("����ȸ������", 500, 10, 6));
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