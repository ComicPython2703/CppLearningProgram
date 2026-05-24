#include <iostream>
#include <queue> // 层序遍历需要队列
using namespace std;

// 1. 定义二叉树节点结构（教学版：仅存整型数据）
struct TreeNode {
    int val;         // 节点值
    TreeNode* left;  // 左孩子指针
    TreeNode* right; // 右孩子指针

    // 构造函数：初始化节点
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// 2. 二叉树核心操作类（封装所有功能，便于教学演示）
class BinaryTree {
private:
    TreeNode* root; // 二叉树根节点（整个树的入口）

    // 【递归遍历】前序遍历（根 → 左 → 右）：私有函数，供外部接口调用
    void preOrderTraversal(TreeNode* node) {
        if (node == nullptr) return; // 递归终止条件：空节点
        cout << node->val << " ";    // 1. 访问根节点
        preOrderTraversal(node->left); // 2. 遍历左子树
        preOrderTraversal(node->right); // 3. 遍历右子树
    }

    //// 【递归遍历】中序遍历（左 → 根 → 右）
    //void inOrderTraversal(TreeNode* node) {
    //    if (node == nullptr) return;
    //    inOrderTraversal(node->left);  // 1. 遍历左子树
    //    cout << node->val << " ";      // 2. 访问根节点
    //    inOrderTraversal(node->right); // 3. 遍历右子树
    //}

    //// 【递归遍历】后序遍历（左 → 右 → 根）
    //void postOrderTraversal(TreeNode* node) {
    //    if (node == nullptr) return;
    //    postOrderTraversal(node->left);  // 1. 遍历左子树
    //    postOrderTraversal(node->right); // 2. 遍历右子树
    //    cout << node->val << " ";        // 3. 访问根节点
    //}

    // 递归插入节点（二叉搜索树规则：左小右大）
    TreeNode* insertNode(TreeNode* node, int val) {
        if (node == nullptr) { // 空位置就是插入点
            return new TreeNode(val);
        }
        // 二叉搜索树规则：小于根节点插左子树，大于插右子树
        if (val < node->val) {
            node->left = insertNode(node->left, val);
        }
        else if (val > node->val) {
            node->right = insertNode(node->right, val);
        }
        // 等于的情况：不插入（避免重复值）
        return node;
    }

    // 递归查找节点
    bool findNode(TreeNode* node, int val) {
        if (node == nullptr) return false; // 没找到
        if (node->val == val) return true; // 找到
        // 按二叉搜索树规则查找：小则左，大则右
        return val < node->val ? findNode(node->left, val) : findNode(node->right, val);
    }

    // 递归释放所有节点内存（后序遍历释放：先删孩子，再删根）
    void destroyTree(TreeNode* node) {
        if (node == nullptr) return;
        destroyTree(node->left);  // 释放左子树
        destroyTree(node->right); // 释放右子树
        delete node;              // 释放当前节点
    }

public:
    // 构造函数：初始化空树
    BinaryTree() : root(nullptr) {}

    // 析构函数：释放整棵树的内存
    ~BinaryTree() {
        destroyTree(root);
    }

    // 外部接口：前序遍历
    void preOrder() {
        cout << "前序遍历：";
        preOrderTraversal(root);
        cout << endl;
    }

    //// 外部接口：中序遍历
    //void inOrder() {
    //    cout << "中序遍历：";
    //    inOrderTraversal(root);
    //    cout << endl;
    //}

    //// 外部接口：后序遍历
    //void postOrder() {
    //    cout << "后序遍历：";
    //    postOrderTraversal(root);
    //    cout << endl;
    //}

    //// 外部接口：层序遍历（广度优先，非递归，用队列）
    //void levelOrder() {
    //    cout << "层序遍历：";
    //    if (root == nullptr) {
    //        cout << "空树" << endl;
    //        return;
    //    }
    //    queue<TreeNode*> q; // 队列存节点指针，按层存储
    //    q.push(root);       // 根节点入队

    //    while (!q.empty()) {
    //        TreeNode* curr = q.front(); // 取队头节点
    //        q.pop();                    // 出队
    //        cout << curr->val << " ";   // 访问当前节点

    //        // 左孩子非空则入队
    //        if (curr->left != nullptr) q.push(curr->left);
    //        // 右孩子非空则入队
    //        if (curr->right != nullptr) q.push(curr->right);
    //    }
    //    cout << endl;
    //}

    // 外部接口：插入节点（封装递归逻辑）
    void insert(int val) {
        root = insertNode(root, val);
        cout << "插入值 " << val << " 成功" << endl;
    }

    // 外部接口：查找节点
    bool find(int val) {
        bool result = findNode(root, val);
        if (result) {
            cout << "值 " << val << " 存在于树中" << endl;
        }
        else {
            cout << "值 " << val << " 不存在于树中" << endl;
        }
        return result;
    }
};

// 3. 教学演示主函数
int main() {
    // 步骤1：创建空二叉树
    BinaryTree bt;

    // 步骤2：插入节点（构建二叉搜索树）
    // 构建的树结构：
    //        8
    //       / \
    //      4   10
    //     / \    \
    //    2   6    12
    bt.insert(8);
    bt.insert(4);
    bt.insert(10);
    bt.insert(2);
    bt.insert(6);
    bt.insert(12);

    // 步骤3：各种遍历演示（核心教学点）
    bt.preOrder();   // 预期：8 4 2 6 10 12  前序遍历
    //bt.inOrder();    // 预期：2 4 6 8 10 12 （二叉搜索树中序遍历是升序） 中序遍历
    //bt.postOrder();  // 预期：2 6 4 12 10 8  后序遍历
    //bt.levelOrder(); // 预期：8 4 10 2 6 12  层序遍历（广度优先，非递归，用队列）

    // 步骤4：查找节点演示
    bt.find(6);  // 存在
    bt.find(9);  // 不存在

    return 0;
}



