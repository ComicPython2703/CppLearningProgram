# 本目录笔记

---

## 基本

---

- `//` 单行注释
- `/* */` 多行注释
- `#include` 导入库
- `cout` 输出流，`<<` 输出操作符
- `endl` 换行（可选）
- `int` 定义整数
- `'` 字符
- `"` 字符串
- `;` 非最后一行的代码必须加此符号

> 重要 必须区分它们，否则会出现 [warning] character constant too long for its type

```python
# 示例 python 代码 ,和 C++ 对比可以发现C++要复杂许多
if __name__ == '__main__':
    print("Hello Wold")
```

```cpp
// example cpp code
#include <iostream>  // 导入 <iostream> 库
using namespace std; // 使用命名空间 std
int main(void)       // 定义主程序 必须是main,void为空值 可写可不写
{
    // cout 为输出, `<<` 后面必须接字符串或是定义过的名字,endl为换行,可写可不写
    cout << "Hello World" << endl;
    return 0;         // 返回0,可写可不写
}
```

- `#include <iostream>` 声明头文件 iostream，标准的输入输出
- `using namespace std;` 使用标准命名空间；main 函数前的返回类型根据函数返回值确定
- `int main(void)` //主函数

---

## 运算

---

### 基本运算

- `+` 加法运算
- `-` 减法运算
- `*` 乘法运算,相当于 Python 的 `x`
- `/` 取整除法运算
- `%` 取余除法运算

> 除法运算需区分整数和浮点数

---

### `i++`和 `++i` 的区别

示例代码如下

#### Python

```python
if __name__ == "__main__":
    i = 10 # Python 无需 int()
    k = 10
    
    a = i + 1
    b = k + 1
    
    print("i++后的a = ",a) # i++后的a =  11
    print("++k后的b = ",b) # ++k后的b =  11
    print("i++后的i = ",i) # i++后的i =  10
    print("++k后的k = ",k) # ++k后的k =  10
```

#### C++

```cpp
#include <iostream>
using namespace std;
int main(void){
    int i = 10;
    int k = 10;

    int a = i++;
    int b = k++;
    cout << "i++后的a = " << a << endl;
    cout << "++k后的b = " << b << endl;
    cout << "i++后的i = " << i << endl;
    cout << "++k后的k = " << k << endl;
    /* i++后的a = 10
      ++k后的b = 10
      i++后的i = 11
      ++k后的k = 11
    */
}
```

- `i++` 和`i--` 都是 先 **赋值** 后 **运算**
- `++i` 和`--i` 都是 先 **运算** 后 **赋值**

---

## 判断

- `!` 取反, `true` 为 `false` , `false` 为 `true`,相当于 Python 中的 `not`
- `&&` 与,代表相同,**必须全部为真**,相当于 Python 中的 `and`
- `||` 或,其中一个的意思,相当于 Python 中的 `or`

> `&&`必须全都为真才为真
> `0`和`false`为假,其余为真
> `||` 必须至少有一个为真

### 优先级

- `!` > `&&` > `||`

---

## 数值类型

- `int`
- `float`
- `char` 字符型

> `cahr` 只能用 `'` ,不能用`"`,只能用 `字符` 而不是 `字符串`

- `bool` 布尔值,用于判断真假,`true` 为 `1` , `false` 为 `0`

---

## 三目运算符

**示例**: `(a>b ? a:b)`

- `?` 判断
- `:` 输出,为真时即输出 左边 的, 为假时即输出 右边 的

> `cout` 里面必须必须把这个运算符放到 `()` 否则报错

---

## Switch 语句

- `default` 默认,所有 `case` 之都不匹配才会执行此内容
- `case` 匹配值,匹配成功后才会执行里面的代码
- `break` 打破, `case` 里面的代码完后使用**此代码**可阻止 `switch` 的剩余代码运行

> **`switch` 括号里面的是 值 ,并且 `case` 必须为一个 值 ,相当于 `if` 里面的 `==`**
> ‏
> **`case`里面的代码执行完成后必须使用 `break;` 语句,否则会继续执行后面的代码**

示例代码如下

```cpp
#include <iostream>
using namespace std;

int main(void){
    char examp;
    cin >> examp;
    switch(examp){
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
            cout << "示例四"
    }
}
```

---

## 循环

### while 循环

- `while` 循环 语法如下

> `while (条件) {代码}`

当条件为真时,`while`里面的代码才会执行

---

### for 循环

-`for` 循环
示例代码如下

```cpp
#include <iostream>
using namespace std;

int main(void)
{
    for(int i = 1;i < 200 ;i++;)
        {
            cout << i << "";
        }
}
```

- `int i = 1;` 初试值 **可视为起点**
- `i < 100;` 循环条件 **可视为终点**
- `i++` 增量表达式
  > `size_t` 为无符号整数,建议使用 `int` 作为替代

---

## 数组

---

### 数组基础概念

定义 :: 相同数据类型的元素组成的集合

示例: `int array[5] = {1,2,3,4,5}` `cout << array[4]`

- `int` 定义该数组的类型, 所有的`数据类型`皆可使用
- `array` 该数组的名称
- `[<int>]` 定义数组的长度
- `{1,2,3,4,5}` 数组元素

```txt
      下标定义如下
      {1 , 2 , 3 , 4 , 5 , 6 , 7 }
       0   1   2   3   4   5   6
```

> **数组类型不可使用`C++保留关键字`**
>
> **数组元素长度不可超出 `name[<length>]` 所定义的长度**

---

### 输出

示例代码如下

```cpp
/* 有 vector 库 */
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n = 10; // 初始化 n 的值为 10
    vector<int> n;

    for (int i = 0; i < n.size(); i++)
    {
        cout << "数组内容: " << n[i] << " ";
    }
}
```

---

### 查找

先定义数组再查找

示例代码如下

`int arrange[10] = {1,2,3,4,5,6,7,8,9,10};`

`cout << arrange[6];`

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

## C++关键字

- `const` 只读变量,代表后续不可更改
- `?`

---

## 指针

### 基础概念

- 指针是存储变量地址的变量
- `int *ptr` 定义指针
- `&var` 取变量地址
- `*ptr` 解引用，访问指针指向的值

```cpp
#include <iostream>
using namespace std;
int main(){
    // 指针 数组
    const int MAX_01 = 3; // 定义 max 最大值
    int  var_03[MAX_01] = {10, 100, 200}; // 定义数组 var03
    int *ptr_03[MAX_01]; // 

    for (int i = 0; i < MAX_01; i++)
    {
        ptr_03[i] = &var_03[i]; // 赋值为整数的地址
    }
    for (int i = 0; i < MAX_01; i++)
    {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr_03[i] << endl;
    }
}
```

---

## _C++ 内置库_

---

### string 库

示例代码如下

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
   /* 基础 */

    string s1;             //空字符串
    string s2{"hello"};    //列表初始化
    string s3{s2};         //拷贝初始化
    string s4{"hello", 4}; //限制字符串长度为4
    string s5{s2, 1, 3};   //复制s2的 1~3
    //no_code           //5个x

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

---

### vector 库

示例代码如下

```cpp
#include <vector>
using namespace std;

int main(void){
    int n = 10; // 初始化 n 的值为 10
    vector<int> nums(n);

    cout << "输出0 (false):" << nums.empty() << endl;


}
```

- `push_back()` 数组尾部添加一个元素

---
