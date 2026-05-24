//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    /* 基础 */

    string s1;             //空字符串
    string s2{"hello"};    //列表初始化
    string s3{s2};         //拷贝初始化
    string s4{"hello", 4}; //限制字符串长度为4
    string s5{s2, 1, 3};   //复制s2的 1~3
    //no_code           //5个x

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;

    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl;
    cout << "--------------------------------" << endl;

    /* 赋值 */

    string n1;
    n1 = "Test message";
    cout << "n1: " << n1 << endl;

    string n2{"AUSDF BDSKJB DECAAC"};
    n1 = n2;
    cout << "n1: " << n1 << endl;

    cout << "--------------------------------" << endl;
    cout << "第三个内容" << endl;
    cout << "--------------------------------" << endl;

    /* 拼接 */

    string f1{"C++ = "};
    string f2{"TEEEEESSST"};
    string f3;

    f3 = f1 + f2;

    cout << "f3: " << f3 << endl;
}