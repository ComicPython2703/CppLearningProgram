//------------------------------------------------
//  19/10/25 10:41
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

#include <iostream>
#include <string>
using namespace std;


// 学生结构体
struct Student {
    int id;          // 学号
    string name;     // 姓名
    string gender;   // 性别
    string className; // 班级
    string specialty; // 特长
};

// 全局变量
const int MAX_STUDENTS = 100;  // 最大学生数量
Student students[MAX_STUDENTS]; // 学生列表
int studentCount = 0;           // 当前学生数量

// 显示菜单
void showMenu() {
    cout << "\n========== 学生管理系统 ==========" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 显示所有学生" << endl;
    cout << "3. 退出系统" << endl;
    cout << "==============================" << endl;
}

// 主函数 - 程序入口
int main() {

    cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
    cout << "--------------------------------" << endl
         << endl;

    int choice;

    cout << "欢迎使用学生管理系统！" << endl;

    //添加学生1到数组
    students[0].id = 1001;
    students[0].name = "张三";
    students[0].gender = "男";
    students[0].className = "计算机1班";
    students[0].specialty = "编程";
    studentCount++;

    while (true) {
        showMenu();
        cout << "请选择操作 (1-3): ";
        cin >> choice;

        if (choice == 1) {
            
        }
        else if (choice == 2) {

            cout << "\n----- 所有学生信息 -----" << endl;

            // 2. 打印表头
            cout << "学号\t姓名\t性别\t班级\t特长" << endl;
            cout << "--------------------------------------------" << endl;

            // 3. 遍历显示每个学生
            for (int i = 0; i < studentCount; i++) {
                cout << students[i].id << "\t"
                    << students[i].name << "\t"
                    << students[i].gender << "\t"
                    << students[i].className << "\t"
                    << students[i].specialty << endl;
            }

            cout << "--------------------------------------------" << endl;
            cout << "共 " << studentCount << " 名学生" << endl;


        }
        else if (choice == 3) {
            cout << "感谢使用，再见！" << endl;
            break;
        }
        else {
            cout << "输入错误，请重新选择！" << endl;
        }
    }

    return 0;
}