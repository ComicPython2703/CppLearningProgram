# C++ 编程基础笔记

---

## 基本语法

---

- `//` 单行注释
- `/* */` 多行注释
- `#include` 导入头文件
- `cout` 输出流，`<<` 输出操作符
- `endl` 换行（可选）
- `int` 定义整数
- `'` 字符
- `"` 字符串
- `;` 语句结束符（除特殊情况外必须加）

> 重要：必须区分字符和字符串，否则会出现 [warning] character constant too long for its type

```python
# Python 示例代码（对比用）
if __name__ == '__main__':
    print("Hello World")
```

```cpp
// C++ 示例代码
#include <iostream>  // 导入输入输出流库
using namespace std; // 使用标准命名空间

int main(void)       // 主函数定义
{
    cout << "Hello World" << endl; // 输出字符串并换行
    return 0;         // 返回0，表示程序正常结束
}
```

### 基础概念

- `#include <iostream>`：包含输入输出流的头文件
- `using namespace std;`：使用标准命名空间，避免每次写 `std::`
- `int main(void)`：主函数，程序入口点
- `return 0;`：函数返回值，0 表示正常退出

---

## 运算

---

### 基本算术运算

- `+` 加法运算
- `-` 减法运算
- `*` 乘法运算
- `/` 除法运算
- `%` 取余运算

> 注意：整数除法会丢弃小数部分，浮点数除法会保留小数

### 自增自减运算

```cpp
#include <iostream>
using namespace std;

int main(void){
    int i = 10;
    int k = 10;

    int a = i++;  // 先赋值后自增
    int b = ++k;  // 先自增后赋值
    
    cout << "i++后的a = " << a << endl;  // 输出: 10
    cout << "++k后的b = " << b << endl;  // 输出: 11
    cout << "i++后的i = " << i << endl;  // 输出: 11
    cout << "++k后的k = " << k << endl;  // 输出: 11
}
```

- `i++` 和 `i--`：先赋值后运算
- `++i` 和 `--i`：先运算后赋值

---

## 逻辑判断

---

### 逻辑运算符

- `!` 逻辑非，`true` 变 `false`，`false` 变 `true`
- `&&` 逻辑与，所有条件都为真时结果才为真
- `||` 逻辑或，至少一个条件为真时结果为真

### 优先级

- `!` > `&&` > `||`

### 布尔值

- `0` 和 `false` 为假，非零值和 `true` 为真

---

## 数据类型

---

### 基本类型

- `int` 整型
- `float` 单精度浮点型
- `double` 双精度浮点型
- `char` 字符型
- `bool` 布尔型

> 注意：`char` 类型只能用单引号 `'` 包裹单个字符

### 类型示例

```cpp
int num = 10;
float pi = 3.14f;
double precise = 3.1415926;
char letter = 'A';
bool isTrue = true;
```

---

## 三目运算符

---

### 语法格式

```text
条件 ? 表达式1 : 表达式2
```

### 示例

```cpp
int a = 5, b = 10;
int max = (a > b) ? a : b;  // max 为 10
```

> 注意：在 `cout` 中直接使用三目运算符时，建议用括号包裹

---

## Switch 语句

---

### 语法结构

```cpp
switch(表达式) {
    case 值1:
        语句1;
        break;
    case 值2:
        语句2;
        break;
    default:
        默认语句;
}
```

### 示例代码

```cpp
#include <iostream>
using namespace std;

int main(void){
    char grade;
    cin >> grade;
    
    switch(grade){
        case 'A':
            cout << "优秀";
            break;
        case 'B':
            cout << "良好";
            break;
        case 'C':
            cout << "及格";
            break;
        default:
            cout << "无效等级";
    }
    return 0;
}
```

> 注意：
>
> 1. `case` 后必须是常量表达式
> 2. 每个 `case` 块结束后应使用 `break` 退出
> 3. `default` 是可选的，处理所有未匹配的情况

---

## 循环结构

---

### while 循环

```cpp
while (条件) {
    // 循环体
}
```

### for 循环

```cpp
for (初始化; 条件; 更新) {
    // 循环体
}
```

### 示例‎

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    // 打印1到199的数字
    for(int i = 1; i < 200; i++)  // 修正：移除多余分号
    {
        cout << i << " ";
    }
    return 0;
}
```

> `size_t` 通常用于表示大小/索引，但初学者使用 `int` 更直观

---

## 数组

---

### 一维数组

```cpp
// 定义方式1：指定大小和元素
int arr1[5] = {1, 2, 3, 4, 5};

// 定义方式2：自动推导大小
int arr2[] = {1, 2, 3, 4, 5};

// 定义方式3：指定大小，部分初始化
int arr3[5] = {1, 2};  // 前两个为1,2，其余为0
```

### 数组访问

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
cout << numbers[0];  // 输出: 10（第一个元素）
cout << numbers[4];  // 输出: 50（最后一个元素）
```

### 数组下标

```text
{1, 2, 3, 4, 5, 6, 7}
 0  1  2  3  4  5  6
```

> 注意：
>
> 1. 数组下标从0开始
> 2. 不要访问超出数组边界的位置

---

## 函数

---

### 函数定义

```cpp
返回类型 函数名(参数列表) {
    // 函数体
    return 返回值;  // 如果返回类型不是void
}
```

### 函数示例

```cpp
#include <iostream>
using namespace std;

// 函数声明
int add(int a, int b);

int main() {
    int result = add(5, 3);
    cout << "5 + 3 = " << result << endl;
    return 0;
}

// 函数定义
int add(int a, int b) {
    return a + b;
}
```

### 参数传递方式

1. 值传递：传递参数的副本
2. 引用传递：传递参数的引用
3. 指针传递：传递参数的地址

---

## C++ 标准库

---

### string 库

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // 初始化
    string s1;                 // 空字符串
    string s2 = "Hello";       // 直接初始化
    string s3 = s2;            // 拷贝初始化
    
    // 字符串操作
    s1 = "Test";
    string combined = s1 + " " + s2;  // 字符串拼接
    
    // 字符串长度
    cout << "s2长度: " << s2.length() << endl;
    
    // 访问字符
    cout << "s2第一个字符: " << s2[0] << endl;
    
    return 0;
}
```

### vector 库

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    // 创建vector
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // 添加元素
    nums.push_back(6);
    
    // 访问元素
    cout << "第一个元素: " << nums[0] << endl;
    
    // 遍历vector
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    // 使用范围for循环
    for(int num : nums) {
        cout << num << " ";
    }
    
    return 0;
}
```

### vector 常用方法

- `push_back(value)`：在末尾添加元素
- `pop_back()`：删除末尾元素
- `size()`：获取元素数量
- `empty()`：判断是否为空
- `clear()`：清空所有元素

---

## 总结

这份笔记涵盖了C++的基础语法，包括：

1. 基本语法结构
2. 数据类型和变量
3. 运算符和表达式
4. 控制结构（分支和循环）
5. 数组和容器
6. 函数定义和使用
7. 常用标准库

建议结合实际编程练习加深理解，每个概念都要编写代码验证效果。

---
>copyright ComicPython6045 2020-2026 All Rights Reserved
