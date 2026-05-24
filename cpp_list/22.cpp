#include <iostream>
#include <string>
#include <vector>
using namespace std; 

//创建类
class Acc
{
//类的权限默认是私有的
//private: 类权限设置为 内部访问
public: // 类权限设置为 公有

    //属性1
    string name{"None"};
    //属性2
    double value{0.0};

    //方法1
    bool fun1(double a1){
        value += a1;
        cout << name << " 加 " << a1 << " 现在：" << value << endl;
        return true;
    };
    //方法2
    bool fun2(double a2){
        value -= a2;
        cout << name << " 减 " << a2 << " 现在：" << value << endl;
    };
};


int main()
{
    //实例化 对象
    Acc l1;

    //修改类属性(语法上可以使用,但不提倡,一般用函数包裹.目的是为了防止意外修改)
    l1.name = "my1";
    l1.value = 1000.0;

    //调用类方法
    l1.fun1(500.0);
    l1.fun2(200.0);


    // 我们可以不使用 但有这种写法
    // //实例化指针
    // Acc *n1 = new Acc();  // 分配内存
    // // (*n1).name = "my2";   // 使用.  加括号提升运算优先级
    // n1->value = 2000.0;   // 使用->
    
    // // (*n1).fun1(50.0);     // 两种方式
    // n1->fun2(2.0);

    // delete n1;            // 释放内存

    return 0;
}
