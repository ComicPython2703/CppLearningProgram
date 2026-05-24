//------------------------------------------------
//  07-09-25 10:42
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iomanip>
#include <iostream>
using namespace std;

int main(void)		
{
	cout << "------------------------------------------" << endl ;
	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
	cout << "------------------------------------------" << endl << endl;
		 
	cout << "--------------------------------" << endl;
	cout << "first section" << endl;
	cout << "--------------------------------" << endl <<endl;
	
	float a = 90/3/4;
	float b = a * 5 *6;
	cout << "5 people in 6 days puted for"<< b << "m2 dizhuan"<< endl << endl;
	
	cout << "--------------------------------" << endl;
	cout << "second section" << endl;
	cout << "--------------------------------" << endl;
	
	short aa ;
	int bb ; 
	long long cc;
	cout <<"a storage is:"<<sizeof(aa) << endl;
	cout <<"b storage is:"<<sizeof(bb) << endl;
	cout <<"c storage is:"<<sizeof(cc) << endl;
	
	cout << "--------------------------------" << endl;
	cout << "third section" << endl;
	cout << "--------------------------------" << endl;
	
	
	//500
	float m;
	float n;
	cin >> m >> n ;
	cout <<fixed<<setprecision(2)<< ( m*m + n*n ) - (n*n/2) - (m*(m+n)/2) <<endl;

	cout << "--------------------------------" << endl;
	cout << "third section" << endl;
	cout << "--------------------------------" << endl;
	
	float r;
	cin >> r ;
	cout << "周长:" << 2*3.14*r <<endl;
	cout << "面积:" << 3.14*r*r << endl;
	
		
}