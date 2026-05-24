#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 任务：读取某个txt文件,发现文件不存在,则创建此文件




// 文件读写

int main(){

    // 读取 需要文件本就存在
	// 读取txt文件  创建一个输入文件流对象并打开指定文件
	ifstream file1("students1.txt");
    
	string line;
    
	if (!file1.is_open()) {
		cout << "未找到数据文件，需要创建新文件" << endl;
		return 0;
	}
	while (getline(file1, line)) {
		
		// 跳过空行
		if (line.empty()) {
			continue;
		}
     std::cout << line << std::endl;
	}
     //关闭文件
    file1.close();


    // 保存文件 若文件不存在则会自行创建文件
    // 用于保存 创建一个输出文件流对象并打开指定文件
    ofstream file4("students1.txt");
    if (!file4.is_open()) {
        cout << "无法创建数据文件！" << endl;
        return 0;
    }
    file4 << 1234 << "|"  << endl;
    // 关闭文件
    file4.close();
    
    
    /*
    ifstream file2("students.txt");
    
    std::string line; //存储读取的每一行文本


     //file2.setstate(std::ios::failbit);  // 人为设置失败标志

    // 无限循环，通过内部的break语句来控制退出
    while (true) {

        // 按行读取 每次读取1行
        getline(file2, line);
        std::cout << line << std::endl;

        // 检查是否到达文件末尾
        if (file2.eof()) {
            std::cout << "结尾" << std::endl;
            break;  // 跳出循环，结束文件读取
        }
            

        // 文件读取错误
        if (file2.fail()) {
            std::cout << "读取错误" << std::endl;
            break;  
        }

        
    }
    // 关闭文件
    file2.close();
    */
    
    return 0;
}



