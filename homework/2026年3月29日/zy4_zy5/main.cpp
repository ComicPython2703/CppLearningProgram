//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 数组
int len_1 = sizeof(n) / sizeof(n[0]);     // 数组个数

int a1[3][4]{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
int len_2 = sizeof(a1) / sizeof(a1[0]); // 数组a1的长度
int len_3 = sizeof(a1[0]) / sizeof(a1[0][0]);

void outlen(int lens);

int main(void)
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 原生数组字节大小" << endl;
    cout << "--------------------------------" << endl
         << endl;

    outlen(1);
    cout << "字节大小: " << sizeof(n) << endl;
}

void outlen(int lens) {
    if (lens == 1) {
        cout << "数组 n 的内容: " ;
        for (int i = 0; i < len_1; ++i)
            cout << n[i] << " " ;
        cout << endl;
    } else {
        cout << "二维数组 a1 的内容:\n";
        for (int i = 0; i < len_2; ++i) {
            for (int j = 0; j < len_3; ++j)
                cout << a1[i][j] << " ";
            cout << endl;
        }
    }
}