//------------------------------------------------
//  2026年8月16日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
     cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
     cout << "--------------------------------" << endl
          << endl;

     string s1; // 空
     string s2 = "Hello";

     cout << "s1是空的,s2是不带括号的Hello" << endl;

     cout << "--------------------------------" << endl;
     cout << " 基本操作" << endl;
     cout << "--------------------------------" << endl;

     cout << "长度" << endl
          << endl;

     cout << "s2的长度: " << s2.length() << endl;
     cout << "s2的大小: " << s2.size() << endl;

     cout << endl
          << "判空" << endl
          << "--------------------------------" << endl;

     if (s1.empty())
     {
          cout << "s1是空的!" << endl;
     }

     cout << endl
          << "访问字符" << endl
          << "--------------------------------" << endl;

     cout << "s2[1]的输出: " << s2[1] << endl;
     cout << "s2[99]的输出(已越界!) :  " << s2[99] << endl;
     cout << endl
          << "s2.at(1)的输出: " << s2.at(1) << endl;
     cout << "s2.at(99)的输出(已越界!),我逝过毒,这里直接展示: " << "发生异常: CPP/std::out_of_range \n Unhandled exception at 0x00007FF86BD65369 in 2026年8月16日.exe: Microsoft C++ exception: std::out_of_range at memory location 0x000000C96E1EFA10." << endl
          << endl;

     cout << "--------------------------------" << endl;
     cout << " 修改内容 " << endl;
     cout << "--------------------------------" << endl;

     cout << endl
          << "末尾追加" << endl
          << "--------------------------------" << endl;

     s1 = "Hello ";
     s1 += "World";    // += 追加
     s1.append("!!!"); // append()

     cout << "追加完毕的s1: " << s1 << endl;

     cout << endl
          << "中间插入" << endl
          << "--------------------------------" << endl;
     s1.insert(6, "Beautiful ");
     cout << "插入完毕的s1: " << s1 << endl;

     cout << endl
          << "删除" << endl
          << "--------------------------------" << endl;
     s1.erase(6, 10);
     // s1.擦除(起始位置,长度)
     cout << "删除完成的s1: " << s1 << endl;

     cout << endl
          << "查找" << endl
          << "--------------------------------" << endl;

     string text1 = "I love C++ programming";
     auto pos1 = text1.find("C++");
     cout << "text1的内容: " << text1 << endl;
     if (pos1 != string::npos)
     {
          cout << "C++在: " << pos1 << endl;
     }

     cout << "--------------------------------" << endl;
     cout << " 字串 " << endl;
     cout << "--------------------------------" << endl;

     string sub = text1.substr(7, 3);
     cout << "sub的内容: " << sub << endl;

     cout << "--------------------------------" << endl;
     cout << " 数字转换 " << endl;
     cout << "--------------------------------" << endl;

     string numStr = "123";
     int mun = stoi(numStr);
     double d = stod("3.14");

     string back = to_string(456);
}
