//------------------------------------------------
//  2025-11-23 10:51
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;


    cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

    int n = 10; // 初始化 n 的值为 10 
    vector<int> nums;
    for (int i = 0; i < nums.size(); i++)

    {
        cout << "初始数组内容: " << nums[i] << " ";
    }

    nums.push_back(10);

    cout << "数组内容: " ;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " "  ;
    }
    cout << endl ;

    cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

    cout << "长度: " << nums.size() << endl;

    cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;

    cout << "数组的最后一个内容: " << nums.back() << endl;
    
    cout << "--------------------------------" << endl;
	cout << "第四个内容" << endl;
	cout << "--------------------------------" << endl;

    cout << "删除最后一个元素" << endl;
    nums.pop_back();    
    
}