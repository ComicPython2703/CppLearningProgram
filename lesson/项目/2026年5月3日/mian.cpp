//------------------------------------------------
//  2026年5月3日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 追加元素" << endl;
	cout << "--------------------------------" << endl
		<< endl;    

    vector <int>nums1 = {1,2,33,9};
    vector <int>nums2 = {0,99,3,77};
    
    // nums2.push_back(10);
    for (int i = 0; i < nums2.size(); i++)
    {
        nums2.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i];
    }
}
