#include "Shop.h"

Shop::Shop()
{
	shopItems.push_back(new SkillCard("스킬카드.♥퀸", 200, 1, "상대 주사위 갯수를 하나 줄여준다"));
	shopItems.push_back(new SkillCard("스킬카드.♠에이스", 200, 2, "내 주사위 갯수를 하나 늘려준다"));
	shopItems.push_back(new SkillCard("스킬카드.조커", 500, 3, "상대의 체력 - 1"));
	shopItems.push_back(new Potion("빨강포션", 100, 4, 1));
	shopItems.push_back(new Potion("주황포션", 200, 5, 2));
	shopItems.push_back(new Potion("완전회복포션", 500, 6, 10));
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