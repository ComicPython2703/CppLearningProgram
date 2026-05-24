//------------------------------------------------
// 31/08/25 11:14
// Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------ 
#include <iostream>
using namespace std;  

int main(void)
{
	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;
	
	cout << "请输入正方形的边长:" ;
	int a;
	cin >> a;
	cout << "面积:" << a * a << endl;
	cout << "周长:" << a * 4 << endl;
	
	cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;
	cout << "请输入三个整数:";
	int b;
	int c;
	int d;
	
	cin >> b >> c >> d ;
	cout <<"平方和:"<<b*b + c*c +d*d<< endl;
	
	cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;
	
	cout << "请输入三个整数:";
	long long e;
	long long f;
	long long g;
	cin >> e >> f >> g ;
	long long h = e*f*g;
	long long i = e*e*e + f*f*f + g*g*g ;
	cout << "乘积:" << h<< endl;
	cout << "三次方:"  << i << endl;
	
	cout << "--------------------------------" << endl;
	cout << "第四个内容" << endl;
	cout << "--------------------------------" << endl;
	
	long long j=8000;
	cout <<"小时:"<< j / 3600 << endl;
	cout <<"分钟:"<< j / 600 << endl;
	cout <<"秒:"  << j % 60 ;
	
	return 0;
}

