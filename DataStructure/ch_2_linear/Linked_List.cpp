//
// Created by wujinxing on 2019/10/30.
// 线性表的链式存储实现
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

//typedef int Position;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

/* 查找 */
Position Find(List L, ElementType X) {
    Position p = L; // p指向L的第1个节点

    while (p && p->Data != X)
        p = p->Next;

    return p;
}

bool Insert(List L, ElementType X, Position P) {
    Position tmp, pre;

    // 查找p的前一个节点
    for (pre = L; pre && pre->Next != P; pre = pre->Next);

    if (pre == NULL) {
        printf("插入位置参数错误");
        return false;
    } else {
        tmp = (Position) malloc(sizeof(struct LNode)); //申请、填装节点
        tmp->Data = X;  //节点赋值
        tmp->Next = P;  //节点指向插入位置的下一个节点
        pre->Next = tmp;    // 上一个节点指向插入的节点
        return true;
    }
}

bool Delete(List L, Position P) {
    Position tmp, pre;

    // 查找p的前一个节点
    for (pre = L; pre && pre->Next != P; pre = pre->Next);

    if (pre == NULL || P == NULL) {
        printf("删除位置参数错误\n");
        return false;
    } else {
        pre->Next = P->Next;
        free(P);
        return true;
    }
}