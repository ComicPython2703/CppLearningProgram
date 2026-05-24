//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    string f1{"ÎÒÏë"};
    string f2{"ÏÂ¿Î"};
    string f3;

    f3 = f1 + f2;

    cout << "f3: " << f3 << endl;
}