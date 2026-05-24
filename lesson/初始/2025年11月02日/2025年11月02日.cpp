//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void)
{

	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
	cout << "--------------------------------" << endl;

	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

	int i = 100;
	while (i > 0)
	{
		/* code */
		cout << i << " ";
		i = i - 1 ;
	}
	cout << endl;
	
	cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

	for (size_t i = 100; i > 0; i--) // int 
	{
		/* code */
		cout << i << " " ;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;

	int m ,n ;
	cout << "输入两个整数,格式: 10 空格 10" <<endl;
	cout << "输入: ";
	cin >> m >> n;

	int sum1 = 0 ,sum2 = 0;
	int debug = 0;
	for (i = m; i <= n; i++)
	{
		debug++;
		cout << "[DEBUG]循环次数: " << debug << endl;
		if (i % 2 == 0 )
		{
				sum1 += i;
		}
		else {
			sum2 += i;
		}
	}
	cout <<"偶数: "<<sum1 << "  基数: " << sum2 << endl;
	
	cout << "--------------------------------" << endl;
	cout << "第四个内容" << endl;
	cout << "--------------------------------" << endl;

	int m1 , n1 = 0;
	cout << "输入 m 和 n 数据:";
	cin >> m1 >> n1 ;

	for (i = m1; i < n1; i++)
	{
		/* code */
		if (i % 3 == 0){
			cout << i << endl;
			break;
		}
	}

	cout << "--------------------------------" << endl;
	cout << "第五个内容" << endl;
	cout << "--------------------------------" << endl;


	int a , b;
	cout << "输入两个数字: " ;
	cin  >> a >> b;


	for (i = a; i < b; i++)
	{
		/* code */
		if (i % 3 == 0)
		{
			/* code */
			continue;
		}
	cout << m << "到" << n << "之间能被 3 整除的数字: " << i << endl ;
	}
	
	cout << "--------------------------------" << endl;
	return 0;
    
}