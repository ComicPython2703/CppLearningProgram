#ifndef na

#include <iostream>
#include <string>
using namespace std;

// 单链表 结构体定义
struct ListNude
{
    int val; //元素,存储链表内的元素
    ListNude* next; //指针,存储下一个节点地址

    ListNude(int x,ListNude* next): val(x),next(next){} // 节点
};

void printa(ListNude *&p_print) // 
{
    while (p_print)
    {
        cout << p_print->val << endl;
        p_print = p_print->next;
    }
}


#endif