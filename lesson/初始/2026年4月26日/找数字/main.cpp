//------------------------------------------------
//  2026年4月26日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

void cha(vector<int> list_x){
    for (int i = 0; i < list_x.size(); i++)
    {
        if (list_x[i] == 250)
        {
            cout << "找到了" << endl;
        }
        else
        {
            cerr << "没找到" << endl;
        }
    }
}

int main(void){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 数组内找 250" << endl;
	cout << "--------------------------------" << endl
		<< endl;

    vector<int> lists{1,2,3,4,4,5,6,6,7,3123,435231,34,32151,3243543,531,250,213,331542,41};

    cha(lists);
}