//------------------------------------------------
//  2026年3月22日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream> //C:\Windows\apppatch\AppLoc.exe
using namespace std;

int main(void)
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    const int MAX_01 = 3; // 定义 max 最大值
    int  var_03[MAX_01] = {10, 100, 200}; // 定义数组 var03
    int *ptr_03[MAX_01];  // 定义指针

    for (int i = 0; i < MAX_01; i++)
    {
        clog << "赋值给ptr_03" << endl;
        ptr_03[i] = &var_03[i];
    }

    clog << "循环结束" << endl;

    for (int i = 0; i < MAX_01; i++)
    {
        cout << "var的值[" << i << "] = ";
        cout << *ptr_03[i] << endl;
    }
    // cout << nullptr << endl; // 'operator <<' is ambiguous
    
    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl;
    cout << "--------------------------------" << endl;

    const int max_2 = 4; // 只读 max_2 数据,names 数组的长度
    const char *names[max_2] = {
        "csad1",
        "dqwd2",
        "d23dd",
        "d3f4l1t",
    }; // 指针

    for (int i = 0; i < max_2; i++)
    {
        cout << "names的值[" << i << "] = ";
        cout << names[i] << endl;
    }
    
}