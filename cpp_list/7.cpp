#include <iostream>
#include <vector>
using namespace std;
 
// 函数声明
int max(int num1, int num2);
vector<int> add_v(vector<int> n1, vector<int> n2);

int main ()
{
    // 局部变量声明
    int a = 100;
    int b = 200;
    int ret;

    // 调用函数来获取最大值
    ret = max(a, b);
    cout << "Max: " << ret << endl;


    vector<int> list_1 {1, 2, 3};
    vector<int> list_2 {1, 1, 1};
    vector<int> list_3 = add_v(list_1, list_2);

    for (int i=0; i < list_3.size(); i++){
        cout << "list_3: " << list_3[i] << endl;
    }
    

   return 0;
}

// 说明
// 返回的数据类型 函数名称(数据类型 参数1，数据类型 参数2)
// 函数返回两个数中较大的那个数
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}

// void 是没有返回值的类型
// 返回值类型可以使用任何类型 以 vector 示例
// 将两个数组内的数相加
vector<int> add_v(vector<int> n1, vector<int> n2){
    
    vector <int> n3{0, 0, 0};
    for (int i=0; i < n1.size(); i++){
        n3[i] = n1[i] + n2[i];
    }

    return n3;
}