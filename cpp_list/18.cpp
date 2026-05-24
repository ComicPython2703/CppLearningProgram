#include<iostream>
#include<string> 
#include <vector>
using namespace std;

// 双链表节点
class DoublyListNode {
public:
   int val;
   DoublyListNode* prev;  // 前驱指针
   DoublyListNode* next;  // 后继指针
   DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

DoublyListNode* createDoublyLinkedList(const vector<int>& arr) {
   if (arr.empty()) {
       return NULL;
   }
   DoublyListNode* head = new DoublyListNode(arr[0]);
   DoublyListNode* cur = head;
   // for 循环迭代创建双链表
   for (int i = 1; i < arr.size(); i++) {
       DoublyListNode* newNode = new DoublyListNode(arr[i]);
       cur->next = newNode;
       newNode->prev = cur;
       cur = cur->next;
   }
   return head;
}
int main() {

   // 插入
   // 创建一条双链表
   //DoublyListNode* head = createDoublyLinkedList({ 1, 2, 3, 4, 5 });

   //// 在双链表头部插入新节点 0
   //DoublyListNode* newHead = new DoublyListNode(0);
   //newHead->next = head;
   //head->prev = newHead;
   //head = newHead;

   // 想要插入到索引 3（第 4 个节点）
   // 需要操作索引 2（第 3 个节点）的指针
   //DoublyListNode* p = head;
   //for (int i = 0; i < 2; i++) {
   //    p = p->next;
   //}
   //// 组装新节点
   //DoublyListNode* newNode = new DoublyListNode(66);
   //newNode->next = p->next;
   //newNode->prev = p;
   //// 插入新节点
   //p->next->prev = newNode;
   //p->next = newNode;


   

   // 原始创建、遍历、
   //// 1. 创建3个独立节点
   //DoublyListNode* node1 = new DoublyListNode(1);  // 第一个节点（值1）
   //DoublyListNode* node2 = new DoublyListNode(2);  // 第二个节点（值2）
   //DoublyListNode* node3 = new DoublyListNode(3);  // 第三个节点（值3）
   //// 2. 双向链接：node1 ←→ node2 ←→ node3
   //// node1 和 node2 绑定
   //node1->next = node2;  // node1的下一个是node2
   //node2->prev = node1;  // node2的上一个是node1
   //// node2 和 node3 绑定
   //node2->next = node3;  // node2的下一个是node3
   //node3->prev = node2;  // node3的上一个是node2
   //// 3. 验证：正向遍历（从node1到node3）
   //cout << "正向遍历：";
   //DoublyListNode* cur = node1;  // 从第一个节点开始
   //while (cur != nullptr) {
   //    cout << cur->val << " ";
   //    cur = cur->next;  // 往后走
   //}
   //cout << endl;
   //// 4. 验证：反向遍历（从node3到node1）
   //cout << "反向遍历：";
   //cur = node3;  // 从最后一个节点开始
   //while (cur != nullptr) {
   //    cout << cur->val << " ";
   //    cur = cur->prev;  // 往前⾛
   //}
   //cout << endl;

   // 删除
   // 创建一个双链表
   DoublyListNode* head = createDoublyLinkedList({ 1, 2, 3, 4, 5 });
   // 删除第 4 个节点
   // 先找到第 3 个节点
   DoublyListNode* p = head;
   for (int i = 0; i < 2; ++i) {
       p = p->next;
   }

   // 现在 p 指向第 3 个节点，我们将它后面那个节点摘除出去
   DoublyListNode* toDelete = p->next;
   // 把 toDelete 从链表中摘除
   p->next = toDelete->next;
   toDelete->next->prev = p;
   // 把 toDelete 的前后指针都置为 null 是个好习惯（可选）
   toDelete->next = nullptr;
   toDelete->prev = nullptr;

   //// 现在链表变成了 1 -> 2 -> 3 -> 5
   

   //// 创建一个双链表
   //DoublyListNode* head = createDoublyLinkedList({ 1, 2, 3, 4, 5 });
   //DoublyListNode* p = head;
   //// 找到尾结点
   //while (p->next != nullptr) {
   //    p = p->next;
   //}
   //// 现在 p 指向尾节点
   //// 把尾节点从链表中摘除
   //p->prev->next = nullptr;
   //// 把被删结点的指针都断开是个好习惯（可选）
   //p->prev = nullptr;
   //// 现在链表变成了 1 -> 2 -> 3


   // 遍历
   // 创建一条双链表
   //DoublyListNode* head = createDoublyLinkedList({ 1, 2, 3, 4, 5 });
   //DoublyListNode* tail = nullptr;
   // 从头节点向后遍历双链表
   for (DoublyListNode* p = head; p != nullptr; p = p->next) {
       cout << p->val << endl;
       //tail = p;
   }
   //cout << endl;
   //// 从尾节点向前遍历双链表
   //for (DoublyListNode* p = tail; p != nullptr; p = p->prev) {
   //    cout << p->val << endl;
   //}

   return 0;
}




// 用灵活的内存分配和O(1)的插入删除，换取了随机访问的O(n)性能。在数据动态变化、无法预知大小的场景下，链表比数组更合适。

//      场景	          链表优势	          对比数组的劣势
// 1. 大小动态变化	  按需分配，无浪费	    需要预分配或扩容复制
// 2. 只在两端操作	  O(1)入队出队	        可能需要循环或扩容      
// 3. 内存碎片严重	  利用分散小内存	        需要连续大块内存
// 4. 频繁合并拆分	  O(1)连接/断开	        O(n)复制元素
// 5. 深度不可预测	  无限深度（直到内存满）	 最大深度受限
// 6. 大文件处理	  分块加载，内存友好	     需要整个文件内存


// 用链表实现队列


// 数组：像搬实物，要把书从书架中间拿到最前面，需要把前面的书都往后挪一格。
// 链表：像改目录，只要在目录里把这本书的名字划掉，写在最前面。书本身还在原来的位置。
// LRU需要：频繁把"书"从中间拿到最前面，所以用"改目录"（链表）比"搬书"（数组）快得多。