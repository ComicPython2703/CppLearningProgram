//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void) {
    cout << "=========================================================" << endl;
    cout << "           菜单                  " << endl ;
    cout << "=========================================================" << endl;

    int a;
    cout << "输入编号: ";
    cin  >> a;

    float ap1 = 3.00;
    float ap2 = 2.50;
    float ap3 = 4.10;
    float ap4 = 10.20;

    switch (a)
    {
    case 1:
        /* code */
        cout << "物品: apple 价格: " << ap1 << endl;
        break;
    case 2:
        /* code */
        cout << "物品: pears 价格: " << ap2 << endl;
        break;
    case 3:
        /* code */
        cout << "物品: oranges 价格: " << ap3 << endl;
        break;
    case 4:
        /* code */
        cout << "物品: grapes 价格: " << ap4 << endl;
        break;
    default:
        cerr << "没有" << endl;
        break;
    }
}