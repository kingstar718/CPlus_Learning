//
// Created by wujinxing on 2019/11/3.
// 二叉搜索树操作集
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); //先序遍历
void InorderTraversal(BinTree BT); //后序遍历

BinTree Insert(BinTree BST, ElementType X);

BinTree Delete(BinTree BST, ElementType X);

Position Find(BinTree BST, ElementType X);

Position FindMin(BinTree BST);

Position FindMax(BinTree BST);

int main() {
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;
    BST = NULL;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
}