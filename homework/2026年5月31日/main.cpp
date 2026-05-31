//------------------------------------------------
//  2026年5月31日 10:32
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

    ListNude(int x,ListNude* next): val(x),next(next){}
};

int main(){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;

    ListNude n5(5,NULL);
    ListNude n4(4,&n5);
    ListNude n3(4,&n4);
    ListNude n2(4,&n3);
    ListNude n1(4,&n2);

    ListNude *head = &n1;

}
