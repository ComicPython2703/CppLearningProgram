//------------------------------------------------
//  2026年5月31日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include "nude.h" // 只包含头文件，不再重复定义结构体
#include <iostream>
using namespace std;

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    // 创建链表 1->2->3->4->5
    ListNude n5(5, nullptr);
    ListNude n4(4, &n5);
    ListNude n3(3, &n4);
    ListNude n2(2, &n3);
    ListNude n1(1, &n2);
    ListNude *head = &n1;

    // ---------- 删除节点（删除第3个节点，即值为3的节点） ----------
    cout << "删除节点" << endl;
    ListNude *p1 = head;
    for (int i = 0; i < 2; i++)
    {
        p1 = p1->next;
    }
    p1->next = p1->next->next; // 跳过值为3的节点

    printa(head);

    cout << "结束" << endl;

    // ---------- 插入头节点 ----------
    cout << "插入头节点" << endl;
    ListNude *newNode = new ListNude(0, head);
    head = newNode;

    printa(head);

    cout << "结束" << endl;

    // ---------- 插入尾部节点 ----------
    cout << "插入尾部节点" << endl;
    ListNude *p = head;
    while (p->next != nullptr)
    { //  修正条件，找到最后一个节点
        p = p->next;
    }
    p->next = new ListNude(6, nullptr); // 尾部插入新节点

    printa(head);

    cout << "结束" << endl;

    // 释放动态分配的内存（newNode 和 尾部节点），但此处为了简洁省略，实际应添加 delete
    // 注意：栈上的 n1~n5 会自动销毁，但 newNode 和 p->next 需要手动释放
    delete newNode; // 但此时 head 已被更新，需小心释放；实际项目应设计析构函数
    // 更规范的写法是遍历释放所有节点，但本例仅作演示，故不展开

    return 0;
}