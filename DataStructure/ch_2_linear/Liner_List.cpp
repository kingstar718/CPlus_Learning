#include <winioctl.h>

//
// Created by wujinxing on 2019/10/29.
// 线性表的顺序存储实现
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    int Last; /* 保存线性表中最后一个元素的位置 */
};

struct LNode L;
List PtrL;

// 访问下标为i的元素 L.Data[i] 或PtrL->Data[i]
// 线性表长度 L.Last+1 或 PtrL->Last+1

//初始化
List MakeEmpty() {
    List Ptrl;
    Ptrl = (List) malloc(sizeof(struct LNode));
    Ptrl->Last = -1;//镁元素设为-1
    return Ptrl;
}

int Find(ElementType X, List PtrL) {
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X) {
        i++;
    }
    if (i > PtrL->Last)
        return -1;
    else
        return i;
}

void Insert(ElementType X, int i, List PtrL) {
    int j;
    if (PtrL->Last == MAXSIZE - 1) {
        printf("表满");
        return;
    }
    if (i < 1 || i > PtrL->Last + 2) {
        printf("位置不合法");
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--) {
        PtrL->Data[j + 1] = PtrL->Data[j]; //将ai~an倒序向后移动
    }
    PtrL->Data[i - 1] = X;
    PtrL->Last++; // Last仍指向最后元素
    return;
}

void Delete(int i, List PtrL) {
    int j;
    if (i < 1 || i > PtrL->Last + 1) {
        printf("不存在第%d个元素", i);
        return;
    }
    for (j = i; j <= PtrL->Last; j++) {
        PtrL->Data[j - 1] = PtrL->Data[j]; //将ai+1~an顺序向前移动
    }
    PtrL->Last--; // Last仍指向最后元素
    return;
}