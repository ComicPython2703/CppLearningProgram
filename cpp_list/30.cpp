#include <iostream>
using namespace std;

// 极简栈类：固定大小，无扩容，只保留核心功能
class SimpleStack {
private:
    int arr[5];  // 静态数组，固定容量5
    int topIdx;  // 栈顶索引：-1=空栈，0~4=栈顶位置

public:
    // 构造函数：初始化空栈
    SimpleStack() {
        topIdx = -1; // 初始栈空
    }

    // 1. 入栈（压栈）：只能从栈顶加元素
    void push(int value) {
        // 检查栈是否已满（栈顶索引到数组最后一位）
        if (topIdx == 4) { // 数组大小5，索引0~4
            cout << "栈满！无法入栈：" << value << endl;
            return;
        }
        topIdx++;          // 栈顶索引上移
        arr[topIdx] = value; // 元素放入栈顶
        cout << "入栈：" << value << endl;
    }

    // 2. 出栈（弹栈）：只能从栈顶删元素
    void pop() {
        // 检查栈是否为空
        if (topIdx == -1) {
            cout << "栈空！无法出栈" << endl;
            return;
        }
        cout << "出栈：" << arr[topIdx] << endl;
        topIdx--; // 栈顶索引下移（逻辑删除，无需清空数据）
    }

    // 3. 查看栈顶元素（不删除）
    void peek() {
        if (topIdx == -1) {
            cout << "栈空！无栈顶元素" << endl;
            return;
        }
        cout << "栈顶元素：" << arr[topIdx] << endl;
    }
};

// 测试极简栈
int main() {
    SimpleStack stack;

    // 入栈测试（超过5个会提示栈满）
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6); // 栈满，无法入栈

    // 查看栈顶
    stack.peek(); // 输出5

    // 出栈测试（清空后再出栈会提示栈空）
    stack.pop(); // 5
    stack.pop(); // 4
    stack.pop(); // 3
    stack.pop(); // 2
    stack.pop(); // 1
    stack.pop(); // 栈空

    return 0;
}