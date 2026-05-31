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
void prinths(ListNude* head); // 打印当前链表内容

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

    prinths(head);
    cout << "--------------------------------" << endl;
    
    // 在单链表头部插入一个新节点 0
    // 步骤1：新建节点
    ListNude* newNude = new ListNude(0);
    // 步骤2：链接节点
    newNude->next = head;
    // 步骤3：将头节点 设为新的节点
    head = newNude;

    prinths(head);
    
    cout << "--------------------------------" << endl;

}
void prinths(ListNude* head) // 打印当前链表内容
{
    ListNude* p_print = head;
    while (p_print) {
        cout << p_print->val << endl;
        p_print = p_print->next;
    }
}