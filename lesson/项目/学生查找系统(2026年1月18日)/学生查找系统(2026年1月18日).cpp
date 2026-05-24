//
// 学生查找系统(2026年1月18日).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//------------------------------------------------
//  2026年1月2日
//  Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved
//------------------------------------------------

/*
	ComicPythonWorkstation权威评价:
	这78项目,搞死我得了
*/

#include <iostream>
#include <string>

using namespace std;

int choice;

struct Student {
	int id{};          // 学号
	string name;     // 姓名
	string gender;   // 性别
	string className; // 班级
	string specialty; // 特长
};

const int MAX_STUDENTS = 10000000;  // 最大学生数量
Student students[MAX_STUDENTS]{ // 学生列表 
	{1, "张三", "男", "一班", "编程"},
	{2, "李四", "女", "二班", "绘画"}
}; // 学生列表 
// MarkDown的,这个int(13)玩意改我两节课
int studentCount = 2;           // 当前学生数量(数组模式下为预设数量)
const string FILENAME = "studs.txt"; // TODO:没搞,等会找老师

void showmenu(); // 展示菜单
void shouAllStudents();
void addstud();
void findStud(); // 查找
void editStud(); // 编辑
void delStud(); // 删除
/* ------施工中----- */
bool isIdExitst(); // 检查存在
int findStudIndex(int id); // 索引
void saveToFile(); // 保存数据
void LoadFromFile(); // 加载
string trim(const string str); // 去除字符串首尾空格
bool IsPureInteger(const string inputStr); // 输入是否为整数
/* ------施工尾----- */


int main() //主程序
{
	cout << "Copyright (c) 2010-2026 ComicPython6045. All Rights Reserved" << endl;
	cout << "--------------------------------" << endl
		<< endl;

	/* students[0].id = 1;
	students[0].name = "张三";
	students[0].gender = "男";
	students[0].className = "计算机1班";
	students[0].specialty = "编程";
	studentCount++; */

	while (true) {
		showmenu();
		cout << "请选择操作 (1-6): ";
		cin >> choice;
		if (choice == 1) {
			addstud();
		}
		else if (choice == 2) {
			shouAllStudents();
		}
		else if (choice == 3) {
			findStud();
		}

		else if (choice == 4) {
			editStud();
		}
		else if (choice == 5) {
			delStud();
		}
		else if (choice == 6) {
			cout << "退出..." << endl;
			return 0;
		}
		else
		{
			cout << "重新输入\n" << endl;
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
