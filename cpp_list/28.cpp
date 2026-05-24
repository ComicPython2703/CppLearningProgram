#include <iostream>
// 可选：用于快速拷贝内存（也可以手动循环拷贝）
#include <cstring>
using namespace std;

int main() {
    // ========== 1. 初始化原始数组 ==========
    // 初始容量（数组能存多少个元素）
    int capacity = 3;
    // 已存元素个数（避免拷贝空位置）
    int count = 0;
    // 动态创建数组（必须用new，才能手动释放内存）
    int* arr = new int[capacity];

    // 先往数组里存2个元素
    arr[count++] = 1;   // count变成1
    arr[count++] = 2;   // count变成2
    cout << "扩容前：" << endl;
    cout << "容量：" << capacity << "，元素：";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  // 输出：1 2

    // ========== 2. 核心：数组扩容 ==========
    // 步骤1：定义新容量（通常扩为原来的2倍，减少频繁扩容）
    int new_capacity = capacity * 2;
    // 步骤2：创建更大的新数组
    int* new_arr = new int[new_capacity];

    // 步骤3：拷贝旧数组的有效数据到新数组
    // 方式1：手动循环（新手优先理解这个）
     for (int i = 0; i < count; i++) {
         new_arr[i] = arr[i];
     }
    // 方式2：memcpy快速拷贝（效率更高，推荐）
    // 参数：目标数组、源数组、拷贝的字节数（元素数 × 单个元素大小）
    //memcpy(new_arr, arr, count * sizeof(int));

    // 步骤4：释放旧数组的内存（必须！否则内存泄漏）
    delete[] arr;

    // 步骤5：更新指针和容量（让原变量指向新数组）
    arr = new_arr;
    capacity = new_capacity;

    // ========== 3. 验证扩容效果 ==========
    // 扩容后可以继续加新元素
    arr[count++] = 3;
    arr[count++] = 4;
    arr[count++] = 5;

    cout << "扩容后：" << endl;
    cout << "容量：" << capacity << "，元素：";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  // 输出：1 2 3 4 5

    // 程序结束前，释放最终的数组内存
    delete[] arr;
    return 0;
}