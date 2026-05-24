//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void)
{

	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl
		 << endl;

	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

	int a;
	int b = 0;

	cout << "输入零件数 : ";
	cin >> a;

	// [ERR] swith语法 编辑生成失败! 将使用 if 语句

	if (a < 100)
	{
		cout << "奖金为 10$ " << endl;
	}
	else if (a >= 100 && a < 110)
	{
		cout << "奖金为 30$" << endl;
	}
	else if (a >= 110 && a < 120)
	{
		cout << "奖金为 50$" << endl;
	}
	else if (a >= 120 && a < 130)
	{
		cout << "奖金为 70$" << endl;
	}
	else if (a >= 130)
	{
		cout << "奖金为 80$" << endl;
	}

	cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

	int n;
	int num = 1 ;
	cout << "输入整数: ";
	cin >> n;

	while (num <= n)
	{
		if (num % 3 == 0) {
			cout << num << endl;
		}
		num++;
	}

	cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;

	int n1;
	cout << "输入整数: " ;
	cin >> n;

	int d = 0;
	int num1 = 1;

	while (num1 <= n)
	{
		/* code */
		d = d + num1;
		cout << d <<endl;
		num1++;
		
	}

	cout << "--------------------------------" << endl;
	cout << "第四个内容" << endl;
	cout << "--------------------------------" << endl;
	
	int n2 = 0;
	int m2 = 0;
	int a1 = 0;
	int s1 = 0;
	cout << "输入两行数字:" << endl ;
	cout << "用法: "<<endl;
	cout << "  1行1列: 第二行的数字数量"<< endl;
	cout << "     2列: 要寻找的目标" << endl;
	cout << "  2行: 任意数字,但必须加<空格>" << endl;
	cout << "第一行: " ;
	cin  >> n1;
	cout << "第二行： ";
	cin >> m2;

	while (n2--)
	{
		/* code */
		cin >> a1;
		if (a1 == m2)
		{
			s1++;
		}
	}
	cout << s1 << endl;
	
	

	return 0;
}