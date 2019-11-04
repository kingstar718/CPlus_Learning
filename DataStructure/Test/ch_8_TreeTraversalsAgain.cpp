//
// Created by wujinxing on 2019/11/4.
//
/**
 * 有序二叉树遍历可以通过堆栈以非递归方式实现例如，
 * 假设遍历6节点二叉树（键的编号从1到6）时，堆栈操作为：
 * push（1）；push（2）；push（3）；pop（）；pop（）；push（4）；pop（）；pop（）；push（5）；push（6）；pop（）；pop（）
 * 然后，可以从这个操作序列生成一个唯一的二叉树（如图1所示）你的任务是给出这个树的后序遍历序列。
 *           1
 *          / \
 *         2    5
 *       / \   /
 *      3  5  6
 * 输入规格：
 * 每个输入文件包含一个测试用例。对于每种情况，第一行包含一个正整数n（≤30），它是树中节点的总数（因此节点的编号从1到n）。
 * 接下来是2n行，每行描述一个堆栈操作，格式为：“push x”，其中x是被推送到堆栈上的节点的索引；或“pop”，意思是从堆栈中弹出一个节点。
 *
 * 输出规格：
 * 对于每个测试用例，在一行中打印对应树的后序遍历序列保证存在一个解决方案。所有数字必须用一个空格隔开，并且行的末尾不能有多余的空格。
 *
 * 6
 * Push 1
 * Push 2
 * Push 3
 * Pop
 * Pop
 * Push 4
 * Pop
 * Pop
 * Push 5
 * Push 6
 * Pop
 * Pop
 * Sample Output:
 * 3 4 2 6 5 1
 */

#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode {
    string data;
    Tree left;
    Tree right;
};

Tree create() {
    Tree T;
    T = (Tree) malloc(sizeof(struct TreeNode));
    T->left = NULL;
    T->right = NULL;
    return T;
}

// 中序遍历整理树
Tree rebuild(Tree T) {
    int n;
    string str;
    stack<Tree> s;
    Tree node = T;
    bool flag = false;
    string value;
    scanf("%d\n", &n);
    //根节点赋值
    getline(cin, str);
    value = str.substr(5); //从第5个开始截取
    node->data = value;
    //根节点入栈
    s.push(node);
    for (int i = 1; i < 2 * n; i++) {
        getline(cin, str);
        if (str == "Pop") {
            node = s.top();
            s.pop();
        } else {
            value = str.substr(5);
            Tree tmp = create();
            tmp->data = value;
            if (!node->left) {
                node->left = tmp;
                node = node->left;
            } else if (!node->right) {
                node->right = tmp;
                node = node->right;
            }
            s.push(tmp);
        }
    }
    return T;
}

// 后序遍历递归
void bl(Tree T, bool &flag) {
    if (T) {
        bl(T->left, flag);
        bl(T->right, flag);
        if (!flag) {
            flag = true;
        } else {
            cout << " ";
        }
        cout << T->data;
    }
}

int main() {
    Tree T;
    bool flag = false;
    string str;
    T = create();
    T = rebuild(T);
    bl(T, flag);
    return 0;
}

