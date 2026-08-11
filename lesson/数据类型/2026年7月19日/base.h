#include <iostream>
#include <vector>
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

/* 创建链表
将vector数组转换为链表 */
ListNude* createLinkedList(vector<int> arr){
    /* 判空 */
    if (arr.empty())
    {
        cerr << "[ERR]检测到空内容! 返回空指针!" << endl;
        return nullptr;/* 危险,空指针 */
    }
    ListNude* head = new ListNude(arr[0]);
    ListNude* cur = head;
    for (int i = 1; i < arr.size(); i++)
    {
        cur -> next = new ListNude(arr[i]);
        cur = cur ->next;
    }
    return head;
}

void print_node(ListNude* head) // 打印当前链表内容
{
    ListNude* p_print = head;
    while (p_print) {
        cout << p_print->val << " ";
        p_print = p_print->next;
    }
    cout << endl;
}