//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void wqe1(string v1, string v2)
{
    string v3;
    v3 = v1 + v2;
    cout << "v3: " << v3 << endl;
}

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    string v1{"ÎÒÏë"};
    string v2{"ÏÂ¿Î"};
    wqe1(v1, v2);
}
