#include <iostream>
#include <vector> 
using namespace std;

// 核心：栈对象持有vector，自动管理堆内存，add函数添加元素
// 虽然代码 全程无手动 new/delete 但在vector 底层在扩容时是会使用new/delete
class StackObjAutoHeap {
private:
    vector<int> vec; 

public:
    // 构造函数：用类名，默认构造
    StackObjAutoHeap() = default;  // 可省略

    // add函数：操作正确的成员变量vec，打印容量验证堆内存扩容
    void add(int value) {
        vec.push_back(value); // 修正：用vec而非data
        cout << "添加元素" << value << "后,vector容量:" << vec.capacity() << endl;
    }

    // 析构函数：自动释放堆内存，无手动delete
    ~StackObjAutoHeap() {
        cout << "栈对象销毁 → vector自动释放堆内存" << endl;
    }
};

int main() {
    cout << "进入局部作用域" << endl;
    {
        StackObjAutoHeap obj; // 栈上对象，默认构造
        obj.add(10);          // 调用add添加元素，vector自动分配堆内存
    } // 出作用域：obj析构 → vec析构 → 堆内存自动释放
    cout << "离开局部作用域（堆内存已自动释放）" << endl;

    return 0;
}