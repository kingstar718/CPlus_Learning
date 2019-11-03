#include <cstdio>

//
// Created by wujinxing on 2019/11/3.
// 二叉搜索树
//
typedef struct Node *Position;

typedef struct Node {
    int Data;
    struct Node *Left;
    struct Node *Right;
} BinTree;

Position Find(int X, BinTree BST) {
    if (!BST) return NULL;

    if(X > BST.Data){
        return Find(X, BST.Right);
    }
}