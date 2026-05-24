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
static void findStud() { // 查找学生
		/* cout << "\n [ERR]无法使用该功能,没写" << endl; */
		if (studentCount == 0)
		{
			cerr << "[ERR]没有任何学生!!!!" << endl;
			return;
		}

		int a;          // 学号 
		string b;       // 姓名
		int findchoice; // 选择查找

		cout << "=============查找学生===============" << endl;
		cout << "学号: 1 , 姓名: 2" << endl;
		cout << "选择一项: ";
		cin >> findchoice;
		if (findchoice == 1)
		{
			cout << "输入学号: ";
			cin >> a;
			for (int i = 0; i < studentCount; i++) {
				if (a == students[i].id)
				{
					cout << "找到!" << endl << endl;
					cout << "\n----- 当前学生信息 -----" << endl;
					cout << "学号\t姓名\t性别\t班级\t特长" << endl;
					cout << "--------------------------------------------" << endl;
					cout << students[a-1].id << "\t"
					<< students[a-1].name << "\t"
					<< students[a-1].gender << "\t"
					<< students[a-1].className << "\t"
					<< students[a-1].specialty << endl;
					cout << "--------------------------------------------" << endl << endl;
					break;
				}
				cerr << "没有该学生" << endl;
			}
		}
		else if (findchoice == 2)
		{
			cout << "输入姓名: ";
			cin >> b;
			// 不要再吞我代码了!!!!╰（‵□′）╯ヽ（≧□≦）ノ
			for (int i = 0; i < studentCount; i++) {
				if (b == students[i].name)
				{
					cout << "找到!" << endl << endl;
					cout << "\n----- 当前学生信息 -----" << endl;
					cout << "学号\t姓名\t性别\t班级\t特长" << endl;
					cout << "--------------------------------------------" << endl;
					cout << students[i].id << "\t"
					<< students[i].name << "\t"
					<< students[i].gender << "\t"
					<< students[i].className << "\t"
					<< students[i].specialty << endl;
					cout << "--------------------------------------------" << endl << endl;
				}
				else {
					cerr << "没有该学生" << endl;
				}
			}
		}
	
}
static void editStud() { // 编辑学生
		/* 11:00 am 整了,才开始写这个B
		cout << "\n [ERR]无法使用该功能,没写" << endl; */
		cout << "=========修改学生信息==========" << endl;
		
		if (studentCount == 0) {
			cerr << "[ERR] 没有学生信息可修改！" << endl;
			return;
		}
		
		int editId; // 修改学生学号
		cout << "输入要修改的学生学号: ";
		cin >> editId;
		
		for (int i = 0; i < studentCount; i++) {
			if (students[i].id == editId) {
				cout << "找到学生: " << students[i].name << endl;
				cout << "输入新姓名 (当前: " << students[i].name << "): ";
				cin >> students[i].name;
				cout << "输入新性别 (当前: " << students[i].gender << "): ";
				cin >> students[i].gender;
				cout << "输入新班级 (当前: " << students[i].className << "): ";
				cin >> students[i].className;
				cout << "输入新特长 (当前: " << students[i].specialty << "): ";
				cin >> students[i].specialty;
				cout << "学生信息修改成功！" << endl;
				return;
			}
		}
		
		cerr << "[ERROR] 没有找到学号为 " << editId << " 的学生！" << endl;
	
}
static void delStud() { // 删除学生
	 // cout << "\n [ERR]无法使用该功能,没写" << endl;
	cout << "=========删除学生==========" << endl;
    
    if (studentCount == 0) {
        cout << "[WARN] 没有学生信息可删除！" << endl;
        return;
    }
    
    int deleteId;
    cout << "输入要删除的学生学号: ";
    cin >> deleteId;
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == deleteId) {
            // 将后面的元素向前移动
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            // 清空最后一个元素（可选，但更安全）
            students[studentCount - 1] = Student{};
            studentCount--;
            cout << "学生删除成功！" << endl;
            return;
        }
    }
    
    cerr << "[ERROR] 没有找到学号为 " << deleteId << " 的学生！" << endl;
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
