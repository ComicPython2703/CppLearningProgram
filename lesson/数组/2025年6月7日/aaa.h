#include <iostream>
#include <vector>
using namespace std;

void printn(vector<int> &n) // 输出数组n的内容
{
    for (int i = n.size() -1; i >= 0; i--) 
    {cout << n[i] << endl;}
}

void printv(vector<int> &n) // 输出数组v的内容
{
    for (int i = 0; i < n.size(); i++) 
    {cout << n[i] << endl;}
}