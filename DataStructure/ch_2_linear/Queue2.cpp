//
// Created by wujinxing on 2019/10/31.
// 队列的链式存储
//

#include <cstdlib>
#include <iostream>

typedef int ElementType;
ElementType ERROR = 1;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;
    int MaxSize;
};

typedef struct QNode *Queue;

bool IsEmpty(Queue Q) {
    return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q) {

    Position FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q)) {
        printf("队列空");
        return ERROR;
    } else {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear) //若队列只有一个元素
            Q->Front = Q->Rear = NULL; //删除后队列置为空
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;

        free(FrontCell); //释放被删除节点空间
        return FrontElem;
    }
}
