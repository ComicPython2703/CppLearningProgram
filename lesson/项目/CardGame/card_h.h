#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Card // 卡牌结构体
{
    string name; // 卡牌类型
    vector<int> val; // 值
    int card_type; 
};

 
Card Player_select_OneCard( // 玩家选择一张牌
    vector <Card>&Player_card_list,
    int Player_hp_max,
    int Enemy_hp_max,
    Card Enemy_one_card
); 

Card Player_select_OneCard(vector <Card>&Player_card_list,int Player_hp_max,int Enemy_hp_max,Card Enemy_one_card);

#endif // DEBUG

