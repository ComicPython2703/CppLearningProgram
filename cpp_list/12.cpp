#include <iostream>
#include <chrono>    // C++11 时间库头文件

int main() {
    // 获取当前时间点：纳秒级别
    auto now = std::chrono::system_clock::now();
    // 原数据类型如下
    //std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    // 将time_point转换为time_t类型
    // time_t是C/C++标准时间类型，表示从1970年1月1日00:00:00 UTC到现在的秒数（Unix时间戳）
    // to_time_t()函数进行类型转换，会丢失纳秒/微秒精度，只保留秒级精度
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // 定义tm结构体变量，用于存储分解后的本地时间信息
    // tm结构包含：年、月、日、时、分、秒、星期等时间分量
    std::tm timeinfo;

    // 条件编译：根据操作系统选择不同的线程安全时间转换函数
    // Windows平台使用localtime_s（微软安全版本）
    // 函数原型：errno_t localtime_s(struct tm* _Tm, const time_t* _Time)
    // 参数1：输出参数，存储转换后的时间
    // 参数2：输入参数，待转换的time_t时间
#ifdef _WIN32
    localtime_s(&timeinfo, &now_time);    // Windows线程安全版本
#else
    // Linux/Unix/macOS平台使用localtime_r（POSIX标准）
    // 函数原型：struct tm* localtime_r(const time_t* timep, struct tm* result)
    // 参数1：输入参数，待转换的time_t时间
    // 参数2：输出参数，存储转换后的时间
    // 返回值：成功返回result指针，失败返回NULL
    localtime_r(&now_time, &timeinfo);    // Unix/Linux线程安全版本
#endif

    // 输出格式化时间字符串，格式：年-月-日 时:分:秒
    // 注意：tm结构中的时间分量存储规则：
    // tm_year：从1900年开始的年数，所以需要加1900得到实际年份
    // tm_mon：月份从0开始计数（0=1月，1=2月...11=12月），所以需要加1得到实际月份
    // tm_mday：月份中的天数（1-31），直接使用
    // tm_hour：小时（0-23），24小时制
    // tm_min：分钟（0-59）
    // tm_sec：秒（0-59），通常范围0-60（60用于闰秒）
    std::cout << (timeinfo.tm_year + 1900) << "-"   // 年
        << (timeinfo.tm_mon + 1) << "-"             // 月
        << timeinfo.tm_mday << " "                  // 日
        << timeinfo.tm_hour << ":"                  // 时
        << timeinfo.tm_min << ":"                   // 分
        << timeinfo.tm_sec << std::endl;            // 秒

    return 0;
}

// 注意：此代码输出的时间格式中，如果月份、日期、小时、分钟、秒是单位数，不会补零
// 例如：2024-3-5 9:5:8 而不是 2024-03-05 09:05:08
// 如需补零格式，需要添加iomanip头文件和setw/setfill格式化控制