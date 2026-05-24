//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 循环10次" << endl;
	cout << "--------------------------------" << endl
		<< endl;

    int a = 0;   

    cout << "--------{使用for循环}-------------" << endl;

    for (int i = 0; i <= 10; i++)
    {
        cout << "循环了" << i <<"次" << endl;
    }

    cout << "--------{使用while循环}-------------" << endl;
    
    while (a <= 10)
    {   
        cout << "循环了" << a <<"次" << endl;
        a++;
    }
    
    
}