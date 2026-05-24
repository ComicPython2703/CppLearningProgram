//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
using namespace std;

// 函数定义：计算直角三角形面积，返回整数结果（底×高÷2，整数除法会截断小数部分）
int triangleArea(int base, int height) {
    return base * height / 2;
}

int main(void){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 计算三角形面积" << endl;
	cout << "--------------------------------" << endl
		<< endl;

    int base, height;
    
    cout << "请输入直角三角形的底边长（整数）: ";
    cin >> base;
    cout << "请输入直角三角形的高（整数）: ";
    cin >> height;
    
    int area = triangleArea(base, height);
    
    cout << "直角三角形的面积为: " << area << endl;
    
    return 0;
}
