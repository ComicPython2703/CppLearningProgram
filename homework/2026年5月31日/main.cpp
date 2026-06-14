//------------------------------------------------
//  2026年5月31日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
// #include "nude.h" // 哦好省事啊ヾ(≧▽≦*)o
#include <iostream>
#include <string>
using namespace std;
struct ListNude
{
    int val; //元素,存储链表内的元素
    ListNude* next; //指针,存储下一个节点地址

    ListNude(int x,ListNude* next): val(x),next(next){} // 节点
};
int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;

    ListNude n5(5,NULL); 
    ListNude n4(4,&n5); //地址拿出来,n5是一块地址
    ListNude n3(3,&n4);
    ListNude n2(2,&n3);
    ListNude n1(1,&n2);

    ListNude* head = &n1; // 坐标
    ListNude* p_print = head;
    //cout << p->val << endl;
    //printa(p_print);
    
    // ----------|删除节点|------------
    cout << "删除节点" << endl;

    ListNude* p1 = head;

    for (int i = 0; i < 2; i++) {
       p1 = p1->next;
    }
    p1->next = p1->next->next;

    //printa(p1);
    while (p_print) {
        std::cout << p_print->val << std::endl;
        p_print = p_print->next;
    }
    
    cout << "结束" << endl;

/*     // ----------|插入头节点|------------

    cout << "插入头节点" << endl;

    ListNude* newNode = new ListNude(0,NULL); // 新建节点,地址要用指针存储
    newNode -> next = head; // 下一个指向头节点
    head = newNode; //更新头节点

    printa(newNode);

    cout << "结束" << endl;

    // ----------|插入尾部节点|------------

    cout << "插入尾部节点" << endl;

    ListNude* p = head;
    while (p -> next != nullptr || p -> next != NULL)  // 避免空指针
    {
        p = p->next; // 遍历
    }
    p->next = new ListNude(6,NULL);

    printa(p);

    cout << "结束" << endl; */


}