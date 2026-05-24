
// 一、主流 C++ 编译器（按使用频率排序）

// 编译器名称：MSVC（Microsoft Visual C++）
// 核心特点：微软闭源编译器，VS 内置，对 Windows API/COM 支持最佳，C++ 新标准（C++20/23）支持及时，报错信息贴合 VS 生态
// 适用平台：Windows
// 典型使用场景：Windows 桌面程序、游戏开发、Windows 驱动、.NET 混合开发

// 编译器名称：GCC（GNU Compiler Collection）
// 核心特点：开源跨平台，C++ 标准支持全面（C++98 至 C++23），Linux/macOS 系统默认，嵌入式开发首选
// 适用平台：Linux/macOS/Windows（MinGW）
// 典型使用场景：跨平台 C++ 开发、Linux 服务端、嵌入式（ARM/MCU）、开源项目

// 编译器名称：Clang/LLVM
// 核心特点：开源，基于 LLVM 架构，编译速度比 GCC 快，报错信息极友好（新手易读），兼容 GCC 语法，C++20/23 支持更前沿
// 适用平台：Linux/macOS/Windows
// 典型使用场景：macOS/iOS 开发（Xcode 默认）、Android NDK、Clion 开发、对编译速度 / 报错体验有要求的场景

// 编译器名称：Intel C++ Compiler (ICC/ICX)
// 核心特点：英特尔专属，对 x86/ARM 架构深度优化（性能比 GCC/MSVC 高 5%-20%），兼容 MSVC/GCC 语法
// 适用平台：Windows/Linux/macOS
// 典型使用场景：高性能计算（HPC）、科学计算、英特尔芯片专属优化的程序



// 主流编译器的小分支
// 编译器名称：MinGW-w64
// 核心特点：GCC 的 Windows 移植版，轻量无需安装 VS，直接生成 Windows 原生可执行文件
// 适用场景：Windows 轻量 C++ 开发、不想装 VS 的场景

// 编译器名称：TDM-GCC
// 核心特点：精简版 MinGW，体积更小、安装更快，适合快速搭建 Windows C++ 编译环境
// 核心特点：精简版 MinGW，体积更小、安装更快，适合快速搭建 Windows C++ 编译环境

// 编译器名称：ARM GCC
// 核心特点：GCC 的 ARM 架构定制版，支持 STM32、树莓派等 ARM 芯片，C++ 嵌入式开发专用
// 适用场景：嵌入式 C++ 开发（如 STM32、Arduino 进阶）

// 编译器名称：Emscripten
// 核心特点：基于 LLVM，将 C++ 编译为 WebAssembly（Wasm），实现前端运行 C++ 代码
// 适用场景：前端跨端开发、网页运行高性能 C++ 逻辑

// 编译器名称：NVCC
// 核心特点：NVIDIA 专属，编译 CUDA C++，支持 GPU 并行计算，兼容 GCC/Clang 语法
// 适用场景：显卡加速计算、AI 训练、高性能并行程序


// 日常开发核心选 3 个：MSVC（Windows）、GCC（Linux）、Clang（macOS / 跨平台）；
// 特殊场景选定制版：MinGW（Windows 轻量）、ARM GCC（嵌入式）、NVCC（CUDA）；
// 新手优先选「自带编译器的 IDE」：VS（MSVC）、Clion（Clang/GCC）、Xcode（Clang），无需手动配置。
// 简单来说：Windows 用 MSVC，Linux 用 GCC，macOS 用 Clang，跨平台 / 新手用 Clang，覆盖 90% 的 C++ 开发场景。


// gcc --versio 查看gcc版本


// 例如: c17-c语言17标准、c++17 c++语言17标准 

// C++各个版本的新特性
// https://gcc.gnu.org/projects/cxx-status.html



// GCC 版本与 C/C++ 标准对应关系:

// GCC 13.1 | 2023-04-26 | C17 | C++17
// GCC 12.2 | 2022-08-19 | C17 | C++17
// GCC 12.1 | 2022-05-06 | C17 | C++14
// GCC 11.3 | 2022-04-21 | C17 | C++17
// GCC 11.2 | 2021-07-28 | C17 | C++17
// GCC 11.1 | 2021-04-27 | C17 | C++17
// GCC 10.4 | 2022-06-28 | C17 | C++14
// GCC 10.3 | 2021-04-08 | C17 | C++14
// GCC 10.2 | 2020-07-23 | C17 | C++14
// GCC 10.1 | 2020-05-07 | C17 | C++14
// GCC 9.5 | 2022-05-27 | C17 | C++14
// GCC 9.4 | 2021-06-01 | C17 | C++14
// GCC 9.3 | 2020-03-12 | C17 | C++14
// GCC 9.2 | 2019-08-12 | C17 | C++14
// GCC 9.1 | 2019-05-03 | C17 | C++14
// GCC 8.5 | 2021-05-14 | C17 | C++14
// GCC 8.4 | 2020-03-04 | C17 | C++14
// GCC 8.3 | 2019-02-22 | C17 | C++14
// GCC 8.2 | 2018-07-26 | C17 | C++14
// GCC 8.1 | 2018-05-02 | C17 | C++14
// GCC 7.5 | 2019-11-14 | C11 | C++14
// GCC 7.4 | 2018-12-06 | C11 | C++14
// GCC 7.3 | 2018-01-25 | C11 | C++14
// GCC 7.2 | 2017-08-14 | C11 | C++14
// GCC 7.1 | 2017-05-02 | C11 | C++14
// GCC 6.5 | 2018-10-26 | C11 | C++98
// GCC 6.4 | 2017-07-04 | C11 | C++14
// GCC 6.3 | 2016-12-21 | C11 | C++14
// GCC 6.2 | 2016-08-22 | C11 | C++14
// GCC 6.1 | 2016-04-27 | C11 | C++14
// GCC 5.5 | 2017-10-10 | C11 | C++98
// GCC 5.4 | 2016-06-03 | C11 | C++98
// GCC 4.9.4| 2016-08-03 | C90 | C++98

// C 标准支持:
// GCC 8 + 默认 C17
// GCC 5~7 默认 C11
// GCC 4.9 及以下默认 C90

// C++ 标准支持:
// GCC 11/12/13 
// 默认 C++17(GCC 12.1 例外为 C++14)
// GCC 7~10 默认 C++14(GCC 6.5/GCC 5.x 例外为 C++98)
// GCC 4.9 及以下默认 C++ 98




// vs查看 编译器与C++支持版本

// VS2026 → 144(1940+)
// VS2022 → 143(1930+)
// VS2019 → 142(1920+)
// VS2017 → 141(1910+)
// VS2015 → 140(1900)

#include <iostream>
#include <string>

// 辅助函数：解析_MSC_VER对应VS/MSVC版本
std::string get_vs_version(int msc_ver) {
    if (msc_ver >= 1940) return "VS2026 (MSVC v144)";
    if (msc_ver >= 1930) return "VS2022 (MSVC v143)";
    if (msc_ver >= 1920) return "VS2019 (MSVC v142)";
    if (msc_ver >= 1910) return "VS2017 (MSVC v141)";
    if (msc_ver == 1900) return "VS2015 (MSVC v140)";
    if (msc_ver >= 1800) return "VS2013 (MSVC v120)";
    if (msc_ver >= 1700) return "VS2012 (MSVC v110)";
    return "更早版本(VS2010及以下)";
}

// 辅助函数：判断C++标准支持情况(纯文本，无Unicode)
std::string get_cpp_std_support() {
    std::string res;
    // 核心C++标准宏(_MSVC_LANG是VS专用的C++标准宏)
    res += "【默认/最高支持的C++标准】\n";
#if _MSVC_LANG >= 202600L // C++26(实验性)
    res += "[支持] C++26(实验性支持，需开启预览功能)\n";
#elif _MSVC_LANG >= 202302L // C++23
    res += "[支持] C++23(完全支持)\n";
#elif _MSVC_LANG >= 202002L // C++20
    res += "[支持] C++20(默认/完全支持)\n";
#elif _MSVC_LANG >= 201703L // C++17
    res += "[支持] C++17(默认/完全支持)\n";
#elif _MSVC_LANG >= 201402L // C++14
    res += "[支持] C++14(默认/完全支持)\n";
#elif _MSVC_LANG >= 201103L // C++11
    res += "[支持] C++11(默认/完全支持)\n";
#else // C++98/03
    res += "[支持] C++98/C++03(默认支持)\n";
#endif

    // 补充关键特性支持(精准到具体功能)
    res += "\n【关键C++特性支持】\n";
    // C++11核心特性
#if __cpp_lambdas >= 200907L
    res += "[支持] C++11 Lambda表达式\n";
#else
    res += "[不支持] C++11 Lambda表达式\n";
#endif
#if __cpp_auto >= 201104L
    res += "[支持] C++11 auto自动类型推导\n";
#else
    res += "[不支持] C++11 auto自动类型推导\n";
#endif

    // C++14核心特性
#if __cpp_return_type_deduction >= 201304L
    res += "[支持] C++14 auto返回值推导\n";
#else
    res += "[不支持] C++14 auto返回值推导\n";
#endif

    // C++17核心特性
#if __cpp_structured_bindings >= 201606L
    res += "[支持] C++17 结构化绑定\n";
#else
    res += "[不支持] C++17 结构化绑定\n";
#endif
#if __cpp_filesystem >= 201703L
    res += "[支持] C++17 std::filesystem\n";
#else
    res += "[不支持] C++17 std::filesystem\n";
#endif

    // C++20核心特性
#if __cpp_concepts >= 201907L
    res += "[支持] C++20 概念(Concepts)\n";
#else
    res += "[不支持] C++20 概念(Concepts)\n";
#endif
#if __cpp_ranges >= 201911L
    res += "[支持] C++20 范围(Ranges)\n";
#else
    res += "[不支持] C++20 范围(Ranges)\n";
#endif

    // C++23核心特性
#if __cpp_static_call >= 202207L
    res += "[支持] C++23 std::static_call\n";
#else
    res += "[不支持] C++23 std::static_call\n";
#endif

    return res;
}

int main() {
    // 关闭同步，提升终端输出效率(可选，避免乱码)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 1. 输出编译器基础信息
    std::cout << "========================================" << std::endl;
    std::cout << "【VS编译器核心信息】" << std::endl;
    std::cout << "MSVC版本宏(_MSC_VER)：" << _MSC_VER << std::endl;
    std::cout << "对应VS版本：" << get_vs_version(_MSC_VER) << std::endl;
    std::cout << "MSVC详细版本(_MSC_FULL_VER)：" << _MSC_FULL_VER << std::endl;
    std::cout << "MSVC工具集版本(_MSC_BUILD)：" << _MSC_BUILD << std::endl;

    // 2. 输出C++标准支持情况
    std::cout << "========================================" << std::endl;
    std::cout << get_cpp_std_support() << std::endl;

    // 3. 输出手动指定标准的提示
    std::cout << "========================================" << std::endl;
    std::cout << "【手动指定C++标准的编译参数】" << std::endl;
    std::cout << "C++11: /std:c++11" << std::endl;
    std::cout << "C++14: /std:c++14" << std::endl;
    std::cout << "C++17: /std:c++17" << std::endl;
    std::cout << "C++20: /std:c++20" << std::endl;
    std::cout << "C++23: /std:c++23" << std::endl;
    std::cout << "C++26: /std:c++26(仅VS2026+，需开预览)" << std::endl;

    return 0;
}