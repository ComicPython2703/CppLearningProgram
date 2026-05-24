#include <vector>
#include <iostream>
using namespace std;

vector <int> AppendToArray(vector <int>a , vector <int>b){  // 数组追加 a 为追加者 , b 为被追加的数组
    for (int i = 0; i < a.size(); i++)
    {   
        cout << "数组追加." << endl;
        b.push_back(a[i]);
    }
    return b;
}