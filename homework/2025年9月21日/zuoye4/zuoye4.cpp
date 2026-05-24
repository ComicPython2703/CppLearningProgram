//------------------------------------------------
//  21/09/25 10:53
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void) {
	int a;
	int b;
	int c; 
	cout << "输入值a: ";
	cin >> a;
	cout << "输入值b: ";
	cin >> b;
	cout << "输入值c: ";
	cin >> c;
	if(a>=b) {
		if (a>=c){
			cout <<a;
		}
	 	else {
			cout << c;
		}
    }
	else{
		 if (b>=c){
			cout <<b;
		}
		else {
			cout << c;
		}
 	}
	
}
