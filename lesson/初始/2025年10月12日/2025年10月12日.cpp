//------------------------------------------------
//  12-10-25 10:40
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void) {

	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl
	     << endl;

	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

	char c;
	cout << "输入一个字符: ";
	cin >> c ;

	if (c >= 'A' && c <= 'Z') {
		cout << "Yes" << endl;
	} else if(c >= 'a' && c <= 'z') {
		cout << "No" << endl;
	} else {
		cerr<<"输入的内容不是一个字符"<<endl;
	}

	cout << "--------------------------------" << endl;
	cout << "第二部分" << endl;
	cout << "--------------------------------" << endl;

	int a;
	cout << "输入两位数: " ;
	cin >> a;
	if(a<100) {
		cout << "Yes"<< endl;
	} else {
		cerr << "No" << endl;
	}

	cout << "--------------------------------" << endl;
	cout << "第三部分" << endl;
	cout << "--------------------------------" << endl;

	int b;
	cout << "输入一个字符: ";
	cin >> b;

	if (b>10) {
		cout << "yes" <<endl;
	} else {
		cout<< "no" <<endl;
	}


	cout << "--------------------------------" << endl;
	cout << "第四部分" << endl;
	cout << "--------------------------------" << endl;

	int d , e , f;
	cout << "输入三个整数: " << endl;
	cin >> d >> e >> f;
	int max = d; // 在此处定义最大最小

	
	if (d>e)
	{
		cout << (d>f? d:f ) ;
	}
	else{
		cout << (e>f?e:f) ;
	}
	
	cout << "--------------------------------" << endl;
	cout << "第五部分" << endl;
	cout << "--------------------------------" << endl;

	char name;
	cout << "输入型号";
	cin >> name;
	switch (name)
	{
	case '1':
		cout << "240$";
		break;
	case '2':
		cout << "180$";
		break;
	case '3':
		cout << "120$";
		break;
	
	default:
		break;
	}


	return 0;
}
