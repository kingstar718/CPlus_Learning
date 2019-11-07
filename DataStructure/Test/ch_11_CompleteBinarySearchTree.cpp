//
// Created by wujinxing on 2019/11/7.
// 完全二叉搜索树
//
/**
 * 二进制搜索树（BST）递归地定义为具有以下属性的二进制树：
 * 节点的左子树只包含键小于节点键的节点。
 * 节点的右子树仅包含键大于或等于节点键的节点。
 * 左子树和右子树也必须是二进制搜索树。
 * 完整的二叉树（CBT）是一个完全填充的树，但底层可能例外，它是从左到右填充的。
 * 现在给定一系列不同的非负整数键，如果要求树也必须是CBT，则可以构造唯一的BST您应该输出这个BST的水平顺序遍历序列。
 *
 * 输入规格：
 * 每个输入文件包含一个测试用例对于每种情况，第一行包含一个正整数N（≤1000）然后在下一行给出N个不同的非负整数键一行中所有数字用空格隔开，且不大于2000。
 * 输出规格：
 * 对于每个测试用例，在一行中打印对应的完整二进制搜索树的级别顺序遍历序列一行中的所有数字都必须用空格隔开，并且行的末尾不能有多余的空格。
 *
 * Sample Input:
 * 10
 * 1 2 3 4 5 6 7 8 9 0
 * Sample Output:
 * 6 3 8 1 5 7 9 0 2 4
 */
#include <iostream>
#include <algorithm>
#include <cmath>

#define MaxSize 2005
int value[MaxSize];
int BST[MaxSize];

// 计算n个结点的树其左子树结点个数
int getLeftLength(int n) {
    int h = 0; // 保存该结点下满二叉树的层数
    int tmp = n + 1;
    while (tmp != 1) {
        tmp /= 2;
        h++;
    }
    int x = n - pow(2, h) + 1; // 最下面一排子叶结点的个数
    x = x < pow(2, h - 1) ? x : pow(2, h - 1); // 子叶结点最多为2^(h-1)
    int L = pow(2, h - 1) - 1 + x; // 该结点个数情况下左子树的个数
    return L;
}


void solve(int left, int right, int root) {

    int n = right - left + 1;
    if (n == 0) return;

    int L = getLeftLength(n); // 计算出n个结点的树其左子树有多少个结点
    BST[root] = value[left + L]; // 根节点的位置是 左边界偏移量
    int leftRoot = 2 * root + 1; // 左儿子接到位置，从0开始
    int rightRoot = leftRoot + 1; // 右儿子结点位置
    solve(left, left + L - 1, leftRoot); // 左子树递归
    solve(left + L + 1, right, rightRoot); // 右子树递归
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> value[i];
    }
    // 小到大排序
    std::sort(value, value + n);
    solve(0, n - 1, 0);
    for (int i = 0; i < n; ++i) {
        if (i)
            std::cout << " ";
        std::cout << BST[i];
    }
    return 0;
}