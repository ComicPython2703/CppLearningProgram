#include <iostream>
#include <vector>

using namespace std;
 
int main ()
{
    // // 死循环
    // for( ; ; )
    // {
    //     cout << "嘀嘀嘀" << endl;
    // }
    // // 死循环
    // while(1){
    //     cout << "嘟嘟嘟" << endl;
    // }



    // 局部变量声明
    int a = 10;

    // while 循环执行
    while( a < 20 )
    {
        cout << "a 的值：" << a << endl;
        a++;
    }

    // for 循环执行
    // 起点 终点 步长
    for ( int i=0; i<=3; i++ )
    {
        cout << "i 的值：" << i << endl;
    }


    vector <int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     /* 
    for(int i {0}; i<nums.size(); i++)    这样是会出现警告的
    
    警告如下:
        warning: comparison between signed and unsigned integer expressions [-Wsign-compare]
    意思是 无符号整形 与 有符号的整形 最后不要进行比较

    解决方法：
        简单的方法避开这个经过就是使用 unsigned
    */ 

    // for 循环格式： 初始化；执行条件；自增或自减
    for(unsigned int i {0}; i<nums.size(); i++)
    {
        cout << nums[i] << " " << endl;
    }

    // C++ 11标准 可用 直接遍历
    int a1 [] {1, 2, 3, 4, 5};
    // 可使用 auto 自动类型
    for (auto i: a1)
    {
        cout << i << " " << endl;
    }
   return 0;
}