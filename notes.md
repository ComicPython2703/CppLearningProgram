# 本目录笔记

---

## 基本

- `//` 单行注释
- `/* */` 多行注释
- `#include` 导入库或文件
- `int` 定义整数
- `'` 字符
- `"` 字符串
- `;` 语句结束符,大多数语句末尾需要加分号(函数定义、控制结构的大括号后不加)

> 重要 必须区分字符和字符串,否则会出现 [warning] character constant too long for its type

```python
# 示例 python 代码,和 C++ 对比可以发现 C++ 要复杂许多
if __name__ == '__main__':
    print("Hello World")
```

```cpp
// example cpp code
#include <iostream>  // 导入 <iostream> 库
using namespace std; // 使用命名空间 std
int main(void)       // 定义主函数,必须是 main,void 可写可不写
{
    // cout 为输出,`<<` 后面必须接字符串或已定义的变量,endl 为换行,可写可不写
    cout << "Hello World" << endl;
    return 0;         // 返回 0,可写可不写
}
```

- `#include <iostream>` 包含头文件 iostream,提供标准的输入输出功能

>[WARNING]
> *绝对禁止导入`bits/stdc++.h`!!!!!*
> *这个头文件罪大恶极,一口气导入了所有的库,这使得编译时间大幅增加!!!*

- `using namespace std;` 使用标准命名空间,简化代码书写

`std`命名空间,本示例使用了

- `cout` 输出流,`<<` 输出操作符
- `endl` 换行(可选)
- `int main(void)` 主函数,程序入口

>[WARNING]
> *在正规生产环境下绝对禁止`using namespace`,否则会命名污染!!!*

---

## 运算

### 基本运算

- `+` 加法运算
- `-` 减法运算
- `*` 乘法运算,相当于 Python 的 `*`
- `/` 除法运算(整数除法会截断小数部分)
- `%` 取余运算(只能用于整数)

> 除法运算需区分整数和浮点数

### `i++` 和 `++i` 的区别

示例代码如下:

#### Python

Python 中没有 `++` 运算符,以下代码仅模拟概念:
<!--这个观点待确认-->
```python
if __name__ == "__main__":
    i = 10
    k = 10

    # Python 中没有 i++ 或 ++k,这里使用 i+1 表示效果
    a = i + 1   # 相当于后置效果(但不会改变 i)
    b = k + 1   # 相当于前置效果(但不会改变 k)

    print("i+1 后的 a = ", a)   # 11
    print("k+1 后的 b = ", b)   # 11
    print("i 的值 = ", i)        # 10
    print("k 的值 = ", k)        # 10
```

#### C++

```cpp
#include <iostream>
using namespace std;
int main(void) {
    int i = 10;
    int k = 10;

    int a = i++;   // 后置: 先赋值给 a,再让 i 自增
    int b = ++k;   // 前置: 先让 k 自增,再赋值给 b
    cout << "i++ 后的 a = " << a << endl;
    cout << "++k 后的 b = " << b << endl;
    cout << "i++ 后的 i = " << i << endl;
    cout << "++k 后的 k = " << k << endl;
    /* 输出:
       i++ 后的 a = 10
       ++k 后的 b = 11
       i++ 后的 i = 11
       ++k 后的 k = 11
    */
}
```

- `i++`(后置)先使用 `i` 的当前值参与表达式,再让 `i` 自增
- `++i`(前置)先让 `i` 自增,再使用新值参与表达式

---

## 判断

- `!` 取反,`true` 变为 `false`,`false` 变为 `true`,相当于 Python 的 `not`
- `&&` 逻辑与,必须全部为真才为真,相当于 Python 的 `and`
- `||` 逻辑或,至少一个为真即为真,相当于 Python 的 `or`

> `&&` 必须所有条件都为真才为真  
> 数值 `0` 和 `false` 视为假,非零值和 `true` 视为真  
> `||` 只要有一个条件为真即为真

### 优先级

- `!` > `&&` > `||`

---

## 数值类型

- `int` 整型
- `float` 浮点型
- `char` 字符型

> `char` 只能用单引号 `'`,不能用双引号 `"`,只能存储单个字符,不能存储字符串

- `bool` 布尔型,用于逻辑判断,`true` 为 `1`,`false` 为 `0`

---

## 三目运算符

**语法**: `(条件 ? 表达式1 : 表达式2)`

- `?` 判断条件
- `:` 根据条件选择: 条件为真时取左侧值,为假时取右侧值

示例代码如下

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10;
    // ---使用定义值输出---
    int max = (a > b) ? a : b;
    cout << max << endl;
    // ---使用cout输出---
    cout << (a > b) ? a : b; // 错误
    cout << ((a > b) ? a : b); // 正确
}
```

> 在 `cout` 中使用三目运算符时,给表达式必须加括号 `()`,因为 `<<` 的优先级高于 `?:`,不加括号会导致只输出 0,也就是`false`

---

## Switch 语句

- `default` 默认分支,当所有 `case` 都不匹配时执行
- `case` 匹配值,如果表达式等于该值,则执行其后代码
- `break` 跳出 `switch` 结构,防止继续执行后续分支

> **`switch` 括号中的表达式必须是整型、枚举或可隐式转换为整型的类型,`case` 后面必须是常量表达式**
> ?
> **每个 `case` 执行完后通常需要 `break;`,否则会继续执行下一个 `case` 的代码(“穿透”)**

示例代码如下:

```cpp
#include <iostream>
using namespace std;

int main(void) {
    char examp;
    cin >> examp;
    switch(examp) {
        case 'A':
            cout << "示例一";
            break;
        case 'B':
            cout << "示例二";
            break;
        case 'C':
            cout << "示例三";
            break;
        default:
            cout << "示例四";
    }
}
```

---

## 循环

### while 循环

语法: `while (条件) { 循环体 }`

当条件为真时,执行循环体；条件为假时退出循环.

### for 循环

#### 正向循环

示例代码:

```cpp
for (int i = 0; i < 200; i++) {
    // code
}
```

- `int i = 0;` 初始化语句(起点)
- `i < 200;` 循环条件(终点)
- `i++` 循环变量的增量表达式 (步长)

> `size_t` 是无符号整数类型,通常用于表示数组索引,建议在循环中使用 `int` 或 `size_t` 但需注意符号匹配.

#### 反向循环

与正向循环不同,反向循环是 `i--` 而不是 `i++`

> **`反向循环`一般适用于数组(尤其是动态数组)**

示例代码

```cpp
for (int i = 100; i >= 0; i--) {
    // code
}
```

> **反向循环的起点是数组最大值**

---

## 数组

### 数组基础概念

定义: 相同数据类型的元素组成的集合.

示例: `int array[5] = {1, 2, 3, 4, 5};`  
访问: `cout << array[4];`

- `int` 指定数组元素的类型(可以是任意数据类型)
- `array` 数组名称
- `[5]` 数组长度(元素个数)
- `{1, 2, 3, 4, 5}` 初始化列表

数组下标从 0 开始:

```text
元素: {1, 2, 3, 4, 5, 6, 7}
下标:  0  1  2  3  4  5  6
```

> **数组名不能使用 C++ 保留关键字**  
> **元素个数不能超过 `[长度]` 定义的值**

### 输出

使用循环遍历数组:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};   // 初始化包含5个元素的 vector
    for (int i = 0; i < nums.size(); i++) {
        cout << "数组内容: " << nums[i] << " ";
    }
    return 0;
}
```

### 查找

先定义数组,再通过下标访问:

```cpp
int arrange[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
cout << arrange[6];   // 输出第7个元素(下标6)
```

### 字节大小

**使用 `sizeof()` 可以获取一个数组的字节大小**

示例代码

```cpp
int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 数组
sizeof(n) // n 的字节大小
```

### 长度

还是原来的 `sizeof()` , **这次需要将`此数组本体的字节大小` 除以 `此数组的 不超过最大索引 字节大小`**

示例代码

```cpp
int n[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 数组
int len_1 = sizeof(n) / sizeof(n[0]);     // 数组个数
cout << len_1 << endl;
```

---

## 函数

### 函数定义

```cpp
返回类型 函数名(参数列表) {
    // 函数体
    return 返回值;  // 如果返回类型不是 void
}
```

- 如果返回类型是 `void`,可以省略 `return`

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

### 参数

#### 参数定义

由`数据类型`和`变量`组成

#### 参数传递方式

1. **值传递**: 传递参数的副本,函数内修改不影响原变量
2. **引用传递**: 传递参数的引用,使用 `&` 修饰,函数内修改会影响原变量
3. **指针传递**: 传递参数的地址,使用 `*` 修饰,通过解引用操作原变量

### 返回值

#### 定义

使用 `return <返回类型>` 返回 `值`

> **只有 `void` 类型的函数无需返回任意值** **其他类型的函数必须返回一个值**

#### 接收返回值

定义变量接收返回值
示例

```cpp
// 函数示例 简单的乘法计算
void outlen(int a , int b) {
    return a * b;
}
int output = outlen(2,3);
// 此处 outlen 的 返回值为 6
```

---

## 结构体

结构体(`struct`)用于将多个不同类型的变量组合成一个新的数据类型.

**语法:**

```cpp
struct 结构体名称 {
    数据类型 成员1;
    数据类型 成员2;
    // ...
};
```

**示例:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// 定义一个结构体
struct Student {
    string name;
    int age;
    float score;
};

int main() {
    // 创建结构体变量并初始化
    Student stu1 = {"张三", 18, 95.5};

    // 访问成员(使用点运算符 .)
    cout << "姓名: " << stu1.name << endl;
    cout << "年龄: " << stu1.age << endl;
    cout << "成绩: " << stu1.score << endl;

    return 0;
}
```

- 结构体中的成员可以是任意类型(基本类型、数组、指针、甚至其他结构体).
- 通过 `.` 访问成员,若使用指针则用 `->`.

### 查找 1

这里使用的`ListNude`定义如下

```cpp
struct ListNude
{
    int val; //元素
    ListNude* next; //指针

    ListNude(int x): val(x),next(NULL){} 
    ListNude(int x,ListNude* next) : val(x),next(next) {}
    // 函数名(参数):参数赋值
};
```

通过 指针 和 `while`循环遍历 得到要查找的值

示例代码如下

```cpp
/*核心代码*/
ListNude *p = head; // 定义指针,指向头
int nl = 0;
while (p)
{
    nl += 1;
    if (p->val == 4)
    {break;}
}
```

### 删除

通过 指针 和 `for`循环遍历

```cpp
ListNude *p2 = head;
for (int i = 0; i < 2; i++)
{
    p2 = p2->next;
}
p2->next = p2->next->next;
```

### 添加

> [WARNING]
> 部分内容需要修正

#### 头部插入

```cpp
// 在单链表头部插入一个新节点 0
// 步骤1：新建节点
ListNude* newNude = new ListNude(0); // 新建节点
// 步骤2：链接节点
newNude->next = head;
// 步骤3：将头节点 设为新的节点
head = newNude;
```

#### 中间插入

```cpp
// 先要找到前驱节点，即第 3 个节点
ListNude* p1 = head;

// 步骤1：找到插入的位置
for (int i = 0; i < 2; i++) {
    p1 = p1->next;
}
// 此时 p 指向第 3 个节点
// 组装新节点的后驱指针
ListNude* newNode = new ListNude(66);  // 步骤2：新建节点
newNode->next = p1->next;  // 步骤3：新节点的下一个指针 指向 后节点(前节点的下一个指针)
// 步骤4：前节点的下一个指针 指向新节点
p1->next = newNode;
```

#### 尾部追加

```cpp
ListNude *p = head; // 定义指针 p 指向 头节点

while (p -> next != nullptr)
    {p = p -> next;} // 将指针P走向最后一个节点

p -> next = new ListNude(6); // 此时p是最后一个节点,在这里新建节点

```

---

## 数据结构

数据结构是计算机中组织和存储数据的方式. C++ 中常用的数据结构有:

### 1. 原生数组(Array)

已在前面介绍,固定大小,连续存储.

### 2. 动态数组(vector)

动态数组,大小可自动调整. 详见笔记后面的 `vector` 部分.

### 3. 栈(stack)

后进先出(LIFO)容器. 需要包含 `<stack>`.

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);      // 压栈
    s.push(20);
    cout << s.top() << endl;  // 访问栈顶: 20
    s.pop();                  // 出栈
    cout << s.top() << endl;  // 10
    return 0;
}
```

### 4. 队列(queue)

先进先出(FIFO)容器. 需要包含 `<queue>`.

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl; // 队头: 1
    q.pop();
    cout << q.front() << endl; // 队头: 2
    return 0;
}
```

> 更多数据结构(如链表、映射、集合)可参考 C++ 标准模板库(STL)文档.

---

## 指针

### 基础概念

 `指针` 是 存储 `变量地址` 的 `变量`

- `int *ptr;` 定义一个指向 `int` 类型的指针
- `&var` 取变量 `var` 的地址
- `*ptr` 解引用,访问指针指向的值,`*`的位置可任意

```cpp
#include <iostream>
using namespace std;

int main() {
    const int MAX_01 = 3; // const 代表后续不可更改
    int var_03[MAX_01] = {10, 100, 200};   // 整数数组
    int *ptr_03[MAX_01];                   // 指针数组

    for (int i = 0; i < MAX_01; i++) {
        ptr_03[i] = &var_03[i];            // 将每个元素的地址存入指针数组
    }
    for (int i = 0; i < MAX_01; i++) {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr_03[i] << endl;        // 通过指针访问值
    }
}
```

> C++11 起推荐使用 `nullptr` 替代 `NULL` 表示空指针

---

## 栈

### 内存中的栈

在计算机内存中,栈(Stack)是一种后进先出(LIFO,Last In First Out)的线性数据结构. 它主要负责管理函数调用、局部变量和程序执行上下文,由操作系统或编程语言的运行时环境自动管理

### 栈区

由系统自动分配,速度较快. 但程序员是无法控制的. (只要栈的剩余空间大于所申请空间,系统将为程序提供内存,否则将报异常提示栈溢出. )

### 危险操作

#### 大数组

```cpp
// 1. 不要在栈上定义大数组
void func() {
    int big[10000000];  // 崩溃 栈会炸
}
```

#### 长数组

```cpp
// 2. 不要用定长数组作为大参数
void process(int data[1000000]) {  // 危险 栈会炸
}
```

#### 返回局部数组地址

```cpp
// 3. 不要返回局部数组地址
int* bad() {
    int arr[100];
    return arr;  // 危险
}
// 函数结束,arr 被销毁！在函数外使用索引无法访问,因为被销毁了.

```

---

## C++ 内置库

### string 库

>[IMPORTANT]
> **在没有对字符串操作(如增删改)的情况下不建议导入此库**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    /* 初始化方式 */
    string s1;                // 空字符串
    string s2{"hello"};       // 列表初始化
    string s3{s2};            // 拷贝初始化
    string s4{"hello", 4};    // 取前 4 个字符
    string s5{s2, 1, 3};      // 从下标 1 开始取 3 个字符
    // string s6(5, 'x');     // 5 个 'x'(另一种初始化方式)

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;

    /* 赋值 */
    string n1;
    n1 = "Test message";
    cout << "n1: " << n1 << endl;

    string n2{"AUSDF BDSKJB DECAAC"};
    n1 = n2;
    cout << "n1: " << n1 << endl;

    /* 拼接 */
    string f1{"C++ = "};
    string f2{"TEEEEESSST"};
    string f3;

    f3 = f1 + f2;
    cout << "f3: " << f3 << endl;
}
```

我写不过来了＞︿＜
看我今年8月16日的cpp代码

---

### fstring 库

#### 创建文件

创建分手动和自动

##### 手动创建文件

手动创建就直接右键就行了

##### 自动创建文件

使用以下代码

```cpp
ofstream file("example.txt");
if (!file.is_open()) {
    cerr << "无法创建数据文件！" << endl;
    return 0;
}
file << 1234 << "|"  << endl;
// 关闭文件
file.close();
```

- `ofstream` 保存文件,若没有该文件则会自行创建该文件
使用方法 : `ofstream name("name.type")`

#### 读取

使用 `ifstream` 读取文件
使用方法: `ifstream name("name.type");`

示例代码

```cpp
ifstream file1("example.txt");
    
if (!file1.is_open()) {
    cerr << "未找到数据文件，需要创建新文件" << endl;
    return 1;
}
else{
    return 0;
}
```

> [WARNING]
> 该方法读取文件必须先创建该文件,否则无法读取

---

### vector 库

`vector` 是动态数组,大小可自动调整.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    vector<int> nums(n);   // 创建一个包含 10 个 0 的 vector

    cout << "empty(): " << nums.empty() << endl;   // 输出 0(false),因为不为空
    cout << "size(): " << nums.size() << endl;     // 输出 10

    nums.push_back(42);    // 尾部添加元素,size 变为 11
    cout << "after push_back, size = " << nums.size() << endl;

    return 0;
}
```

- `push_back()` 在数组尾部添加一个元素
- `empty()` 判断是否为空
- `size()` 返回元素个数

> **数组最大值应使用 `数组.size() -1` 来表示, 绝对不要使用 `max_size()` 来表示!!!!!!**

---

### chrono 时间库

- `system_clock` 一个结构体
- `time_t` 是 C/C++标准时间类型,表示从 `1970/1/1 00:00:00 UTC` 到现在的精确秒数;

#### 获取当前时间戳

获取的当前时间点精度为纳秒级别,获取后需转换

示例代码如下

方法一
<!--这个还好,44个字符,才3重套娃-->
```cpp
// auto是C++11的特性
// 本次示例不使用 using namespace 这种大忌霸
#include <iostream>
#include <chrono>
int main(){
    auto now = std::chrono::system_clock::now(); // 当前时间戳
}
```

方法二
<!--老™长了,90个字符,4+3重套娃,谁干na?!-->
```cpp
#include <iostream>
#include <chrono>
int main(){
    // 原始数据类型,C/C++可用
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
}
```

- `system_clock` 结构体,来自命名空间`std::chrono`,`system_clock::now()`获取时间
- `now()` 函数

> **`system_clock`不是命名空间,是结构体. `now()`是 `struct system_clock` 的一个静态函数**

#### 将`time_point`转换为`time_t`类型

示例代码如下

```cpp
std::time_t now_time = std::chrono::system_clock::to_time_t(now);
```

- `to_time_t` 函数,用于类型转换,会丢失`纳秒`/`微秒`精度,只保留`秒`级精度

#### 存储本地时间信息

主要使用`tm`这个结构体存储

原始结构体内定义了如下的内容,已翻译

```cpp
struct tm
{
    int tm_sec;   // 秒
    int tm_min;   // 0到59的分钟
    int tm_hour;  // 0到23的小时
    int tm_mday;  // 1到31月
    int tm_mon;   // 从一月到十二月,源代码定义的是从0到11月
    int tm_year;  // 从1900年开始
    int tm_wday;  // 星期一到星期天,源代码定义的是从 0到6
    int tm_yday;  // 一年的天数,0到365
    int tm_isdst; // 夏令时标志,这什么玩意???? *叹息*
};
```

- `tm_year`需要加 1990 才能显示正常年份
- `tm_mon`需要加 1,因为是从 0 开始

#### 输出当前时间

> **输出前请先获取当前时间戳,见上述** **本段代码只展示其核心内容**

##### Windows 平台

```cpp
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    tm timeinfo;

    localtime_s(&timeinfo, &now_time); // 注意这里

    cout << (timeinfo.tm_year + 1900) << "-"
         << (timeinfo.tm_mon + 1) << "-"
         << timeinfo.tm_mday << " "
         << timeinfo.tm_hour << ":"
         << timeinfo.tm_min << ":"
         << timeinfo.tm_sec << endl;
}
```

##### Linux 平台

```cpp
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    tm timeinfo;

    localtime_r(&now_time, &timeinfo);

    cout << (timeinfo.tm_year + 1900) << "-"
         << (timeinfo.tm_mon + 1) << "-"
         << timeinfo.tm_mday << " "
         << timeinfo.tm_hour << ":"
         << timeinfo.tm_min << ":"
         << timeinfo.tm_sec << endl;
}
```

在这段代码,Windows 和 Linux 主要区别是`localtime_`后面接的字母.
windows 是`s`,linux 是`r`

> [WARN] >**注意: 此代码输出的时间格式中,如果月份,日期,小时,分钟,秒是单位数,不会补零**
> 如需补零格式,需要添加`iomanip`头文件和`setw`/`setfill`格式化控制
