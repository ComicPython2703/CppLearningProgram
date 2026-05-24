#include <iostream>
using namespace std;

const int MAX = 5;          // 队列最大容量
int queueArray[MAX];        // 数组实现队列
int frontIndex = 0;         // 队头指针
int rearIndex = 0;          // 队尾指针
int currentSize = 0;        // 当前队列大小

// 取余 3 % 5 = 3  3除5除不了,直接就将3作为余数返回了


// 入队函数
bool enqueue(int value) {
    if (currentSize >= MAX) {
        cout << "队列已满，无法入队 " << value << endl;
        return false;
    }
    queueArray[rearIndex] = value;
    rearIndex = (rearIndex + 1) % MAX;  // 循环
    currentSize++;
    cout << "入队成功: " << value << endl;
    return true;
}

// 出队函数
bool dequeue() {
    if (currentSize <= 0) {
        cout << "队列为空，无法出队" << endl;
        return false;
    }
    int value = queueArray[frontIndex];
    frontIndex = (frontIndex + 1) % MAX;
    currentSize--;
    cout << "出队元素: " << value << endl;
    return true;
}

// 获取队头元素
int getFront() {
    if (currentSize <= 0) {
        cout << "队列为空" << endl;
        return -1;
    }
    return queueArray[frontIndex];
}

// 打印队列内容
void printQueue() {
    if (currentSize == 0) {
        cout << "队列为空" << endl;
        return;
    }
    cout << "队列内容（从前到后）: ";
    for (int i = 0; i < currentSize; i++) {
        int idx = (frontIndex + i) % MAX;
        cout << queueArray[idx] << " ";
    }
    cout << "  [front=" << frontIndex << ", rear=" << rearIndex
        << ", size=" << currentSize << "/" << MAX << "]" << endl;
}

// 清空队列
void clearQueue() {
    frontIndex = rearIndex = currentSize = 0;
    cout << "队列已清空" << endl;
}

int main() {
    cout << "=== 队列操作演示 ===" << endl;

    // 1. 入队
    cout << "\n1. 入队 10, 20, 30:" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue();

    // 2. 查看队头
    cout << "\n当前队头: " << getFront() << endl;

    // 3. 出队
    cout << "\n2. 出队一个元素:" << endl;
    dequeue();
    printQueue();

    // 4. 继续入队测试循环
    cout << "\n3. 继续入队 40, 50, 60, 70:" << endl;
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);  // 这个会失败，队列已满
    printQueue();

    // 5. 出队两次后再入队
    cout << "\n4. 出队两次后再入队 80:" << endl;
    dequeue();
    dequeue();
    enqueue(80);
    printQueue();



    //内存局部性好
    //数组连续存储，CPU缓存友好

    //访问模式可预测，预取效率高
    //CPU观察访问模式：
    //1. 顺序模式（数组）：每次 + 4字节
    //→ 预取下一缓存行
    //2. 跨步模式（每隔N个）：每次 + N * 4字节
    //→ 预取下N个缓存行
    //3. 随机模式（链表）：地址无规律
    //→ 无法预取，每次缓存不命中

    return 0;
}