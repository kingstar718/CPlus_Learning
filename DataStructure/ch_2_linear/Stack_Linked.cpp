//
// Created by wujinxing on 2019/10/30.
// 栈的链表实现
//
#include <cstdlib>
#include <iostream>

typedef int ElementType;
ElementType ERROR = -1; //错误值

typedef int Position;
typedef struct SNode *PtrToSNode;

struct SNode {
    ElementType Data;  //存储元素的数组
    PtrToSNode Next;
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize) {
    //构建一个堆栈的头结点，返回该节点指针
    Stack S;

    S = (Stack) malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S) {
    return (S->Next == NULL);
}

bool Push(Stack S, ElementType X) {

    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode) malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}


ElementType Pop(Stack S) {

    PtrToSNode FirstCell;
    ElementType TopElem;

    if (IsEmpty(S)) {
        printf("堆栈空");
        return ERROR;
    } else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}
