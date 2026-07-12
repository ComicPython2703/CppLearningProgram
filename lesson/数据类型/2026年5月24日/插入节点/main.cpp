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
void prinths(ListNude *head); // 打印当前链表内容

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;
         
    cout << "初始化" << endl << "--------------------------------" << endl;

    ListNude n5(5,nullptr); // 结构体  名称()
    ListNude n4(4,&n5);
    ListNude n3(3,&n4);
    ListNude n2(2,&n3);
    ListNude n1(1,&n2);
    ListNude *head = &n1; // 头节点

    prinths(head);
    cout << "头部插入" << endl;
    cout << "--------------------------------" << endl;
    
    // 在单链表头部插入一个新节点 0
    // 步骤1：新建节点
    ListNude* newNude = new ListNude(0); // 新建节点
    // 步骤2：链接节点
    newNude->next = head;
    // 步骤3：将头节点 设为新的节点
    head = newNude;

    prinths(head);
    
    cout << "--------------------------------" << endl << endl;

    cout << "尾部追加" << endl;
    cout << "--------------------------------" << endl;
    ListNude *p = head; // 定义指针 p 指向 头节点
    
    while (p -> next != nullptr)
    {p = p -> next;} // 将指针P走向最后一个节点

    p -> next = new ListNude(6); // 此时p是最后一个节点,在这里新建节点
    
    prinths(head); // 打印


    cout << endl <<"中间插入" << endl;
    cout << "--------------------------------" << endl;
    // 先要找到前驱节点，即第 3 个节点
    ListNude* p1 = head;

    // 步骤1：找到插入的位置
    for (int i = 0; i < 2; i++) {
       p1 = p1->next;
    }
    // 此时 p 指向第 3 个节点
    // 组装新节点的后驱指针
    ListNude* newNode = new ListNude(66);  // 步骤2：新建节点
    newNode->next = p1->next;  // 步骤3：新节点的下一个指针 指向 后节点(前节点的下一个指针)
    // 步骤4：前节点的下一个指针 指向新节点
    p1->next = newNode;

    prinths(head);

    cout << endl <<"删除节点" << endl;
    cout << "--------------------------------" << endl;

    ListNude *p2 = head;
    for (int i = 0; i < 2; i++)
    {
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    prinths(head);
}

void prinths(ListNude* head) // 打印当前链表内容
{
    ListNude* p_print = head;
    while (p_print) {
        cout << p_print->val << ",";
        p_print = p_print->next;
    }
    cout << endl;
}