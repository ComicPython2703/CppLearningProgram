//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;



int move_1(vector<int> list_x){
    int nl = 0;
    for (int i = 0; i < list_x.size(); i++)
    {
        nl += list_x[i]; // 下标
    }
    return nl;
}

int main(){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 数组-循环累加10次->返回累加结果" << endl;
	cout << "--------------------------------" << endl
		<< endl;
    vector<int> num{1,2,3}; // value::6
    int a1 = move_1(num);
    cout << a1 << endl;

    return 0;
}