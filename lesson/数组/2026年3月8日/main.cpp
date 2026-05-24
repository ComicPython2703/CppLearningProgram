//------------------------------------------------
//  2026年3月1日 10:51:14 am
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 固定大小数组
int currentLen = 10;                          // 当前有效元素个数(可变)

void outlen(); // 输出当前数组

int main()
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl << endl;

    outlen(); // 输出初始数组
    cout << "初始数组长度: " << currentLen << endl;

    cout << "--------------------------------" << endl;
    cout << "请输入要删除的元素索引(0 ~ " << currentLen - 1 << "): ";
    int index;
    cin >> index;

    // 检查索引有效性
    if (index < 0 || index >= currentLen)
    {
        cerr << "索引超出范围！" << endl;
        return 1;
    }

    // 删除指定索引的元素：将后面所有元素前移一位
    for (int i = index; i < currentLen - 1; i++)
    {
        n[i] = n[i + 1];
    }
    currentLen--; // 有效长度减1

    cout << "删除后的长度: " << currentLen << endl;
    cout << "删除后的内容: ";
    outlen();

    return 0;
}

void outlen()
{
    cout << "输出当前数组: ";
    for (int i = 0; i < currentLen; i++)
    {
        cout << n[i] << " ";
    }
    cout << endl;
}