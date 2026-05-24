//------------------------------------------------
//  2026年3月1日 10:51:14 am
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 数组
int len_1 = sizeof(n) / sizeof(n[0]);     // 数组个数

int a1[3][4]{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
int len_2 = sizeof(a1) / sizeof(a1[0]); // 数组a1的长度
int len_3 = sizeof(a1[0]) / sizeof(a1[0][0]);

void outlen(); // 输出当前数组

int main()
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    outlen(); // 未修改
    cout << "初始数组长度: " << len_1 << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    // 修改
    n[0] = 11;

    cout << "修改了0索引" << endl;
    outlen();
    cout << "当前数组长度: " << len_1 << endl;

    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl;
    cout << "--------------------------------" << endl;

    // 修改数组
    cout << "修改数组" << endl;
    for (int i = 0; i < len_1; i++)
    {
        if (i > 3)
        {
            n[i] = n[i + 1];
        }
        if (i == len_1 - 1)
        {
            n[i] = 0;
        }
    }
    outlen();

    cout << "--------------------------------" << endl;
    cout << "第三个内容" << endl;
    cout << "--------------------------------" << endl;

    cout << "查找10是否位于 n 数组" << endl;
    for (int i = 0; i < len_1; i++)
    {
        if (10 == n[i])
        {
            cout << "10在里面!" << endl;
        }
    }
    cout << "--------------------------------" << endl;
    cout << "第三个内容" << endl;
    cout << "--------------------------------" << endl;

    cout << "查找10是否位于 a1 数组" << endl;
    for (int i = 0; i < len_2; i++)
    {
        for (int j = 0; j < len_3; j++)
        {
            if (a1[i][j] == 10)
            {
                cout << "10在里面!" << endl;
            }
        }
    }

    

}

void outlen()
{
    cout << "输出当前数组: ";
    for (int i = 0; i < len_1; i++)
    {
        cout << n[i] << " ";
    }
    cout << endl;
}
