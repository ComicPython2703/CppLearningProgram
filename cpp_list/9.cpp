#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> split(const string &str, char delimiter);

int main() {
    // 1. 创建和初始化
    string s1;                    // 空字符串
    string s2 = "Hello";         // 字面量初始化
    string s3("World");          // 构造函数
    string s4(5, 'A');           // "AAAAA" - 5个A
    string s5 = s2;              // 拷贝
    
    // 2. 基本操作
    // 长度
    cout << s2.length() << endl;     // 5
    cout << s2.size() << endl;       // 5（同length）
    
    // 是否空
    if (s1.empty()) cout << "空" << endl;
    
    // 访问字符
    cout << s2[0] << endl;           // 'H'（不检查越界）
    cout << s2.at(0) << endl;        // 'H'（检查越界，越界抛异常）
    
    // 3. 修改内容
    // 末尾追加
    s1 = "Hello";
    s1 += " World";                  // "Hello World"
    s1.append("!!!");                // "Hello World!!!"
    
    // 插入
    s1.insert(6, "Beautiful ");      // "Hello Beautiful World!!!"
    // 删除
    s1.erase(6, 10);                 // "Hello World!!!"
    // 替换 起始位置 替换长度 需替换字符
    s1.replace(6, 5, "C++");         // "Hello C++!!!"
    
    // 4. 查找
    string text = "I love C++ programming";
    size_t pos = text.find("C++");   // 找到位置7
    if (pos != string::npos) {
        cout << "找到C++ at: " << pos << endl;
    }
    
    // 5. 子串
    string sub = text.substr(7, 3);  // "C++"
    
    // 6. 比较
    string a = "apple", b = "banana";
    if (a == b) cout << "相等" << endl;
    if (a < b)  cout << "a<b" << endl;  // 字典序比较

    // 比较说明 测试
    string s1 = "apple";
    string s2 = "application";

    if (s1 < s2) {
        cout << "s1 < s2" << endl;
    }

    // 打印每个字符的ASCII码
    cout << "字符串 \"" << s1 << "\" 的ASCII码: ";
    for (char ch : s1) {
        cout << int(ch) << " ";  // 'a'=97, '空格'=32
    }
    cout << endl;

    // 打印每个字符的ASCII码
    cout << "字符串 \"" << s2 << "\" 的ASCII码: ";
    for (char ch : s2) {
        cout << int(ch) << " ";  // 'a'=97, '空格'=32
    }
    cout << endl;
    // 比较过程：
    // 1. s1[0]='a' == s2[0]='a' → 继续
    // 2. s1[1]='p' == s2[1]='p' → 继续
    // 3. s1[2]='p' == s2[2]='p' → 继续
    // 4. s1[3]='l' == s2[3]='l' → 继续
    // 5. s1[4]='e' == s2[4]='i' e 101 i 105  s2 > s1

    //s1 < s2
    //字符串 "apple" 的ASCII码: 97 112 112 108 101
    //字符串 "application" 的ASCII码 : 97 112 112 108 105 99 97 116 105 111 110

    
    
    // 7. 数字转换 C++ string 专用的
    string numStr = "123";
    int num = stoi(numStr);         // 字符串转整数
    double d = stod("3.14");        // 字符串转浮点数
    
    string back = to_string(456);   // 数字转字符串
    
    // 便捷打印
    for (char c : s2) {            // 范围for
        cout << c << " ";
    }
    // 正常打印
    for (int i = 0; i < s2.length(); i++) {  // 索引
        cout << s2[i] << " ";
    }
    

    // 测试1：基本分割
    string csv = "John,Doe,25,USA";
    auto data = split(csv, ',');
    cout << "CSV分割结果:" << endl;
    for (const auto& item : data) {
        cout << "- " << item << endl;
    }

    return 0;
}



vector<string> split(const string &str, char delimiter) {
    vector<string> result;      // 存储分割结果
    stringstream ss(str);       // 将字符串转为流
    string item;                // 临时存储每个分割部分
    
    // getline 从流中读取直到遇到分隔符
    while (getline(ss, item, delimiter)) {
        result.push_back(item);  // 添加到结果
    }
    
    return result;
    }  