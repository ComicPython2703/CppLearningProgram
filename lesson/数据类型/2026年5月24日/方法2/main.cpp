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
};

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;
         
    cout << "方法1" << endl << "--------------------------------" << endl;

    // 方法1
    ListNude n1,n2,n3,n4,n5;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n4.val = 4;
    n5.val = 5;
    
    n5.next = NULL;
    n4.next = &n5;
    n3.next = &n4;
    n2.next = &n3;
    n1.next = &n2;
    ListNude* head = &n1;
    ListNude* p_print = head;
    //cout << p->val << endl;
    while (p_print) {
        std::cout << p_print->val << std::endl;
        p_print = p_print->next;
    }
    
    return 0;

}