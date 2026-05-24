#include <iostream>
#include <cstdlib>  // malloc 需要
using namespace std;


class Test {
public:
    Test() { cout << "构造函数" << endl; }
    ~Test() { cout << "析构函数" << endl; }
};

int main() {

    // 在堆上分配内存的方式
    // malloc:分配内存
    // free:释放 malloc 分配的内存
    //
    // new:分配内存 + 调用构造函数
    // delete:调用析构函数 + 释放内存
    //
    // realloc:调整已分配内存的大小

    // 使用指针的解释
    // new/malloc 给你的是内存地址，C++ 里只能用指针来存地址，所以必须用指针！
    // 内存就像酒店房间
    // 指针就像房间号
    // new就像开房,前台给你房间号(指针)
    // 你想进房间（操作内存），必须用房间号（指针）
    
    // 开房（分配内存）
    // int* roomNumber = new int;  // 前台给你房间号
    // // 进房间（使用内存）
    // *roomNumber = 100;  // 通过房间号进去放东西
    // // 退房（释放内存）
    // delete roomNumber;  // 告诉前台退房

    // new 分配一个整数
    int* p = new int;
    *p = 100;
    cout << *p << endl;  // 输出 100
    delete p;            // 释放
    
    // new 分配数组
    int* arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    cout << arr[0] << "," << arr[1] << endl;  // 输出 1,2
    delete[] arr;        // 释放数组


    // malloc 分配一个整数
    int* p = (int*)malloc(sizeof(int));
    *p = 200;
    cout << *p << endl;  // 输出 200
    free(p);             // 释放
    
    // malloc 分配数组
    int* arr = (int*)malloc(5 * sizeof(int));
    arr[0] = 3;
    arr[1] = 4;
    cout << arr[0] << "," << arr[1] << endl;  // 输出 3,4
    free(arr);           // 释放


    // 先分配3个整数的空间
    int* arr = (int*)malloc(3 * sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    // realloc 扩大到5个整数
    arr = (int*)realloc(arr, 5 * sizeof(int));
    arr[3] = 4;
    arr[4] = 5;
    
    // 输出所有元素
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";  // 输出 1 2 3 4 5
    }
    cout << endl;
    
    free(arr);  // 释放
    


    // new:会调用构造函数
    Test* p1 = new Test();
    delete p1;  // 会调用析构函数
    
    // malloc:只分配内存，不调用构造函数
    Test* p2 = (Test*)malloc(sizeof(Test));
    free(p2);   // 只释放内存，不调用析构函数

    return 0;
}