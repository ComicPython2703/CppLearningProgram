//------------------------------------------------
//  07-10-25 10:38
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
using namespace std;

int main() {
    int value;
    cout << "请输入产值: ";
    cin >> value;
    int tax = 0;
    
    // 将产值除以1000，将范围转换为离散值
    int range = value / 1000;
    
    switch(range) {
        case 0: // 0-999元
            tax = 0;
            break;
        case 1: case 2: case 3: case 4: // 1000-4999元
            tax = value * 2 / 100;
            break;
        case 5: case 6: case 7: case 8: case 9: // 5000-9999元
            tax = value * 3 / 100;
            break;
        default: // 10000元以上
            tax = value * 5 / 100;
            break;
    }
    
    cout << "tax的值为: "<< tax << endl;
    return 0;
}
