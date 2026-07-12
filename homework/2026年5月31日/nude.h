#ifndef NUDE_H
#define NUDE_H

#include <iostream>
#include <string>
using namespace std;

struct ListNude
{
    int val;
    ListNude* next;
    ListNude(int x, ListNude* nxt) : val(x), next(nxt) {}
};

// 打印链表（参数改为指针）
void printa(ListNude* p_print)
{
    while (p_print)
    {
        cout << p_print->val << endl;
        p_print = p_print->next;
    }
}

#endif