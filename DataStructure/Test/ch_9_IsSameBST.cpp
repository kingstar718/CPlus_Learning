//
// Created by wujinxing on 2019/11/4.
// 是否为同一颗二叉树
//
/**
 * 给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
 * 例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。
 *
 * 输入格式:
 * 输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。
 * 第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
 *
 * 简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。
 *
 * 输出格式:
 * 对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
 *
 * 输入样例:
 * 4 2
 * 3 1 4 2
 * 3 4 1 2
 * 3 2 4 1
 * 2 1
 * 2 1
 * 1 2
 * 0
 * 输出样例:
 * Yes
 * No
 * No
 */

/**
 * 1、建一棵树
 * 2、建搜索树
 * 3、判断一序列是否与搜索树一致
 */
#include <cstdio>
#include <cstdlib>

typedef struct TreeNode *Tree;
struct TreeNode {
    int v;
    Tree Left, Right;
    int flag; // 判别一个序列是否一致  被访问过的节点设为1 没有被访问过设为0
};

Tree MakeTree(int N);

Tree Insert(Tree T, int V);

int Judge(Tree T, int N);

Tree NewNode(int V);

void Reset(Tree T);

void FreeTree(Tree T);

// 程序有问题
int main() {
    int N, L, i;
    Tree T;
    scanf("%d", &N);
    //对每组数据
    // 读入N和L
    // 根据第一行序列建树T
    // 依据树T分别判断后面的L个序列是否能与T形成同一个搜索树并输出结果
    while (N) {
        scanf("%d", &L);
        T = MakeTree(N);
        for (i = 0; i < L; i++) {
            if (Judge(T, N))
                printf("Yes\n");
            else
                printf("No\n");
            Reset(T);
        }
        FreeTree(T);
        scanf("%d", &N);
    }
    return 0;
}

// 如何建搜索树
Tree MakeTree(int N) {
    Tree T;
    int i, V;

    scanf("%d", &V);
    T = NewNode(V);
    for (i = 0; i < N; ++i) {
        scanf("%d", &V);
        T = Insert(T, V);
    }
    return T;
}

Tree Insert(Tree T, int V) {
    if (!T) {
        T = NewNode(V); //T不存在就新建树
    } else {
        if (V > T->v) { //插入值大于当前就往右
            T->Right = Insert(T->Right, V);
        } else { // 小于就往左子树
            T->Left = Insert(T->Left, V);
        }
    }
    return T;
}

Tree NewNode(int V) {
    Tree T = (Tree) malloc(sizeof(struct TreeNode));
    T->v = V;
    T->Left = T->Right = NULL;
    T->flag = 0; //0表示节点未被访问
    return T;
}

/*
 * 如何判别
 * 构造 3 1 4 2的树T，在树T中搜索3 2 4 1中的每个数
 * > 如果每次搜索所经过的结点在前面均出现过，则一致
 * > 否则（某次搜索中遇到前面未出现的结点），则不一致
 */
int check(Tree T, int V) {
    if (T->flag) { //1表示点已被搜寻过
        if (V < T->v) {
            return check(T->Left, V);
        } else if (V > T->v) {
            return check(T->Right, V);
        } else {
            return 0;
        }
    } else {
        if (V == T->v) {
            T->flag = 1;
            return 1;
        } else {
            return 0;
        }
    }
}

int Judge(Tree T, int N) {
    int i, V, flag = 0; // flag代表树0一致，1代表已经不一致

    scanf("%d", &V);
    if (V != T->v) {
        flag = 1;
    } else {
        T->flag = 1;
    }
    for (i = 1; i < N; i++) {
        scanf("%d", &V);
        if ((!flag) && (!check(T, V))) {
            flag = 1;
        }
    }
    if (flag) {
        return 0;
    } else {
        return 1;
    }
}

void Reset(Tree T) {
    if (T->Left)
        Reset(T->Left);
    if (T->Right)
        Reset(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T) {
    if (T->Left)
        FreeTree(T->Left);
    if (T->Right)
        FreeTree(T->Right);
    free(T);
}