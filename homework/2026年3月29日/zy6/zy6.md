# ZY6.md

## 分配内存

### 1. 声明局部变量

最基本的栈分配方式。例如：

```cpp
int a;               // 4字节（int大小）
double arr[100];     // 800字节（double[100]）
MyClass obj;         // 对象在栈上构造
```

## 危险操作

### 1.栈溢出

```cpp
void dangerous() {
    char huge[10000000];   // 10MB，超过默认栈大小 → 崩溃
}

void recursion(int depth) {
    char buf[1024];
    recursion(depth + 1);  // 无限递归 → 栈溢出
}
```

### 2.空(是这么叫的吧)

```cpp
int* bad() {
    int local = 42;
    return &local;   // 危险：返回栈地址
}
```

### 3.缓冲区溢出

```cpp
void vulnerable(char* input) {
    char buffer[16];
    strcpy(buffer, input);   // 若 input 长度 > 15，溢出
}
```
