#include "card_h.h"
// 此处内容: 函数实现
Card Player_select_OneCard(vector <Card>& Player_card_list, int Player_hp_max, int Enemy_hp_max, Card Enemy_one_card)
{
    clog << "随机牌" << endl;
    if (Player_card_list.empty())
    {
        return { "NONE",{0},-1 };
    }

    Card card = Player_card_list[0];

    for (int i = 0; i < Player_card_list.size(); i++)
    {
        if (Player_card_list[i].name == "攻击" && Player_card_list[i].val[0] == 3)
        {
            card = Player_card_list[i];
        }
    }

    // -------
    Player_card_list.erase(Player_card_list.begin());

    return card;
}