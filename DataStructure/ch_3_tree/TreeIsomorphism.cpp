//
// Created by wujinxing on 2019/11/2.
// 树的同构
//
#include <cstdio>
#include <cstdlib>

// 静态链表表示树
#define MaxTree 10;
#define ElementType char;
#define Tree int;
#define Null -1;

int BuildTree(struct TreeNode T[]);

int Isomorphic(int R1, int R2);

struct TreeNode {
    char Element;
    int Left;
    int Right;
} T1[10], T2[10];

int main() {
    int R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

int BuildTree(struct TreeNode T[]) {
    int N;
    int Isnode[10] = {0};
    char cl, cr; //输入有’-‘，先用char暂存，在放入结构里
    scanf("%d\n", &N);
    if (N) {
        for (int i = 0; i < N; ++i) {
            scanf("%c %c %c", &T[i].Element, &cl, &cr);
            if (cl != '-') {
                T[i].Left = cl - '0';
                Isnode[T[i].Left] = 1;
            } else {
                T[i].Left = NULL;
            }
            if (cr != '-') {
                T[i].Right = cl - '0';
                Isnode[T[i].Right] = 1;
            } else {
                T[i].Right = NULL;
            }
        }
        for (int j = 0; j < N; ++j) {
            if (!Isnode[j])
                return j;
        }
    }
    return Null;
}

//下面来判断是否为同构
//都为空树，直接返回1；一个空一个不空，直接返回0
//都不空：结点不同，直接0；结点相同，再看子树
//左子树同不存在，就递归调用右子树
//左子树存在，看是否相等，不相等就交换左右子树，再递归调用
int Isomorphic(int R1, int R2) {
    if (R1 == NULL && R2 == NULL) {
        return 1;
    }
    if ((R1 == NULL && R2 != NULL) || (R1 != NULL && R2 == NULL)) {
        return 0;
    }
    if (T1[R1].Element != T2[R2].Element) {
        return 0;
    }
    if (T1[R1].Left == NULL && T2[R2].Left == NULL) {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
    if (((T1[R1].Left != NULL) && (T2[R2].Left != NULL)) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element))) {
        return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
    } else{
        return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);
    }
}