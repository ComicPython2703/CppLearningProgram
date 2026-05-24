//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <float.h>
#include <climits>
using namespace std;

int main()
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    cout << "--------------------------------" << endl;
    cout << "第一个内容" << endl;
    cout << "--------------------------------" << endl;

    long long a1{0};
    cout << "a1 = " << a1 << endl;
    cout << typeid(a1).name() << endl;

    cout << "--------------------------------" << endl;
    cout << "第二个内容" << endl;
    cout << "--------------------------------" << endl;

    cout << "long: " << sizeof(long) << endl; // 915733214657123421.1279858763e+30841324543

    cout << "--------------------------------" << endl;
    cout << "第三个内容" << endl;
    cout << "--------------------------------" << endl;

    cout << "char min~max: " << CHAR_MIN << "~" << CHAR_MAX << endl;
}