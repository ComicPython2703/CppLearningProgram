#include <iostream>
#include <string>
#include <fstream>
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
const string FILENAME = "students.txt"; // 数据文件名


// 函数声明
void showMenu();                // 初始界面
void addStudent();              // 添加学生
void showAllStudents();         // 显示所有学生
void searchStudent();           // 查找学生
void updateStudent();           // 修改学生
void deleteStudent();           // 删除学生
bool isIdExist(int id);         // 检查学号是否存在
int findStudentIndex(int id);   // 查找学生索引
void saveToFile();              // 保存数据
void loadFromFile();            // 加载数据
string trim(const string str); // 去除字符串首尾空格
bool isPureInteger(const string inputStr);  // 输入是否为整数


int main() {

    int choice;
    string inputStr;      // 暂存
    // 程序启动时加载数据
    loadFromFile();
    cout << "========== 学生管理系统 ==========" << endl;
    cout << "已加载 " << studentCount << " 名学生信息" << endl;
    while (true) {
        showMenu();  // 显示功能界面
        ////添加学生1到数组
        //students[0].id = 1001;
        //students[0].name = "张三";
        //students[0].gender = "男";
        //students[0].className = "计算机1班";
        //students[0].specialty = "编程";
        //studentCount++;
        
        cout << "请选择操作 (1-6): ";
        cin >> inputStr;
        // 验证字符串是否为纯整数
        if (!isPureInteger(inputStr)) {
            cout << "输入无效，请输入纯整数（1-6）！" << endl;
            // 清空缓冲区残留（防止异常输入干扰后续循环）
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // 直接重新循环，不执行任何功能
        }
        // 纯整数字符串转换为int类型
        choice = stoi(inputStr);
        
    
        if (choice == 1) {
            addStudent();
        }
        else if (choice == 2) {
            showAllStudents();
        }
        else if (choice == 3) {
            searchStudent();
        }
        else if (choice == 4) {
            updateStudent();
        }
        else if (choice == 5) {
            deleteStudent();
        }
        else if (choice == 6) {
            // 程序结束前保存数据
            saveToFile();
            cout << "数据已保存到文件 " << FILENAME << endl;
            cout << "感谢使用学生管理系统，再见！" << endl;
            break;
        }
        else {
            cout << "输入错误，请重新选择！" << endl;
            
        }
    }

    return 0;
}



// 显示菜单
void showMenu() {
   cout << "\n========== 功能菜单 ==========" << endl;
   cout << "1. 添加学生" << endl;
   cout << "2. 显示所有学生" << endl;
   cout << "3. 查找学生" << endl;
   cout << "4. 修改学生信息" << endl;
   cout << "5. 删除学生" << endl;
   cout << "6. 退出系统（自动保存）" << endl;
   cout << "==============================" << endl;
}

// 去除字符串首尾空格
string trim(const string str) {
    // 从头找不是空格的字符,若找不到则返回string::npos
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    // 从字符串末尾开始向前查找第一个不是空格的字符
    size_t last = str.find_last_not_of(' ');
    // 从x位置开始，截取x个字符:
    // 理解 起点、长度、
    return str.substr(first, (last - first + 1));
}

// 从文件加载数据
void loadFromFile() {

    // 读取txt文件  创建一个输入文件流对象并打开指定文件
    ifstream file(FILENAME);

    if (!file.is_open()) {
        cout << "未找到数据文件，将创建新文件" << endl;
        return;
    }

    string line;
    studentCount = 0;

    // // 从文件流中读取一行到字符串   学生要小于限定值
    while (getline(file, line) && studentCount < MAX_STUDENTS) {
        // 跳过空行
        if (line.empty()) {
            continue;
        }

        // 解析学生数据（格式：id|name|gender|className|specialty）
        // .find() 参数：查询目标、查询起点
        int pos1 = line.find('|');
        int pos2 = line.find('|', pos1 + 1);
        int pos3 = line.find('|', pos2 + 1);
        int pos4 = line.find('|', pos3 + 1);

        //cout << "解析格式位置： " << pos1 << " " << pos2 << " " << pos3 << " " << pos4 << " " << endl;

        if (pos1 == string::npos || pos2 == string::npos ||
            pos3 == string::npos || pos4 == string::npos) {
            continue; // 格式错误，跳过
        }

        // 提取各字段    // 从x位置开始，截取x个字符:
        string idStr = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string gender = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string className = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string specialty = line.substr(pos4 + 1);

        // 去除空格
        idStr = trim(idStr);
        name = trim(name);
        gender = trim(gender);
        className = trim(className);
        specialty = trim(specialty);

        // 转换为整数并存储   字符串 转 整数 stoi()
        students[studentCount].id = stoi(idStr);
        students[studentCount].name = name;
        students[studentCount].gender = gender;
        students[studentCount].className = className;
        students[studentCount].specialty = specialty;

        studentCount++;
    }

    file.close();
    cout << "从文件 " << FILENAME << " 成功加载 " << studentCount << " 名学生信息" << endl;
}

// 保存数据到文件
void saveToFile() {

    // 用于保存 创建一个输出文件流对象并打开指定文件
    ofstream file(FILENAME);

    if (!file.is_open()) {
        cout << "无法创建数据文件！" << endl;
        return;
    }

    // 将每个学生信息写入文件，格式：id|name|gender|className|specialty
    for (int i = 0; i < studentCount; i++) {
        file << students[i].id << "|"
            << students[i].name << "|"
            << students[i].gender << "|"
            << students[i].className << "|"
            << students[i].specialty << endl;
    }

    file.close();
}



// 检查学号是否存在
bool isIdExist(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return true;
        }
    }
    return false;
}

// 查找学生索引
int findStudentIndex(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 添加学生
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "学生数量已达到上限，无法添加！" << endl;
        return;
    }

    Student newStudent;

    cout << "\n----- 添加学生 -----" << endl;

    // 输入学号
    cout << "请输入学号: ";
    cin >> newStudent.id;

    // 检查学号是否重复
    if (isIdExist(newStudent.id)) {
        cout << "学号已存在，请重新输入！" << endl;
        return;
    }

    //cin.ignore(); // 清除输入缓冲区

    // 输入姓名
    cout << "请输入姓名: ";
    // 使用 getline 作为输入 是可以输入空格
    cin >> newStudent.name;

    // 输入性别
    cout << "请输入性别 (男/女): ";
    cin >> newStudent.gender;

    // 输入班级
    cout << "请输入班级: ";
    cin >> newStudent.className;

    // 输入特长
    cout << "请输入特长: ";
    cin >> newStudent.specialty;

    // 添加到列表
    students[studentCount] = newStudent;
    studentCount++;

    cout << "学生添加成功！" << endl;

    // 实时保存
    // saveToFile();
}


// 显示所有学生
void showAllStudents() {
    if (studentCount == 0) {
        cout << "当前没有学生信息！" << endl;
        return;
    }

    cout << "\n----- 所有学生信息 -----" << endl;
    cout << "==============================================================" << endl;
    cout << "学号\t姓名\t性别\t班级\t特长" << endl;
    cout << "==============================================================" << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << students[i].id << "\t"
            << students[i].name << "\t"
            << students[i].gender << "\t"
            << students[i].className << "\t"
            << students[i].specialty << endl;
    }

    cout << "==============================================================" << endl;
    cout << "共 " << studentCount << " 名学生" << endl;
}

// 查找学生
void searchStudent() {
    if (studentCount == 0) {
        cout << "当前没有学生信息！" << endl;
        return;
    }

    int choice;
    cout << "\n----- 查找学生 -----" << endl;
    cout << "1. 按学号查找" << endl;
    cout << "2. 按姓名查找" << endl;
    cout << "请选择查找方式: ";
    cin >> choice;

    if (choice == 1) {
        // 按学号查找
        int id;
        cout << "请输入学号: ";
        cin >> id;

        // 是否找到?
        int found = 0;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].id == id) {
                cout << "\n找到学生信息：" << endl;
                cout << "==============================================================" << endl;
                cout << "学号: " << students[i].id << endl;
                cout << "姓名: " << students[i].name << endl;
                cout << "性别: " << students[i].gender << endl;
                cout << "班级: " << students[i].className << endl;
                cout << "特长: " << students[i].specialty << endl;
                cout << "==============================================================" << endl;
                found = 1;
                break;
            }
        }

        if (!found) {
            cout << "未找到学号为 " << id << " 的学生" << endl;
        }

    }
    else if (choice == 2) {
        // 按姓名查找
        cin.ignore();  // 清除输入缓冲区
        string name;
        cout << "请输入姓名: ";

        // 读取一整行文本 参数:(输入、输出、)
        getline(cin, name);

        int foundCount = 0;
        cout << "\n查找结果：" << endl;
        cout << "==============================================================" << endl;
        cout << "学号\t姓名\t性别\t班级\t特长" << endl;
        cout << "==============================================================" << endl;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].name == name) {
                cout << students[i].id << "\t"
                    << students[i].name << "\t"
                    << students[i].gender << "\t"
                    << students[i].className << "\t"
                    << students[i].specialty << endl;
                foundCount++;
            }
        }

        cout << "==============================================================" << endl;
        if (foundCount == 0) {
            cout << "未找到姓名为 " << name << " 的学生" << endl;
        }
        else {
            cout << "共找到 " << foundCount << " 名学生" << endl;
        }

    }
    else {
        cout << "输入错误！" << endl;
    }
}

// 修改学生信息
void updateStudent() {
    if (studentCount == 0) {
        cout << "当前没有学生信息！" << endl;
        return;
    }

    int id;
    cout << "\n----- 修改学生信息 -----" << endl;
    cout << "请输入要修改的学生的学号: ";
    cin >> id;

    int index = findStudentIndex(id);

    if (index == -1) {
        cout << "未找到学号为 " << id << " 的学生" << endl;
        return;
    }

    // 显示当前信息
    cout << "\n当前学生信息：" << endl;
    cout << "==============================================================" << endl;
    cout << "学号: " << students[index].id << endl;
    cout << "姓名: " << students[index].name << endl;
    cout << "性别: " << students[index].gender << endl;
    cout << "班级: " << students[index].className << endl;
    cout << "特长: " << students[index].specialty << endl;
    cout << "==============================================================" << endl;

    cin.ignore(); // 清除输入缓冲区

    // 修改信息
    cout << "\n请输入新的信息（直接回车保持原值）" << endl;

    // 修改姓名
    string input;
    cout << "新姓名 (" << students[index].name << "): ";
    getline(cin, input);
    if (!input.empty()) {
        students[index].name = input;
    }

    // 修改性别
    cout << "新性别 (" << students[index].gender << "): ";
    getline(cin, input);
    if (!input.empty()) {
        students[index].gender = input;
    }

    // 修改班级
    cout << "新班级 (" << students[index].className << "): ";
    getline(cin, input);
    if (!input.empty()) {
        students[index].className = input;
    }

    // 修改特长
    cout << "新特长 (" << students[index].specialty << "): ";
    getline(cin, input);
    if (!input.empty()) {
        students[index].specialty = input;
    }

    cout << "学生信息修改成功！" << endl;
}


// 删除学生
void deleteStudent() {
    if (studentCount == 0) {
        cout << "当前没有学生信息！" << endl;
        return;
    }

    int id;
    cout << "\n----- 删除学生 -----" << endl;
    cout << "请输入要删除的学生的学号: ";
    cin >> id;

    int index = findStudentIndex(id);

    if (index == -1) {
        cout << "未找到学号为 " << id << " 的学生" << endl;
        return;
    }

    // 显示要删除的学生信息
    cout << "\n要删除的学生信息：" << endl;
    cout << "==============================================================" << endl;
    cout << "学号: " << students[index].id << endl;
    cout << "姓名: " << students[index].name << endl;
    cout << "性别: " << students[index].gender << endl;
    cout << "班级: " << students[index].className << endl;
    cout << "特长: " << students[index].specialty << endl;
    cout << "==============================================================" << endl;

    char confirm;
    cout << "确定要删除吗？(y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        // 删除学生：将后面的元素向前移动
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "学生删除成功！" << endl;
    }
    else {
        cout << "已取消删除操作" << endl;
    }

}
// 字符串是否为纯整数
bool isPureInteger(const string inputStr) {
    if (inputStr.empty()) return false; // 空字符串无效
    // 遍历字符串每个字符，判断是否为数字
    for (int i = 0; i < inputStr.size(); i++) {
        if (!isdigit(inputStr[i])) { // 存在非数字字符，返回无效
            return false;
        }
    }
    return true;
}


