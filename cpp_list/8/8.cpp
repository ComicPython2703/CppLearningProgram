#include <iostream>
#include <vector>    // 导入 vector
using namespace std; 
// vector 尾部添加 尾部删除
// 指定位置删除
// 指定位置添加

int main()
{
    // vector 容器基本使用

    // 初始化 方法1
    vector <int> a1_(3);       // 每个元素默认为0
    // 初始化 方法2
    vector <int> a2_(3, 7);    // 每个元素设置为7
    // 初始化 方法3  C++ 11标准
    vector <int> a3_{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 获取 第0个
    a1_.at(0);
    // 修改为零
    a3_[8] = 0;
    // 末尾追加
    a3_.push_back(10);


    cout << "获取：" << a1_[0] << a1_[1] << a1_[2] << endl;           // 不带检查
    cout << "获取：" << a2_.at(0) << a2_.at(1) << a2_.at(2) << endl;  // 带检测的
    cout << "修改为零：" << a3_.at(8) << endl;
    cout << "查看追加：" << a3_[9] << endl;

    // 清空测试
    vector <int> a4_{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "清空前：" << a4_.size() << " 内容：";

    for (auto i : a4_)
    {
        cout << i;
    }


    //// 增 指定位置
    //// 指定位置插入元素的时间复杂度为 O(n)，因为需要移动插入点后的所有元素。
    //std::vector<int> vec = { 1, 2, 3, 4, 5 };
    //// 指定位置插入元素 当前结果：1 2 10 3 4 5
    //vector<int>::iterator it = vec.insert(vec.begin() + 2, 10);

    //// 返回值的作用
    //// 可以直接使用 it 访问插入的元素
    //*it = 20;  // 将插入的元素修改为 20
    //// 当前结果：1 2 20 3 4 5
    //// 可以不写返回值
    //vec.insert(vec.begin() + 2, 10);
    //// 当前结果：1 2 10 20 3 4 5
    //std::vector<int> vec2 = { 11, 12, 13 };
    //// 在位置2插入vec2的全部元素
    //vec.insert(vec.begin() + 2, vec2.begin(), vec2.end());
    //// 在位置2插入初始化列表中的元素
    //vec.insert(vec.begin() + 2, { 100, 200, 300 });
    //// 结果：1, 2, 10, 3, 4, 5
    //for (int num : vec) {
    //    std::cout << num << " ";
    //}



    // 清空
    a4_.clear();

    cout << endl << "清空后：" << endl;
    for (auto i:a4_)
    {
        cout << i << " 应该是空的" << endl;
    }

    cout << "=======================" << endl;

    cout << "获取第一个元素: " << a3_.front() << endl;   
    cout << "获取最后一个元素: " << a3_.back() << endl;  
    cout << "删除前: " << endl;  
    for (auto i:a3_)
    {
        cout << i << " ";
    }
    cout << endl;

    a3_.pop_back();  // 删除最后一个元素


    // 删除指定位置的元素
    // 指定位置删除元素的时间复杂度为 O(n)，因为需要移动插入点后的所有元素。 
    vector<int> v = { 10, 20, 30, 40, 50 };

    // v.begin();    // 指向第一个元素（10）
    // v.end();      // 指向最后一个元素的**下一个位置**（空的，不存在！）
    // v.end() - 1;  // 指向最后一个元素（50）

    // 常用组合：
    v.erase(v.begin());      // 删除第一个
    v.erase(v.end() - 1);    // 删除最后一个
    int n = 2;
    v.erase(v.begin() + (n - 1));  // 删除第n个
    // 返回值的作用和 insert 指定位置添加一样

    // 判空
    // 方法1：empty()函数（最标准）
    // 有些实现中，list需要遍历所有节点才能数出个数
    // 而empty()只需要检查头尾指针是否相同
    if (v.empty()) {
        cout << "vector为空" << endl;
    }
    if (v.size() == 0) {
        cout << "vector 长度为0" << endl;
    }


    cout << "删除后: " << endl;
    for (auto i : a3_)
    {
        cout << i << " ";
    }



    cout << endl;
    // 高维定义
    vector <vector<int>> a4
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "维度：" << a4.size() << endl;
    cout << "抽取某个数据 " << a4[2][2] << endl;


    return 0;
}
