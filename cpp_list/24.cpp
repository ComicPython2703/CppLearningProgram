#include <iostream>
using namespace std;

// 核心：栈对象持有固定大小的堆数组，add添加新元素（有上限，不扩容），析构自动释放
class StackObjWithHeap {
private:
    int* heap_data;  // 指向堆上的int数组（不再是单个int）
    int current_size; // 当前已添加的元素个数
    int MAX_SIZE; // 数组最大容量（固定，不扩容）

public:
    // 性能写法 : MAX_SIZE(max_size), current_size(0) 初始化更快
    // StackObjWithHeap(int max_size = 5) : MAX_SIZE(max_size), current_size(0) {

    // 构造函数：初始化固定大小的堆数组（指定最大值）
    StackObjWithHeap(int max_size = 5){
        // 初始化 数组容器
        MAX_SIZE = max_size;
        // 初始化 当前元素个数
        current_size = 0;
        // 堆上分配MAX_SIZE个int的数组（初始值为0）
        heap_data = new int[MAX_SIZE](); 
        cout << "栈对象创建 → 堆数组初始化（最大容量：" << MAX_SIZE << "），地址：" << heap_data << endl;
    }

    // add函数：添加新元素（有上限判断，不扩容）
    void add(int value) {
        // 判断是否超过最大值
        if (current_size >= MAX_SIZE) {
            cout << "添加失败！已达最大容量（" << MAX_SIZE << "），无法添加元素" << value << endl;
            return;
        }
        // 向数组末尾添加新元素
        heap_data[current_size] = value;
        current_size++; // 已添加元素数+1
        cout << "添加元素" << value << " → 当前元素数：" << current_size << "/" << MAX_SIZE << endl;
    }

    // 析构函数：释放整个堆数组（自动释放）
    ~StackObjWithHeap() {
        delete[] heap_data; // 释放数组（对应new int[MAX_SIZE]）
        heap_data = nullptr;
        cout << "栈对象销毁 → 堆数组已释放，地址：" << heap_data << endl;
    }
};

int main() {
    cout << "进入局部作用域" << endl;
    {
        StackObjWithHeap obj(3); // 初始化最大容量为3的堆数组
        obj.add(10);            // 添加第1个元素
        obj.add(20);            // 添加第2个元素
        obj.add(30);            // 添加第3个元素
        obj.add(40);            // 尝试添加第4个（超过最大值，失败）
    } // 出作用域：栈对象销毁 → 析构函数释放堆数组
    cout << "离开局部作用域（堆内存已自动释放）" << endl;

    // 当前未考虑扩容
    
    return 0;
}