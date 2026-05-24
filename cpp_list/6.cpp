#include <iostream>
using namespace std;

 
int main ()
{   
    // 原生数组 初始化后，长度无法再变化,若需要长的数组,只能新建新的

    // 初始数组 长度为10 初始化元素
    int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 索引修改 
    n[0] = 11;


    // 经典 sizeof 除法
    int len_1 = sizeof(n) / sizeof(n[0]);

    // 删除 索引4
    for (int i = 0; i <= len_1; i++) {
        n[i] = n[i + 1];
    }

    // 删除后 长度有变化吗
    int len_2 = sizeof(n) / sizeof(n[0]);

    // 输出数组中每个元素的值                     
    for (int j=0; j<=len_2; j++)
    {
        // 判断 查询
        if (n[j] == 9){
            cout << "找到了 " << n[j] << endl;
        }
        cout << n[j] << endl;
    }


    // 定义多维数组
    int a4[3][4]
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "============================" << endl;

    cout << a4[0][0] << "    "<< a4[0][1] << "    "<< a4[0][2] << "    " << a4[0][3] << "    "<< endl;

    cout << "============================" << endl;


    return 0;
}