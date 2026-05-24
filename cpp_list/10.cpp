#include <iostream>
 
using namespace std;
 
int main ()
{
    // 指针基础用法
    int  var = 20;   // 实际变量的声明
    int  *ip;        // 指针变量的声明

    ip = &var;       // 在指针变量中存储 var 的地址


    cout << "var值: " << var << endl;
    // 输出在指针变量中存储的地址
    cout << "ip地址: " << ip << endl;
    // 访问指针中地址的值
    cout << "ip值: " << *ip << endl;

    // C++ 引用 vs 指针
    // 引用很容易与指针混淆，它们之间有三个主要的不同：

    // 不存在空引用，引用必须连接到一块合法的内存。
    // 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
    // 引用必须在创建时被初始化。指针可以在任何时间被初始化。
    // 引用的对象必须是一个变量，而指针必须是一个地址。


    // 偏移指针
    // 定义一个数组
    int arr_01[] = {10, 20, 30, 40, 50};

    // 定义一个指向数组第一个元素的指针
    int* ptr_01 = arr_01;

    // 输出指针指向的元素
    std::cout << "指针当前指向的元素: " << *ptr_01 << std::endl;

    // 递增指针
    ptr_01++;

    // 输出指针指向的元素
    std::cout << "递增指针后指向的元素: " << *ptr_01 << std::endl;

    // 递减指针
    ptr_01--;
    
    // 输出指针递减后指向的元素
    std::cout << "递减指针后指向的元素: " << *ptr_01 << std::endl;
    

    // 同数组 指针比较
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr1 = &arr[1]; // 指向数组的第二个元素
    int* ptr2 = &arr[3]; // 指向数组的第四个元素
    int* ptr3 = &arr[1]; // 指向数组的第二个元素

    // 相等性比较  // 比较指针是否相等
    if (ptr1 == ptr3) {
        std::cout << "ptr1 和 ptr3 指向相同的位置" << std::endl;
    } else {
        std::cout << "ptr1 和 ptr3 指向不同的位置" << std::endl;
    }

    if (ptr1 != ptr2) {
        std::cout << "ptr1 和 ptr2 指向不同的位置" << std::endl;
    } else {
        std::cout << "ptr1 和 ptr2 指向相同的位置" << std::endl;
    }

    // 关系比较 // 同一个数组中多个指针,知道前后位置关系
    if (ptr1 < ptr2) {
        std::cout << "ptr1 指向的元素在 ptr2 指向的元素之前" << std::endl;
    } else {
        std::cout << "ptr1 指向的元素不在 ptr2 指向的元素之前" << std::endl;
    }

    if (ptr2 > ptr1) {
        std::cout << "ptr2 指向的元素在 ptr1 指向的元素之后" << std::endl;
    } else {
        std::cout << "ptr2 指向的元素不在 ptr1 指向的元素之后" << std::endl;
    }


    // 指针 单个元素
    const int MAX1 = 3;
    int  var_02[MAX1] = {10, 100, 200};
    int  *ptr_02;

    // 指针中的数组地址
    ptr_02 = var_02;
    for (int i = 0; i < MAX1; i++)
    {
        cout << "var[" << i << "]的内存地址为 ";
        cout << ptr_02 << endl;

        cout << "var[" << i << "] 的值为 ";
        cout << *ptr_02 << endl;

        // 移动到下一个位置
        ptr_02++;
    }

    // 指针 数组
    const int MAX_01 = 3; // 定义 max 最大值
    int  var_03[MAX_01] = {10, 100, 200}; // 定义数组 var03
    int *ptr_03[MAX_01]; // 

    for (int i = 0; i < MAX_01; i++)
    {
        ptr_03[i] = &var_03[i]; // 赋值为整数的地址
    }
    for (int i = 0; i < MAX_01; i++)
    {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr_03[i] << endl;
    }


    // 指针 字符
    const int MAX_1 = 4;
    const char *names[MAX_1] = {
                "Zara Ali",
                "Hina Ali",
                "Nuha Ali",
                "Sara Ali",
   };
 
   for (int i = 0; i < MAX_1; i++)
   {
      cout << "Value of names[" << i << "] = ";
      cout << names[i] << endl;
   }
    // Value of names[0] = Zara Ali
    // Value of names[1] = Hina Ali
    // Value of names[2] = Nuha Ali
    // Value of names[3] = Sara Ali


    // 容易混淆的概念
    int var_04[3] = {10, 20, 30};
    
    cout << "地址值测试：" << endl;
    cout << "var_04   = " << var_04 << endl;
    cout << "&var_04  = " << &var_04 << endl;
    cout << "&var_04[0] = " << &var_04[0] << endl;
    // 三个输出相同的地址值！
    
    cout << "\n类型大小测试：" << endl;
    cout << "sizeof(var_04)  = " << sizeof(var_04) << endl;    // 12（3*4）
    cout << "sizeof(&var_04) = " << sizeof(&var_04) << endl;   // 8（指针大小）
    
    cout << "\n指针运算测试：" << endl;
    int *p1 = var_04;           // 指向元素的指针
    int (*p2)[3] = &var_04;     // 指向数组的指针
    
    cout << "p1 + 1 = " << p1 + 1 << endl;     // 前进4字节（一个int）
    cout << "p2 + 1 = " << p2 + 1 << endl;     // 前进12字节（整个数组）

    // 地址值测试：
    // var1   = 0x7ffeefbff5cc
    // &var1  = 0x7ffeefbff5cc
    // &var1[0] = 0x7ffeefbff5cc

    // 类型大小测试：
    // sizeof(var1)  = 12
    // sizeof(&var1) = 8

    // 指针运算测试：
    // p1 + 1 = 0x7ffeefbff5d0  （比p1大4）
    // p2 + 1 = 0x7ffeefbff5d8  （比p2大12）




    // 指针指向指针
    int  var_05;
    int  *ptr_05;
    int  **pptr_5;

    var_05 = 3000;

    // 获取 var 的地址
    ptr_05 = &var_05;

    // 使用运算符 & 获取 ptr 的地址
    pptr_5 = &ptr_05;

    // 使用 pptr 获取值
    cout << "var_05 值为 :" << var_05 << endl;
    cout << "*ptr_05 值为:" << *ptr_05 << endl;
    cout << "**pptr_5 值为:" << **pptr_5 << endl;



    // 高级指南 （以上内容教的只是栈指针, 没有教创建堆指针和智能指针）
    // 栈指针：自动释放（指针变量本身，不是它指向的内容）
    // 堆指针：必须手动delete或由智能指针自动释放
    // 最佳实践：优先使用智能指针，让C++自动管理释放时机

   return 0;
}