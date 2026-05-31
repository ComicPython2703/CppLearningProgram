#include<iostream>
#include<string> 
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) :val(x), next(NULL) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

// 输入一个数组，转换为一条单链表
ListNode* createLinkedList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

int main() {

    //// 方法1
    //ListNode n1,n2,n3,n4,n5;
    //n1.val = 1;
    //n2.val = 2;
    //n3.val = 3;
    //n4.val = 4;
    //n5.val = 5;
    //
    //n5.next = NULL;
    //n4.next = &n5;
    //n3.next = &n4;
    //n2.next = &n3;
    //n1.next = &n2;
    //ListNode* head = &n1;

    //// 方法2
    //ListNode n5(5, NULL);
    //ListNode n4(4, &n5);
    //ListNode n3(3, &n4);
    //ListNode n2(2, &n3);
    //ListNode n1(1, &n2);
    //ListNode *head = &n1;

    //// 方法3
    //ListNode* n1 = new ListNode(1);
    //ListNode* n2 = new ListNode(2);
    //ListNode* n3 = new ListNode(3);
    //n3->next = n2;
    //n2->next = n1;
    //n1->next = NULL;
    //ListNode* head = n3;
    
   /*  // 正确释放（先保存下一个节点的地址，再释放当前）
    ListNode* temp = nullptr;
    while(head != NULL) {
        temp = head->next; // 先记住下一个节点的地址
        delete head;       // 释放当前节点
        head = temp;       // 移动到下一个节点
    } */
    // // 释放后把指针置空，避免野指针
    // n1 = nullptr;
    // n2 = nullptr;
    // n3 = nullptr;

    // 创建一条单链表
    ListNode* head = createLinkedList({ 1, 2, 3, 4, 5 });


    // 在单链表头部插入一个新节点 0
    // 步骤1：新建节点
    ListNode* newNode = new ListNode(0);
    // 步骤2：链接节点
    newNode->next = head;
    // 步骤3：将头节点 设为新的节点
    head = newNode;


    // 在单链表尾部插入一个新节点 6
    ListNode* p = head;
    // 先走到链表的最后一个节点
    while (p->next != nullptr) {
        p = p->next;
    }
    // 现在 p 就是链表的最后一个节点
    // 在 p 后面插入新节点
    p->next = new ListNode(6);


    //// 在第 3 个节点后面插入一个新节点 66
    //// 先要找到前驱节点，即第 3 个节点
    //ListNode* p = head;

    //// 步骤1：找到插入的位置
    //for (int i = 0; i < 2; i++) {
    //    p = p->next;
    //}
    //// 此时 p 指向第 3 个节点
    //// 组装新节点的后驱指针
    //ListNode* newNode = new ListNode(66);  // 步骤2：新建节点
    //newNode->next = p->next;  // 步骤3：新节点的下一个指针 指向 后节点(前节点的下一个指针)
    //// 步骤4：前节点的下一个指针 指向新节点
    //p->next = newNode;

    //// 删除第 4 个节点，要操作前驱节点
    //ListNode* p = head;
    //for (int i = 0; i < 2; i++) {
    //    p = p->next;
    //}
    //// 此时 p 指向第 3 个节点，即要删除节点的前驱节点
    //// 把第 4 个节点从链表中摘除
    //p->next = p->next->next;

    //// 删除尾节点
    //ListNode* p = head;
    //// 找到倒数第二个节点
    //while (p->next->next != nullptr) {
    //    p = p->next;
    //}
    //// 此时 p 指向倒数第二个节点
    //// 把尾节点从链表中摘除
    //p->next = nullptr;

    //// 删除头结点
    //head = head->next;

    // 打印链表内容
    ListNode* p_print = head;
    //cout << p->val << endl;
    while (p_print) {
        std::cout << p_print->val << std::endl;
        p_print = p_print->next;
    }
    return 0;
}








