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


// 主函数 - 程序入口
int main() {

    //// 结构体的使用 (单个)
    //// 创建结构体
    //Student newStudent;
    //newStudent.id = 1;
    //newStudent.name = "张三";          // 姓名
    //newStudent.gender = "男";          // 性别
    //newStudent.className = "1年1班";   // 班级
    //newStudent.specialty = "奥特飞踢"; // 特长
    //// 输出
    //cout << "学号: " << newStudent.id << endl;
    //cout << "姓名: " << newStudent.name << endl;
    //cout << "性别: " << newStudent.gender << endl;
    //cout << "班级: " << newStudent.className << endl;
    //cout << "特长: " << newStudent.specialty << endl;

    ////// 字符串拼接 
    ////// \t 表示一个制表符（Tab）相当于按下键盘上的 Tab
    ////// \n 换行 
    ////cout << newStudent.name + "\t使用了\n" + newStudent.specialty << endl;


    //// 创建多个结构体
    //cout << "=== 方法2: 使用结构体数组 ===" << endl;
    //// 创建学生数组（最多4个）
    //const int MAX = 4;
    //Student students[MAX];
    //int count = 0;  // 当前学生数量
    //// 添加学生1到数组
    //students[0].id = 1001;
    //students[0].name = "张三";
    //students[0].gender = "男";
    //students[0].className = "计算机1班";
    //students[0].specialty = "编程";
    //count++;
    //// 添加学生2到数组
    //students[1].id = 1002;
    //students[1].name = "李四";
    //students[1].gender = "女";
    //students[1].className = "数学2班";
    //students[1].specialty = "绘画";
    //count++;
    //// 添加学生3到数组
    //students[2].id = 1003;
    //students[2].name = "王五";
    //students[2].gender = "男";
    //students[2].className = "物理3班";
    //students[2].specialty = "篮球";
    //count++;
    //// 添加学生4到数组
    //students[3] = newStudent;
    //count++;

    //// 用循环输出所有学生
    //cout << "学号\t姓名\t性别\t班级\t特长" << endl;
    //cout << "----------------------------------------" << endl;
    //for (int i = 0; i < count; i++) {
    //    cout << students[i].id << "\t"
    //        << students[i].name << "\t"
    //        << students[i].gender << "\t"
    //        << students[i].className << "\t"
    //        << students[i].specialty << endl;
    //}
    //cout << "\n总共 " << count << " 名学生" << endl;


    //cout << "=== 方法3: 批量初始化数组 ===" << endl;

    // 创建时直接初始化数组
    Student students_1[] = {
        {1001, "张三", "男", "计算机1班", "编程"},
        {1002, "李四", "女", "数学2班", "绘画"},
        {1003, "王五", "男", "物理3班", "篮球"},
        {1004, "赵六", "女", "英语4班", "唱歌"},
        {1005, "钱七", "男", "化学5班", "实验"}
    };

    //cout << sizeof(students_1) << endl;
    //cout << sizeof(students_1[0]) << endl;

    // 计算数组长度
    int count_1 = sizeof(students_1) / sizeof(students_1[0]);

    // 输出
    cout << "学号\t姓名\t性别\t班级\t特长" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < count_1; i++) {
        cout << students_1[i].id << "\t"
            << students_1[i].name << "\t"
            << students_1[i].gender << "\t"
            << students_1[i].className << "\t"
            << students_1[i].specialty << endl;
    }
    cout << "\n总共 " << count_1 << " 名学生" << endl;



    return 0;
}