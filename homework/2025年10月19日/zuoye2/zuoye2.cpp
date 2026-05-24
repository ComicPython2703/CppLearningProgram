//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void) {
    int a;
    cout << "输入数字: ";  // 确保使用半角引号，补充冒号更规范
    cin  >> a;

    switch (a)
    {
    case 1:
        cout << "星期一" << endl;
        break;
    case 2:
        cout << "星期二" << endl;
        break;
    case 3:
        cout << "星期三" << endl;
        break;
    case 4:
        cout << "星期四" << endl;
        break;
    case 5:
        cout << "星期五" << endl;
        break;
    case 6:
        cout << "星期六" << endl;
        break;
    case 7:
        cout << "星期日" << endl;  // 修正"星期七"为"星期日"
        break;
    default:
        cerr << "没有这一天!!!" << endl;  // 修正"天"为"一天"更通顺
        break;
    }
    return 0;  // 补充main函数的返回值
}