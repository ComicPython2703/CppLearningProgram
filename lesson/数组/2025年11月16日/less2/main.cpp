//------------------------------------------------
//  2025-11-06 10:51
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;


    cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

    int n;
    int awq[30];
    cout << "输入n的值: ";
    cin >> n;

    for (size_t i = 1; i <= n; i++)
    {
        awq[i];
        if (i%2 == 0)
        {
            awq[i] = 1;
        }
        if (i%2 == 0)
        {
            awq[i] = 1-awq[i];
        }
        else if (i%3 == 0)
        {
            awq[i] = 1-awq[i];
        }
        else if (i%4 == 0)
        {
            awq[i] = 1-awq[i];
        }
        else if (i%5 == 0)
        {
            awq[i] = 1-awq[i];
        }
        
        cout << i << " " ;
    }
}