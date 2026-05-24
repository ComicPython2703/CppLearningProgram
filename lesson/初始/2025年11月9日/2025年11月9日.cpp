//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main(void) {
    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl <<endl;

	cout << "--------------------------------" << endl;
	cout << "第一个内容" << endl;
	cout << "--------------------------------" << endl;

    int a , b , c;
    cout << "输入三个数字: ";
    cin >> a >> b >> c;

    cout << "最小的整数是: "<< (a<b? (a<c? a:c):(b<c? b:c) ) << endl;

    cout << "--------------------------------" << endl;
	cout << "第二个内容" << endl;
	cout << "--------------------------------" << endl;

    int n;
    cout << "输入b的值来判断是否为质数: ";
    cin >> n;

    bool flag;
	flag=true;
	for(int i=2;i<n;i++){
		if(n%i==0 && n != 1){
			flag=false;
			break;
		}
        else
        {
            flag = true;
            break;
        }
        
	}
	if(flag == false){
		cout<< n << "是素数" << endl; 
	}
    else{
		cout<< n << "不是素数" << endl;
	}

}