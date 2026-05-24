#include <iostream>
using namespace std;

// 注意: 这里的数组没有扩容


// 第一步:定义链表节点（存储key-value对）
struct HashNode {
    int key;        // 键
    int value;      // 值
    HashNode* next; // 指向下一个节点（解决冲突）

    // 节点构造函数
    HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
};

// 第二步:进阶版哈希表（链地址法）
class HashTable {
private:
    static const int TABLE_SIZE = 5; // 哈希表大小（数组长度）
    HashNode* table[TABLE_SIZE];     // 关键点 数组内存储的链表的头节点

    // 哈希函数:取余（和极简版一致）
    int hashFunc(int key) {
        return key % TABLE_SIZE;
    }

public:
    // 构造函数:初始化数组，所有位置设为nullptr（空链表）
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // 析构函数:释放所有链表节点内存（避免泄漏）
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode* curr = table[i];
            while (curr != nullptr) {
                HashNode* temp = curr;
                curr = curr->next;
                delete temp; // 释放单个节点
            }
        }
    }

    // 1. 插入/更新key-value（核心:冲突时追加到链表）
    void insert(int key, int value) {
        int index = hashFunc(key); // 计算索引
        HashNode* curr = table[index];

        // 情况1:该索引下已有节点，先检查是否存在相同key（存在则更新值）
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                cout << "更新成功:key=" << key << " → 新值=" << value << endl;
                return;
            }
            curr = curr->next;
        }

        // 情况2:无相同key，新建节点插入链表头部（最简单的插入方式）
        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[index]; // 新节点指向原链表头
        table[index] = newNode;       // 链表头更新为新节点
        cout << "插入成功:key=" << key << " → 索引=" << index << endl;
    }

    // 2. 根据key查找value
    int find(int key) {
        int index = hashFunc(key);
        HashNode* curr = table[index];

        // 遍历该索引下的链表
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value; // 找到key，返回对应值
            }
            curr = curr->next;
        }

        // 未找到key
        cout << "查找失败:key=" << key << " 不存在" << endl;
        return -1;
    }

    // 3. 根据key删除节点
    void remove(int key) {
        int index = hashFunc(key);
        HashNode* curr = table[index];
        HashNode* prev = nullptr; // 记录前驱节点

        // 遍历链表找目标key
        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        // 情况1:未找到key
        if (curr == nullptr) {
            cout << "删除失败:key=" << key << " 不存在" << endl;
            return;
        }

        // 情况2:找到key，删除节点
        if (prev == nullptr) {
            // 要删除的是链表头节点
            table[index] = curr->next;
        }
        else {
            // 要删除的是中间/尾节点
            prev->next = curr->next;
        }
        delete curr; // 释放节点内存
        cout << "删除成功:key=" << key << endl;
    }
};

// 测试进阶版哈希表
int main() {
    HashTable ht;

    // 1. 插入测试（包含冲突场景）
    ht.insert(6, 666);  // 6%5=1 → 索引1，插入成功
    ht.insert(11, 1111); // 11%5=1 → 索引1，冲突，追加到链表
    ht.insert(6, 6666);  // 更新key=6的值
    ht.insert(3, 333);   // 3%5=3 → 索引3，插入成功

    // 2. 查找测试
    cout << "\n查找key=6:" << ht.find(6) << endl;   // 输出6666
    cout << "查找key=11:" << ht.find(11) << endl;  // 输出1111
    cout << "查找key=99:" << ht.find(99) << endl;  // 提示不存在

    // 3. 删除测试
    cout << "\n";
    ht.remove(11);      // 删除key=11
    ht.remove(99);      // 提示删除失败
    cout << "删除后查找key=11:" << ht.find(11) << endl; // 提示不存在

    return 0;
}