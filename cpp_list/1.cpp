#include <iostream>
#include <string>
using namespace std;

// 原
// int main()
// {
//     cout<< "A" << endl;
//     return 0;
// }

int main(int argc, char** argv)  // argc 参数数量 char 参数列表
{
    for (int i{ 0 }; i < argc; i++)
        cout << "参数：" << argv[i] << endl;


    // 检查是否有足够参数
    if (argc < 3) {
        cout << "错误：需要提供长度和宽度参数" << endl;
        cout << "用法：程序名 长度 宽度" << endl;
        return 1;  // 返回错误码
    }

    // 开始计算
    int length = stoi(argv[1]);
    int width = stoi(argv[2]);
    int area = length * width;

    cout << "面积: " << area << endl;

    return 0;
}



// 单行注释 

/*
    这是多行注释

*/

