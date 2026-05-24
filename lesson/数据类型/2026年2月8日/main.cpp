//------------------------------------------------
//  2026年2月8日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl // 线
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    string munStr = "213"; // 转换示例
    cout << "未转换为int的 munStr 的typeid: " << typeid(munStr).name() << endl;

    int num = stoi(munStr); // 开始转换

    cout << "num的值: " << num << endl; 

    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl; 
    cout << "--------------------------------" << endl;

    int a1 = 2;
    cout << "a1的typeid: " << typeid(a1).name() << endl;

    cout << "转换后的 munStr 的typeid: " << typeid(munStr).name() << endl;
    cout << "num的typeid: " << typeid(num).name() << endl;
    
}
