//------------------------------------------------
//  2026年4月26日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include "aaa.h"

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容: 输出数组n的内容" << endl;
    cout << "--------------------------------" << endl;
    vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << n.size() << endl; // 9
    printn(n); 

    cout << "--------------------------------" << endl;
    cout << "第二个内容: 替换数组v的内容" << endl;
    cout << "--------------------------------" << endl;
    vector<int> v = {10, 20, 30, 40, 50};

    printv(v);

    int nl;
    cout << "请输入想要替换的位置," << "最大位置" << v.size() -1 << ": ";
    cin >> nl;

    v.push_back(0);
    if (nl < v.size() -1) 
    {
        for (int i = v.size() - 2; i >= nl; i--)
        {
            v[i + 1] = v[i];
        }
    }
    else{
        cerr << "[ERR]输入的长度超出限制!" << endl;
        cout << "--------------------------------" << endl;
        return 1;
    }

    int input;
    cout << "请输入想要替换的数值: ";
    cin >> input;

    v[nl] = input; // 在输入的内容(指定位置)中替换想要的内容

    printv(v);
    cout << "--------------------------------" << endl;
}
