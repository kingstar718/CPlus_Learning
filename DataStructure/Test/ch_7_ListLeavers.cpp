//
// Created by wujinxing on 2019/11/3.
//
/*
 * 给定一棵树，您应该按照从上到下，从左到右的顺序列出所有叶子。
 * 输入规范：每个输入文件包含一个测试用例。对于每种情况，第一行给出一个正整数N（≤10），它是树中节点的总数-因此，节点的编号从0到N-1。
 * 然后，紧接着N行，每行对应一个节点，并给出该节点的左，右子级的索引。如果孩子不存在，将在该位置放置“-”。任何一对孩子都用空格隔开。
 * 输出规范：对于每个测试用例，按从上到下，从左到右的顺序在一行中打印所有叶子的索引。相邻数字之间必须恰好有一个空格，行尾不得有多余的空格。
 * 样本输入：8 1-0 2 7--5 4 6
 * 样本输出：4 1 5
 */

#include <cstdio>
#include <cctype>

#define N 10;

typedef struct Node {
    int data, left, right;
} TreeNode;

TreeNode node[10];
TreeNode Queue[10];

int first = -1, last = -1;

void Push(TreeNode tn);

TreeNode Pop();

void printLeavers(int root, int n);

int charToInt(char ch);

int main() {
    int n;
    bool isRoot[10];
    int root = 0;

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        isRoot[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        char cLeft, cRight;
        scanf("%c %c", &cLeft, &cRight);
        getchar(); //读取缓存区的回车符
        node[i].left = charToInt(cLeft);
        node[i].right = charToInt(cRight);
        node[i].data = i;
        if (node[i].left != -1)
            isRoot[node[i].left] = 0;
        if (node[i].right != -1)
            isRoot[node[i].right] = 0;
    }
    //找到根节点
    for (int i = 0; i < n; i++) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }
    printLeavers(root, n);
    return 0;
}

void Push(TreeNode treeNode) {

    Queue[++last] = treeNode;
}

TreeNode Pop() {
    return Queue[++first];
}

//层次遍历打印树节点，队列实现
void printLeavers(int root, int n) {
    int leaves[10];
    int k = 0;
    Push(node[root]);
    for (int i = 0; i < n; ++i) {
        TreeNode tn = Pop();
        //左孩子和右孩子都不存在时，将叶节点的值保存到数组中，便于格式化打印
        if (tn.left == -1 && tn.right == -1) {
            leaves[k++] = tn.data;
        }
        if (tn.left != -1) {
            Push(node[tn.left]);
        }
        if (tn.right != -1) {
            Push(node[tn.right]);
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        printf("%d ", leaves[i]);
    }
    printf("%d\n", leaves[k - 1]);
}

int charToInt(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    } else {
        return -1;
    }
}