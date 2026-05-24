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

    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << array[6] << endl;

    cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

    int a[101] , n , i , max , min ;
    cout << "输入数组长度(n的值): ";
    cin >> n;

    cout << "输入a的值: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    max = a[0];
    min = a[0];

    for (i = 0; i < n; i++)
    {
        /* code */
        if (max < a[i])
        {
            max = a[i];
        }
        else if (min > a[i])
        {
            min = a[i];
        }
    }
    
    cout << "最大: " << max << "  " << "最小" << min << endl;
    
    cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;

    int f;
    int b[47];
    cout << "输入一个数字赋值给F : ";
    cin >> f;
    b[0] = 1;
    b[1] = 1;
    for (size_t i = 2; i < f; i++)
    {
        b[i] = b[i-1] + b[i-2];
    }
    
    cout << "斐波那契数列值: " << b[f] <<endl;
    
}   