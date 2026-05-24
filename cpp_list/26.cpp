// 内存碎片问题--解决方案 jemalloc/tcmalloc 现有库

// 注意：
// 只有当业务场景是 “频繁创建 / 销毁同尺寸小对象”，且性能 / 内存碎片成为瓶颈时,
// 手写定长内存池才有价值;否则优先使用系统new/delete或 STL 容器，降低开发和维护成本。

// 频繁申请/释放内存的核心后果:
// 1. 内存碎片
//    - 外部碎片:堆区总空闲内存充足，但被分割成零散小块，无法申请大块连续内存；
        // 系统内的内存,尚未分配给任何进程
//    - 内部碎片:分配器按固定粒度（如8/16字节）分配，小内存频繁申请导致大量"边角料"空间浪费。进程占内存虚高
        // 已分配给当前进程,但内部还未申请使用 
// 2. 性能抖动
//    - 分配时:系统堆管理器需频繁遍历空闲块列表，寻找匹配内存块；
//    - 释放时:堆管理器需遍历空闲块，尝试合并相邻空闲块（减少碎片但耗时）；
//    - 系统调用:内存操作触发用户态→内核态切换，切换本身存在固定性能开销。

// 场景影响:
//    短运行程序（如小工具）:影响可忽略；
//    长运行/高并发程序（服务器、游戏引擎）:损耗持续放大，表现为响应慢、CPU高、偶发卡顿。

// 解决方案:
//    1. 内存池/对象池:批量申请大块内存，内部复用，统一释放（核心方案）；
//    2. 善用标准库:如C++的vector/string（连续内存、自动扩容）替代零散指针；
//    3. 移动语义（C++11+）:减少深拷贝，避免不必要的内存申请/释放；
//    4. 优先栈内存:短生命周期、小内存优先用栈（分配/释放由编译器管理，无系统开销）。


// 内存池: 预先分配大块内存并自行管理,提高小对象的分配性能
// 1、减少系统调用
// 2、提高内存利用率
// 3、提高缓存命中率



// 手写定长内存池
#include <iostream>  
#include <vector>   

// 内存对齐 向上
static inline std::size_t align_up(std::size_t n, std::size_t align) {
    return (n + (align - 1)) & ~(align - 1);
}

class FixedSizePool {
public:
    // 构造函数
    explicit FixedSizePool(std::size_t block_size, std::size_t blocks_per_page = 1024) {
        // 初始化
        blocks_per_page_ = blocks_per_page;                     // 每一页的块数
        block_size_ = adjust_block_size(block_size);            // 调整块大小（对齐+最小尺寸）
        free_list_ = nullptr;                                   // 初始空闲链表为空
    }

    // 析构函数
    ~FixedSizePool() {
        for(void* p :pages){
            ::operator delete[](p);  // 释放每一页的内存（对应expand里的operator new[]）
        }
    }

    // 页 切分 小内存 函数
    void* allocate() {
        // 若链表为空,则申请新页
        if (!free_list_) {
            expand();
        }
        // 将链表的头节点拿出
        Node* head = free_list_;
        free_list_ = head->next;
        return head;
    }


    // 小内存 归还
    void deallocate(void* p){
        // 回收节点大小若为空,则结束
        if (!p) return ;
        // 把回收的内存块转成Node类型（因为块大小足够存Node）
        Node* node = static_cast<Node*>(p);
        // 链表头插：把回收的块插到空闲链表头部（效率O(1)）
        node->next = free_list_;
        free_list_ = node;

    }


    // 访问 每一小块的内存大小
    std::size_t block_size() const { return block_size_; }
    // 访问 小块的内存的数量
    std::size_t blocks_per_page() const { return blocks_per_page_; }

private:
    // 链表的节点 实际上是指针 为保证内存的最小分配要等于指针的大小
    std::size_t adjust_block_size(std::size_t s) {
        std::size_t min = sizeof(void*);     // 最小块大小=指针大小（因为Node要存指针）
        std::size_t a = s < min ? min : s;   // 保证块大小不小于指针大小
        return align_up(a, alignof(void*));  // 对齐到指针大小的整数倍 
    }

    // 每次向系统申请一页的内存，并把这一页的内存切为很多小块，并把这些小块挂到空闲链表中
    void expand(){
    // 计算一页的总字节数：块大小 × 每页数
    std::size_t page_bytes = block_size_ * blocks_per_page_;
    // 向系统申请一页内存（数组版new，对应析构的delete[]）
    char* page = static_cast<char*>(::operator new[](page_bytes));
    pages.push_back(page); // 记录该页地址，用于析构释放

    // 把一页内存切分成blocks_per_page_个小块，挂到空闲链表
    for (std::size_t i = 0; i < blocks_per_page_; i++) {
        // 计算第i个块的起始地址：页起始 + i×块大小
        char* addr = page + i * block_size_;
        // 转成Node类型（块大小足够存Node）
        Node* n = reinterpret_cast<Node*>(addr);
        // 头插法挂到空闲链表
        n->next = free_list_;
        free_list_ = n;
    }
}

    // 单链表 每个节点-空闲小块内存
    struct Node{Node* next;};

    // 设定 每一小块的内存大小
    std::size_t block_size_;
    // 设定 空闲小块内存的数量
    std::size_t blocks_per_page_;

    Node* free_list_;  // 空闲小块内存 单链表 头节点
    // 多个页的容器 析构统一释放
    std::vector<void*> pages;
};


// ----------------------------------------------------应用 重写 new delete 就可以使用内存池
// 任意创建的对象
struct Particle
{
    float x, y, z;
    int life;

    // 重点: 重写类专属的new/delete（静态成员函数）
    static void* operator new(std::size_t n);
    static void operator delete(void* p) noexcept;

    void update() { ++life; }
};

// 全局静态内存池: 为 Particle 对象分配，块大小=Particle大小，每页4096块
static FixedSizePool g_article_pool(sizeof(Particle), 4096);

// 重点: 实现new：从内存池分配内存
void* Particle::operator new(std::size_t n) {
    // 申请小块内存
    return g_article_pool.allocate();
}
// 重点: 实现delete: 把内存归还给内存池
void Particle::operator delete(void* p) noexcept {
    // 回收小块内存
    g_article_pool.deallocate(p);
}


// 测试
int main() {
    // 初始化 vector 容器
    std::vector<Particle*> vec;
    // 提前扩容
    vec.reserve(10000);

    for (int i = 0; i < 10000; i++) {
        // 实例化对象 申请内存
        Particle* p = new Particle{0, 0, 0, 0};
        // 放入容器
        vec.push_back(p);
    }

    // ... 业务逻辑

    // 将内存池内的内存释放
    for (auto* p : vec) {
        delete p;
    };

    // 查看 小内存块大小 小内存块数量
    std::cout << "BlockSize = " << g_article_pool.block_size()
              << ", BlocksPerPage= " << g_article_pool.blocks_per_page() << std::endl;

    return 0;
}