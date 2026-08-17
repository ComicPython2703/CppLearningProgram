//------------------------------------------------
//  2026年8月16日 10:32
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;
    ifstream file1("main.txt"); // 变量(路径)
    string line;
    if (!file1.is_open())
    {
        cerr << "未找到数据文件，需要创建新文件" << endl;
        return 1;
    }
    else
    {
        cout << "main.txt 读取成功" << endl;
        cout << "main.txt \n type:text file \n";
    }

    while (getline(file1, line))
    {
        // 跳过空行
        if (line.empty())
        {
            continue;
        }
        cout << line << endl;
    }
    file1.close();

    cout << "--------------------------------" << endl;

    ofstream file4("main2.txt");
    if (!file4.is_open())
    {
        cerr << "无法创建文件!" << endl;
        return 1;
    }
    else
    {
        cout << "创建成功!" << endl;
    }

    file4.close();
}