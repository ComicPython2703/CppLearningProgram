// CardGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//------------------------------------------------
//  2026年5月10日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include "card_h.h"

vector <Card>Player_card_list{ // 玩家卡牌列表
    {"攻击",{1},1},
    {"攻击",{3},1},
    {"中毒",{1,1,1},1},
    {"护盾",{1,1,1},0}
};

Card E_i = {"攻击",{1},1}; // 敌人出的牌

int P_hp_max = 3; // 玩家最大生命值
int E_hp_max = 5; // 敌人生命最大值

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;

    Card p_i = Player_select_OneCard(Player_card_list,P_hp_max,E_hp_max,E_i);
    cout << p_i.name << endl;
    for (int i = 0; i < p_i.val.size(); i++)
    {
       cout << p_i.val[i] << "";
    }
    cout << endl;
    cout << p_i.card_type << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
