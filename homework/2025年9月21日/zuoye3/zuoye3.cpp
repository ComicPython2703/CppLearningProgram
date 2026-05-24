//------------------------------------------------
//  21/09/25 10:53
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void) {
	int a;
	cout << "输入值a: ";
	cin >> a;
	if(a==1) {
		cout << "星期一" << endl;
	}
	else if (a==2){
		cout  << "星期二" << endl; 
	}
	else if (a==3){
		cout  << "星期三" << endl; 
	}
	else if (a==4){
		cout  << "星期四" << endl; 
	}
	else if (a==5){
		cout  << "星期五" << endl; 
	}
	else if (a==6){
		cout  << "星期六" << endl; 
	}
	else if (a==7){
		cout  << "星期天" << endl; 
	}
	else {
		cerr << "输出失败,请重试"<< endl ; 
		return 1;
	} 
	return 0;
}
