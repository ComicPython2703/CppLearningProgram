//------------------------------------------------
//  07-10-25 10:38
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void)
{
	cout << "------------------------------------------" << endl ;
	cout << "21/09/25 10:53" << endl;
	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
	cout << "------------------------------------------" << endl << endl;
	
	
	cout << "--------------------------------" << endl;
	cout << "第一部分" << endl;
	cout << "--------------------------------" << endl;
	
	
	char a , b ,c;  
	
	cout << "输入三个字符";
	cin >> a >> b >> c;
	char max = a , min = a; // 在此处定义最大最小 
	
	if(b > max) {
		max = b;
	}
	if(c > max) {
		max = c;
	}
	if(b < max) {
		max = b;
	}
	if(c < max) {
		max = c;
	}
	cout << max << " " << min << endl ;
	
	cout << "--------------------------------" << endl;
	cout << "第二部分" << endl;
	cout << "--------------------------------" << endl;
	
	int user = 123 ;
	int pass = 456;
	
	int usser;
	int passw;
	
	cout << "输入账号: ";
	cin >> usser;
	if(usser == user) {
		cout << "输入密码: ";
		cin >> passw; 
		if(passw == pass) {
			cout << "成功" << endl; 
		}
		else{
			cout << "密码错误" << endl;
		}
	}
	else{
		cout << "账号错误" << endl ; 
	}

	cout << "--------------------------------" << endl;
	cout << "第三部分" << endl;
	cout << "--------------------------------" << endl;
	
	int b1 , b2 , b3;
	
	cout << "输入三角形的三个边: ";
	cin >> b1 >> b2 >> b3;
	
	if(b1+b2>b3 && b1+b3>b2 && b2+b3>b1) {
		cout << "yes"<< endl;
	}
	else{
		cout<<"no" << endl;
	}

	return 0;
}

