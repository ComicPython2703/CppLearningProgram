//------------------------------------------------
//  2026年5月24日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 单链表 结构体定义
struct ListNude
{
    int val; //元素
    ListNude* next; //指针

    ListNude(int x): val(x),next(NULL){}
    ListNude(int x,ListNude* next) : val(x),next(next) {}
};


int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;

    cout << "方法1" << endl;
    // ------------方法1------------------
    
    ListNude n1,n2,n3,n4,n5;
    n1.val = 1; // 赋值12345
    n2.val = 2;
    n3.val = 3;
    n4.val = 4;
    n5.val = 5;

    n5.next = NULL;//先赋值给n5-> next,下一个,让下一个地址先存在 // 节点地址 
    n4.next = &n5; // 地址复制给指针
    n3.next = &n4; //  & -> 引用
    n2.next = &n3;
    n1.next = &n2;
    ListNude* head = &nl; // 头,线头摘些一个,头地址,
    
    cout << "方法2" << endl;
    // ------------方法2------------------




}