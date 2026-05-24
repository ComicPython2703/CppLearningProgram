#include <iostream>
#include <string>
#include "学生查找系统(2026年1月18日).cpp"
using namespace std;

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