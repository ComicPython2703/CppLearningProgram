//------------------------------------------------
//  2026年7月5日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    auto now = system_clock::now(); // 当前时间戳
    // time_point<system_clock> now = system_clock::now();

    time_t now_time = system_clock::to_time_t(now);

    tm timeinfo;

    localtime_s(&timeinfo, &now_time);

    cout << (timeinfo.tm_year + 1900) << "-"
         << (timeinfo.tm_mon + 1) << "-"
         << timeinfo.tm_mday << " "
         << timeinfo.tm_hour << ":"
         << timeinfo.tm_min << ":"
         << timeinfo.tm_sec << endl;
}