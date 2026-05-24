//------------------------------------------------
//  21/09/25 10:53
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void) {
	int a;
	cout << "输入成绩:  ";
	cin >> a ;
	if(a>100){
		cout << "检测到作弊,程序已强制关闭";
		return 1;
	}
	if(a==100) {
		cout << "AP";
	}
	else if(a>=95) {
		cout << "V+";
	}
	else if(a>=90) {
		cout << "V";
	}
	else if(a>=85) {
		cout << "S";
	}
	else if(a>=80) {
		cout << "A";
	}
	else if(a>=70) {
		cout << "B";
	}
	else if(a>=60) {
		cout << "C";
	}
	else{
		cout << "F";
	}
	
	return 0;
}
