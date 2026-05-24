#include <iostream>
using namespace std;

int main(){
    int arr_0[] = {10,20,30,40,50}; // 定义数组
    int len_1 = sizeof(arr_0) / sizeof(arr_0[0]); // 数组大小
    int* ptr_01 = arr_0;

    for (int i = 0; i < len_1; i++)
    {
        cout << "递增指针后指向的元素: " << *ptr_01 << endl;
        ptr_01++;
    }
    
}