#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

struct large // 大结构体
{
    int data[1000];
};

// 1. 传值（有拷贝）
void byValue(large l)
{
    l.data[0] = 1;
}

// 2. 传指针（无拷贝）
void byPointer(large *p)
{
    p->data[0] = 1; // 便捷写法
    // (*p).data[0] = 1;      // 可以：先解引用，再用.
}

// 3. 传引用（无拷贝）
void byReference(large &r)
{
    r.data[0] = 1;
}

void timer(steady_clock::time_point &end, steady_clock::time_point &start)
{
    cout << "传值耗时: " << duration_cast<microseconds>(end - start).count() << "微妙\n";
}