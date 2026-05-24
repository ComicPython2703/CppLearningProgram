//------------------------------------------------
//  2026年3月15日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
	cout << "--------------------------------" << endl
		<< endl;
    
    int var = 20;
    int *ip;

    ip = &var;

    cout << "var 的值: " << var << endl; // 输出在指针变量中存储的地址
    cout << "var 的 ip 地址: " << ip << endl;
    cout << "ip 值 : " << *ip << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    int arr_0[] = {10,20,30,40,50}; // 定义数组

    int* ptr_01 = arr_0;

    cout << "指针当前指向的元素: " << *ptr_01 << endl;

    ptr_01++;
    
    cout << "递增指针后指向的元素: " << *ptr_01 << endl;

    ptr_01--;

    cout << "递减指针后指向的元素: " << *ptr_01 << endl; 


}   