//------------------------------------------------
//  2026年4月26日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int a1(int a){
    int b = 0;
    for (int i = 0; i <= a; i++)
    {   
        if (i % 2 == 0)
        {
            b+=i;
        }
    }
    return b;
}

int main(){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 编写函数-> 输入参数整数 -> 累加小于该数的偶数 -> 返回+输出" << endl;
	cout << "--------------------------------" << endl
		<< endl;

    int input;
    cout << "输入数字: ";
    cin >> input;

    cout << a1(input) << endl;
    
}