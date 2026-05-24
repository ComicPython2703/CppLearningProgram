//------------------------------------------------
//  2026年1月2日
//  Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved
//------------------------------------------------

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

const int MAX_STUDENTS = 100;  // 最大学生数量
Student students[MAX_STUDENTS]; // 学生列表
int studentCount = 0;           // 当前学生数量
const string FILENAME = "studs.txt"; // TODO:没搞,等会找老师

void showmenu();
void shouAllStudents();
void addstud();
void findStud();
void editStud();
void delStud();

int main()
{
	cout << "Copyright (c) 2010-2025 ComicPython6045. All Rights Reserved" << endl;
	cout << "--------------------------------" << endl
		<< endl;

	students[0].id = 1001;
	students[0].name = "张三";
	students[0].gender = "男";
	students[0].className = "计算机1班";
	students[0].specialty = "编程";
	studentCount++;

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

static void showmenu() {  // 显示主菜单
	cout << "========学生管理系统===========" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 查看学生" << endl;
	cout << "3. 查找学生" << endl;
	cout << "4. 修改学生data数据" << endl;
	cout << "5. 删除学生" << endl;
	cout << "6. 退出" << endl;
	cout << "===========================" << endl;
}
static void addstud() { //添加学生
	cout << "\n========添加学生===========" << endl;

	if (studentCount >= MAX_STUDENTS) {
		cout << "\n[ERROR] 已达到最大学生数 (" << MAX_STUDENTS << ")!" << endl;
		return;
	}

	cout << "输入学生学号{id}: ";
	cin >> students[studentCount].id;
	cout << "输入学生姓名: ";
	cin >> students[studentCount].name;
	cout << "输入学生性别: ";
	cin >> students[studentCount].gender;
	cout << "输入学生班级: ";
	cin >> students[studentCount].className;
	cout << "输入学生特长: ";
	cin >> students[studentCount].specialty;
	studentCount++;
}
static void shouAllStudents() {//显示学生
	if (studentCount == 0)
	{
		cout << "[WARN]未找到任何学生,请添加一个学生!!!!";
	}

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
static void findStud() {
	cout << "\n [ERR]无法使用该功能,没写" << endl;
}
static void editStud() {
	cout << "\n [ERR]无法使用该功能,没写" << endl;
}
static void delStud() {
	cout << "\n [ERR]无法使用该功能,没写" << endl;
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
