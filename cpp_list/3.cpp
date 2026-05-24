#include <iostream>  
#include <climits>   // 查看大小 
#include <float.h>   // float 查看大小
using namespace std; // 命名空间定义 使用C++标识符  例如：cout

int main()
{
    // 变量声明的类型
    char a1={'0'};      // 字符型 不是字符串
    short a2{0};        // 整型
    int a3{0};          // 整型
    long a4{0};         // 整型
    long long a5{0};    // 整型
    float a6{0.1};      // 浮点型
    double a7{0.1};     // 浮点型
    bool a8{true};      // 布尔型

    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;
    cout << "a3 = " << a3 << endl;
    cout << "a4 = " << a4 << endl;
    cout << "a5 = " << a5 << endl;
    cout << "a6 = " << a6 << endl;
    cout << "a7 = " << a7 << endl;
    cout << "a8 = " << a8 << endl;
    
    cout << "========================================"<< endl;
	// 查看数据类型名
	cout << typeid(a8).name() << endl;

    // sizeof 查看大小 单位字节
    cout << "char:" << sizeof(char)<< endl;
    cout << "short:" << sizeof(short)<< endl;
    cout << "int:" << sizeof(int)<< endl;
    cout << "long:" << sizeof(long)<< endl;
    cout << "long long:" << sizeof(long long)<< endl;
    cout << "float:" << sizeof(float)<< endl;
    cout << "double:" << sizeof(double)<< endl;
    // cout << "bool:" << sizeof(bool)<< endl;

    cout << "========================================"<< endl;

    // 查看数据类型的范围
    cout << "char min~max:" << CHAR_MIN <<" ~ "<< CHAR_MAX<< endl;
    cout << "short min~max:" << SHRT_MIN <<" ~ "<< SHRT_MAX<< endl;
    cout << "int min~max:" << INT_MIN <<" ~ "<< INT_MAX<< endl;
    cout << "long min~max:" << LONG_MIN <<" ~ "<< LONG_MAX<< endl;
    cout << "long long min~max:" << LLONG_MIN <<" ~ "<< LLONG_MAX<< endl;

    // float.h 导入头文件
    cout << "float min~max:" << FLT_MIN <<" ~ "<< FLT_MAX<< endl;
    cout << "double min~max:" << DBL_MIN <<" ~ "<< DBL_MAX<< endl;

    // 科学计数法字面量
    // double large = 3.0e6;      // 3.0 × 10⁶ = 3,000,000

    return 0;
}
