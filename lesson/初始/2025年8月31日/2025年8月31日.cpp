//------------------------------------------------
//  31/08/25 11:14
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int c1 = 1;
int c2 = 2;

int main(void)
{
	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl
		 << endl;

	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	cout << c1 / c2 << endl;

	cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

	cout << 1 / 10 << endl;
	cout << 12 / 10 << endl;
	cout << 123 / 10 << endl;
	cout << 123 / 100 << endl;

	cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;

	cout << 1 % 10 << endl;
	cout << 12 % 10 << endl;
	cout << 123 % 10 << endl;
	cout << 123 % 100 << endl;

	cout << "--------------------------------" << endl;
	cout << "第四个内容" << endl;
	cout << "--------------------------------" << endl;

	cout << "请输入一个三位数: ";
	int a;
	cin >> a;
	if (a > 999)
	{
		cerr << "[ERR]超出上限" << endl;
	}
	else if (a < 100)
	{
		cerr << "[ERR]低于下限" << endl;
	}
	
	else
	{
		long long b = a / 10;
		int c = a / 100 + b % 10 + a % 10;
		cout << "百位数: " << a / 100 << endl;
		cout << "十位数: " << b % 10 << endl;
		cout << "个位数: " << a % 10 << endl;
		cout << "总和: " << c << endl;
	}
	cout << "--------------------------------" << endl;
	cout << "第五个内容" << endl;
	cout << "--------------------------------" << endl;
	int d = 3, e = 5, f = 0; // 初始化f为0
	cout << d << "_" << e << "_" << f << "_" << endl;
	f = d;
	d = e;
	e = f;
	cout << d << "_" << e << "_" << f << "_" << endl;

	cout << "--------------------------------" << endl;
	cout << "第六个内容" << endl;
	cout << "--------------------------------" << endl;

	cout << "第二种交换方法" << endl;
	int g = 3, h = 5;
	cout << g << "_" << h << endl;
	g = g + h;
	h = g - h;
	g = g - h;
	cout << g << "_" << h << endl;

	cout << "--------------------------------" << endl;
	cout << "第七个内容" << endl;
	cout << "--------------------------------" << endl;

	int i=6,j=9;
	cout << i << "_" << j << endl;
	swap(i,j);
	cout << i << "_" << j << endl;

	return 0;
}
