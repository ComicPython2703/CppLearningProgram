//------------------------------------------------
//  2026年4月26日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

/**
 * 累加不超过整数n的所有正偶数（包括n本身若为偶数）
 * @param n 给定的整数
 * @return 累加和，若n<=0则返回0
 */
int sumEven(int n) {
    if (n <= 0) return 0;
    int sum = 0;
    // 从2开始，步长为2，累加至n
    for (int i = 2; i <= n; i += 2) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 编写函数-> 输入参数整数 -> 累加小于该数的偶数 -> 返回+输出" << endl;
    cout << "--------------------------------" << endl << endl;

    int num;
    cout << "请输入一个整数: ";
    cin >> num;

    // 处理特殊情况：没有偶数
    if (num < 2) {
        cout << "没有符合条件的偶数,累加和为0" << endl;
        return 0;
    }

    // 从大到小构造累加式并计算和
    int sum = 0;
    int start = (num % 2 == 0) ? num : num - 1; // 最大偶数
    cout << start;
    sum += start;

    for (int i = start - 2; i >= 2; i -= 2) {
        cout << "+" << i;
        sum += i;
    }
    cout << "=" << sum << endl;

    // 也可直接调用函数验证（与上面sum应一致）
    // cout << "函数计算结果: " << sumEven(num) << endl;

    return 0;
}