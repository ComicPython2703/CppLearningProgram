//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 原生数组内存地址一一对应" << endl;
	cout << "--------------------------------" << endl
		<< endl;
    const int MAX_01 = 3;
    int var_03[MAX_01] = {10, 100, 200};   // 整数数组
    int *ptr_03[MAX_01];                   // 指针数组

    for (int i = 0; i < MAX_01; i++) {
        ptr_03[i] = &var_03[i];            // 将每个元素的地址存入指针数组
    }
    for (int i = 0; i < MAX_01; i++) {
        cout << "var的值[" << i << "] = ";
        cout << *ptr_03[i] << endl;        // 通过指针访问值
    }
}