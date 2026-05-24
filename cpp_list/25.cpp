#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5};

    // 1. 拷贝：复制一份，a 不变
    vector<int> b = a;

    // 2. 移动：所有权转移，a 变空
    vector<int> c = move(a);

    // 3. 引用：只是别名，不拷贝、不移动
    vector<int>& ref = b;

    cout << "a size: " << a.size() << endl;   // 0（被移走了）
    cout << "b size: " << b.size() << endl;   // 5
    cout << "c size: " << c.size() << endl;   // 5
    cout << "ref size: " << ref.size() << endl; // 5（就是 b）

    ref.push_back(666);
    cout << "b 新增后: " << b.back() << endl; // 666（ref 就是 b）
}