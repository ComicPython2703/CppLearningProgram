//------------------------------------------------
//  2026年5月24日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// 单链表 结构体定义
struct ListNude
{
    int val; //元素
    ListNude* next; //指针

    ListNude(int x): val(x),next(NULL){}
    ListNude(int x,ListNude* next) : val(x),next(next) {}
    // 函数名(参数):参数赋值
};

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;
    
    cout << "方法1" << endl << "--------------------------------" << endl;

    ListNude n5(5,nullptr);
    ListNude n4(4,&n5);
    ListNude n3(3,&n4);
    ListNude n2(2,&n3);
    ListNude n1(1,&n2);
    ListNude *head = &n1;
    
    cout << "--------------------------------" << endl;

}