//------------------------------------------------
//  19/10/25 10:41
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

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl;
    cout << "--------------------------------" << endl;

    int c = 1;

    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "*"
                 << " ";
        }
        c++;
        cout << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "第三个内容" << endl;
    cout << "--------------------------------" << endl;

    int total_levels = 5;
    for (int i = 1; i <= total_levels; i++)
    {
        for (int j = 1; j < total_levels - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}