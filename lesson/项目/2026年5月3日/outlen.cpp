#include <iostream>
#include <vector>
using namespace std;

void outlen(vector <int>n) {
    cout <<"输出当前数组: ";
    for (int i = 0; i < n.size(); i++)
    {
        cout << n[i] << " " ;
    }
    cout << endl;
    
}