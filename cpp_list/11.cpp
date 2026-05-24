#include <iostream>
#include <chrono>
using namespace std;

struct Large {
    int data[1000];  // 大结构体
};

void byValue(Large l);
void byPointer(Large* p);
void byReference(Large& r);
// 若希望返回类型为指针 可以写
// int * func(); 这样返回类型就被指定为 int类型的指针

int main() {
    Large obj = {};

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        byValue(obj);  // 每次拷贝4000字节
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "传值耗时: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << "微秒\n";

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        byPointer(&obj);  // 只传地址（8字节）
    }
    end = chrono::high_resolution_clock::now();
    cout << "指针耗时: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << "微秒\n";

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; i++) {
        byReference(obj);  // 只传引用
    }
    end = chrono::high_resolution_clock::now();
    cout << "引用耗时: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << "微秒\n";

    // 传值耗时: 3459微秒
    // 指针耗时: 122微秒
    // 引用耗时: 57微秒

    // 编译前对引用优化的更激进, 减少了一些判断，例如判空
    return 0;
}


// 1. 传值（有拷贝）
void byValue(Large l) {
    l.data[0] = 1;
}


// 2. 传指针（无拷贝）
void byPointer(Large* p) {
    p->data[0] = 1;           // 便捷写法
    // (*p).data[0] = 1;      // 可以：先解引用，再用.
}

// 3. 传引用（无拷贝）
void byReference(Large& r) {
    r.data[0] = 1;
}