//------------------------------------------------
//  2026年7月5日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include "a.h"

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    large obj = {};

    printf("传值");
    auto start = high_resolution_clock::now(); // 起始时间
    for (int i = 0; i < 10000; i++)
    {
        byValue(obj);
    }
    auto end = high_resolution_clock::now(); // 终止时间
    timer(end, start);

    printf("指针");
    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
    {
        byPointer(&obj);
    }
    end = high_resolution_clock::now();
    timer(end, start);

    printf("引用");
    start = high_resolution_clock::now();
    for (int i = 0; i < 10000; i++)
    {
        byReference(obj);
    }
    end = high_resolution_clock::now();
    timer(end, start);
}
