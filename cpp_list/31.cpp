#include <iostream>
using namespace std;

// 最简单的哈希函数：普通函数，key对数组大小取模
int hashFunc(int key) {
    return key % 5; // 数组大小固定为5，索引范围0~4
}

int main() {
    // 1. 哈希表核心：固定大小的数组（存储容器）
    int hash_table[5] = { 0 }; // 初始值全0，放弃空值标记，极致简化

    // 2. 存值（哈希表核心操作1）：key→哈希函数→索引→存值
    int key1 = 6, value1 = 666;
    hash_table[hashFunc(key1)] = value1; // 6%5=1 → 索引1存666

    int key2 = 3, value2 = 1111;
    hash_table[hashFunc(key2)] = value2; // 11%5=1 → 冲突，覆盖索引1的值

    // 3. 取值（哈希表核心操作2）：key→哈希函数→索引→取值
    cout << "key=" << key1 <<" 对应值：" << hash_table[hashFunc(6)] << endl;  // 输出1111（被覆盖）
    cout << "key=" << key2 <<" 对应值：" << hash_table[hashFunc(3)] << endl;  // 3%5=3 → 输出1111

    return 0;
}