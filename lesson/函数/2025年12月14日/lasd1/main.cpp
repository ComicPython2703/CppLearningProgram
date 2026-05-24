//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void majdi(vector<string> v); // 提前告知C++有该函数
/* 如果函数再main下面,那么就需要这样写 */

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;
    vector<string> my_vec{"1", "2", "3"};
    majdi(my_vec);
}

void majdi(vector<string> v)
{
    cout << "testing" << endl;
    for (auto i : v)
    {
        cout << i << endl;
    }
}