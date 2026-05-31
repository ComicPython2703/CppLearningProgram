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
    int val; //元素,存储链表内的元素
    ListNude* next; //指针,存储下一个节点地址

    ListNude(int x,ListNude* next): val(x),next(next){}
};

void printa(ListNude *&p_print);

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;

    ListNude n5(5,NULL);
    ListNude n4(4,&n5);
    ListNude n3(3,&n4);
    ListNude n2(2,&n3);
    ListNude n1(1,&n2);

    ListNude* head = &n1; // 坐标
    ListNude* p_print = head;
    //cout << p->val << endl;
    printa(p_print);

    // ----------|插入头节点|------------

    cout << "插入头节点" << endl;
    ListNude* newNode = new ListNude(0,NULL); // 新建节点
    newNode -> next = head; // 下一个指向头节点
    head = newNode; //更新头节点
    

}

void printa(ListNude *&p_print) // 
{
    while (p_print)
    {
        cout << p_print->val << endl;
        p_print = p_print->next;
    }
}
