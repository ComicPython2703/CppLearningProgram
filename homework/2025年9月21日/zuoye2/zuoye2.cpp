//------------------------------------------------
//  21/09/25 10:53
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

int main(void) {
	int a;
	cout << "距离: ";
	cin >> a;
	// --------------
	float b = a/1.2; ;//步行
	float c = a/3.0+27+23 ;//骑行
	// --------------------
	if(b>c) {
		cout << "骑行最佳" <<endl;
	}
 	else if(b<c){
 		cout << "步行最佳" <<endl;
	 }
	else{
		cout << "二者都是"  <<endl;
	} 
	
	return 0;	
}

