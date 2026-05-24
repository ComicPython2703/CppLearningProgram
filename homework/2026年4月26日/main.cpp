//------------------------------------------------
//  2026年3月29日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// 计算BMI值
double getBMI(double w, double h) {
    return w / (h * h);
}

// 根据BMI返回身体等级
string getLevel(double bmi) {
    if (bmi < 18.5)
        return "偏瘦";
    else if (bmi < 24.0)   // 18.5 ~ 23.9
        return "正常";
    else if (bmi < 28.0)   // 24.0 ~ 27.9
        return "偏重";
    else                   // ≥28
        return "肥胖";
}

int main() {

    cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
    cout << "作业内容: 计算BMI" << endl;
	cout << "--------------------------------" << endl
		<< endl;

    double weight, height;
    cout << "请输入体重(kg)和身高(m): ";
    cin >> weight >> height;

    double bmi = getBMI(weight, height);
    string level = getLevel(bmi);

    cout << "BMI: " << bmi << endl;
    cout << "身体等级: " << level << endl;

    return 0;
}
