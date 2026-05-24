#include <iostream>
using namespace std;

int main()
{

    int a1 = 10;
    int a2 = 2;

    cout << a1 + a2 << endl;

    // const 关键字 代表后续不可更改
    int max{100};
    int min{10};

    int i{0};
    cout << "请输入一个 10~100 的正整数:";
    cin >> i; // 输入

    // 与或非 三个运算符 && || !

    // "与" 两个条件同时成立
    // "或" 其中一个条件成立就行
    // "非" 条件结果取反

    if (i <= max && i >= min)
    {
        cout << "正常" << endl;
    }
    else
    {
        cout << "输入错误" << endl;
    }

    // 如果输入的数 大于0 输出正数 否则输出 非正数

    // 最常用的运算符

    // 算术运算符
    // + - * /      加减乘除
    // ++ --        元素自增 自减
    // %            取余数

    // 关系运算符
    // == != >= <= > < 用于判断

    // 逻辑运算符
    // && || !

    // switch 判断
    int score;
    cout << "成绩分级判断 (0-100): ";
    cin >> score;

    switch (score / 10)
    {
    case 10:
    case 9:
        cout << "A " << score << endl;
        break;
    case 8:
        cout << "B " << score << endl;
        break;
    case 7:
        cout << "C " << score << endl;
        break;
    case 6:
        cout << "D " << score << endl;
        break;
    default:
        if (score >= 0 && score <= 59)
            cout << "F " << score << endl;
        else
            cout << "不及格" << score << endl;
    }

    return 0;
}
