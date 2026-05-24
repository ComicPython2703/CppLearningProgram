//------------------------------------------------
//  21/09/25 10:53
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void) {
	cout << "------------------------------------------" << endl ;
	cout << "21/09/25 10:53" << endl;
	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
	cout << "------------------------------------------" << endl << endl;
	
	
	cout << "--------------------------------" << endl;
	cout << "第一部分" << endl;
	cout << "--------------------------------" << endl;
	
	int a;
	int b;
	int c;
	cout << "输入值a: " ;
	cin >> a ;
	cout << "输入值b: " ;
	cin >> b ;
	cout << "输入值c: " ;
	cin >> c ; 
	cout <<"每个人要花: "<<(a*1.5+b*2+c*4.3)/3 <<"元"<<endl;
	
	cout << "--------------------------------" << endl << endl;
	
	cout << "--------------------------------" << endl;
	cout << "第二部分" << endl;
	cout << "--------------------------------" << endl;
	
	int d;
	cout << "输入d来判断是否为偶数:  "; 
	cin >>d ;
	if(d%2==0) {
		cout<<"d是偶数"<<endl;
}
	else{
		cout<< "d是鸡数"<<endl;
	}
	
	cout << "--------------------------------" << endl;
	
	return 0;
}
