#include <iostream>
#include <vector>
using namespace std;

int main()
{
/*     int a = 5, b = 10;
    // ---使用定义值输出---
    int max = (a > b) ? a : b;
    cout << max << endl;
    // ---使用cout输出---
    cout << (a > b) ? a : b; // 错误
    cout << ((a > b) ? a : b); // 正确 */
/* int c = 0;
    for (int i = 1; i < 200; i++) {
        c++;
        cout << c << endl;
    }
    vector<int> nums = {1, 2, 3, 4, 5};   // 初始化包含5个元素的 vector
    for (int i = 0; i < nums.size(); i++) {
        cout << "数组内容: " << nums[i] << " ";
    } */
    int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 数组
    int len_1 = sizeof(n) / sizeof(n[0]);     // 数组个数
    cout << len_1 << endl;
}