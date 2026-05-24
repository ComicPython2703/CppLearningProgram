#include <iostream>
using namespace std;


int main ()
{
    // 强制数据类型转换
    char c='1';
    short s='1';
    int n = 1;
    long l = 1;
    float f = 1;
    double d = 1;

    int p = 0;

    int cc = (int)c;
    // 注意：字符 转 整形时 是有问题的
    // “1”是 49
    cout << cc << endl;

    p = ((int)n + (int)l + (double)f);
    // 类型转换
    cout << (int)p << endl;
    


    // 返回类型为 char
    // 自动判断类型
    // 三元表达式  条件 ？ 成立则执行 ：不成立则执行；

    int x = 10;
    auto c = x >= 10 ? 'Y' : 'N';

	// 查看类型
    cout << typeid(c).name() << endl;
    cout << c << endl;

    //  取反  注意只能返回 0 和 1
    cout << !(x == 10) << endl;


    return 0;
}