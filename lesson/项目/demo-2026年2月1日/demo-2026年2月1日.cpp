//------------------------------------------------
//  2026年2月1日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) // argc 参数数量, argv 参数列表
{
    // cout << "text" << endl;
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
        << endl;

    for (int i = 0; i < argc; i++)
    {
        cout << "参数: " << argv[i] << endl;
        cout << "参数长度: " << strlen(argv[i]) << endl;
    }

    /* 通过参数输入长宽计算矩形面积 */

    cout << endl <<"-------------------------------" << endl;
    cout << "通过参数输入长宽计算矩形面积" << endl;
    cout << "-------------------------------" << endl;
    if (argc >= 3) {
        int length = stoi(argv[1]);
        int width = stoi(argv[2]);

        cout << "矩形面积: " << length * width << endl;
    }
    else {
        cout <<"请提供长和宽两个参数来计算矩形面积" << endl << endl;
        cout << "在当前项目,你可使用 Visual Studio 跳到当前项目的目录,启动 Windows Terminal 并执行以下指令: " << endl;
        cout << "cd x64" << endl;
        cout << "cd debug" << endl;
        cout << "demo-2026年2月1日.exe <参数一> <参数二>" << endl;
    }

    cout << "-------------------------------" << endl << endl;

    return 0;  // 添加返回语句
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
