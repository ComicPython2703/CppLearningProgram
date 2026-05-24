#include <iostream>
// 用于内存拷贝（可选，也可保留手动循环）
#include <cstring>
using namespace std;

// 核心函数：添加元素，自动检测容量并扩容
// 参数：数组指针（引用传递，因为要修改指针指向）、当前容量（引用）、已存元素数（引用）、要添加的元素
void addElement(int*& arr, int& capacity, int& count, int element) {
    // 步骤1：检测是否已满（已存元素数 >= 容量）
    if (count >= capacity) {
        cout << "\n容量不足（当前容量：" << capacity << "），自动扩容..." << endl;

        // 步骤2：扩容逻辑（原容量×2）
        int new_capacity = capacity * 2;
        int* new_arr = new int[new_capacity]; // 创建新数组

        // 拷贝旧数据（手动循环，新手易理解）
        for (int i = 0; i < count; i++) {
            new_arr[i] = arr[i];
        }
        // 也可以用memcpy（效率更高）：
        // memcpy(new_arr, arr, count * sizeof(int));

        // 步骤3：释放旧数组，更新指针和容量
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
        cout << "扩容完成！新容量：" << capacity << endl;
    }

    // 步骤4：添加新元素（无论是否扩容，最终都添加）
    arr[count++] = element;
    cout << "添加元素 " << element << " 成功，当前已存元素数：" << count << endl;
}

int main() {
    // ========== 初始化数组 ==========
    int capacity = 3;    // 初始容量
    int count = 0;       // 已存元素数
    int* arr = new int[capacity]; // 动态数组

    // ========== 测试自动添加+扩容 ==========
    cout << "初始状态：容量=" << capacity << "，已存元素数=" << count << endl;

    // 连续添加8个元素（超过初始容量3，会触发多次扩容）
    addElement(arr, capacity, count, 1);
    addElement(arr, capacity, count, 2);
    addElement(arr, capacity, count, 3); // 第3个，刚填满初始容量
    addElement(arr, capacity, count, 4); // 触发第一次扩容（3→6）
    addElement(arr, capacity, count, 5);
    addElement(arr, capacity, count, 6);
    addElement(arr, capacity, count, 7); // 触发第二次扩容（6→12）
    addElement(arr, capacity, count, 8);

    // ========== 输出最终结果 ==========
    cout << "\n===== 最终状态 =====" << endl;
    cout << "数组总容量：" << capacity << endl;
    cout << "已存元素数：" << count << endl;
    cout << "数组元素：";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ========== 释放内存 ==========
    delete[] arr;
    return 0;
}