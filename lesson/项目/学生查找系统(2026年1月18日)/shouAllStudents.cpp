#include <iostream>
#include <string>
#include "学生查找系统(2026年1月18日).cpp"
using namespace std;

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