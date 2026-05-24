//------------------------------------------------
//  19/10/25 10:41
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
	
	cout << "输入三个整数: ";
 	int a , b , c;
 	cin >> a >> b >> c;
	
	cout << "最大的整数是: "<< (a>b? (a>c? a:c):(b>c? b:c) ) << endl;
	
	
	cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

	int score;
	cout << "输入成绩: ";
	cin >> score;
	
	switch(score/10){
		case 10:
		case 9:
			cout << "a" <<endl;
			break;
		case 8:
			cout << "b" <<endl;
			break;
		case 7:
		case 6:
			cout << "c" <<endl;
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
			cout << "F" <<endl;
			break;
		default:
			cerr << "开了" <<endl;
			break;
	}

	cout << "--------------------------------" << endl;
	cout << "第三个内容" << endl;
	cout << "--------------------------------" << endl;
	int money;
	cout << "初始经费:  0 , 100 , 200 , 300"<< endl;
	cout << "输入经费: ";
	cin >> money;
	int m1 = money / 4;
	switch(money%4){
		case 0:
			cout << "4元: " << m1 << "5元:0"<< "6元:0" << endl;
			break;
		case 1:
			cout << "4元:"  << (m1-1) << "5元:1"<< "6元:0" << endl;
			break;
		case 2:
			cout << "4元: " << (m1-1) << "5元:0"<< "6元:1" << endl;
			break;
		case 3:
			cout << "4元: " << (m1-2) << "5元:1"<< "6元:1" << endl;
			break;
	}

	
}
