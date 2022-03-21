#include "Shop.h"

Shop::Shop()
{
	shopItems.push_back(new SkillCard("♥ 퀸", 200, 1, "상대 주사위 갯수를 하나 줄여준다"));
	shopItems.push_back(new SkillCard("♠ 에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
	shopItems.push_back(new Potion("빨강포션", 100, 1, 4));
	shopItems.push_back(new Potion("주황포션", 200, 2, 5));
	shopItems.push_back(new Potion("완전회복포션", 500, 10, 6));
}
void Shop::PrintShopInfo()
{
	cout << "◇      상점      ◇" << endl;
	for (int i = 0; i < shopItems.size(); i++)
	{
		cout << i + 1 << ". " << endl;
		shopItems[i]->PrintInfo();
	}
}