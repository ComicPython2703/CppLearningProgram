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

void prinths(ListNude* head) // 打印当前链表内容
{
    ListNude* p_print = head;
    while (p_print) {
        cout << p_print->val <<",";
        p_print = p_print->next;
    }
    cout << endl;
}

ListNude n5(7,nullptr); // 结构体  名称()
ListNude n4(4,&n5);
ListNude n3(6,&n4);
ListNude n2(3,&n3);
ListNude n1(1,&n2);
ListNude *head = &n1; // 头节点
