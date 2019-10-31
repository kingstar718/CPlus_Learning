//
// Created by wujinxing on 2019/10/31.
// 队列的循环数组实现
//
#include <cstdlib>
#include <iostream>

typedef int ElementType;
ElementType ERROR = 1;

typedef int Position;
struct QNode {
    ElementType *Data;
    Position Front, Rear;
    int MaxSize;
};

typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize) {

    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

/**
 * 假设数组长度为6 MaxSize为5 Front、Rear一开始都为0
 * 添加元素 Rear会一直加，到5就满了，此时如果Front为0， 则有 (5+1)%6==0 表示满了
 * 如果Front到了1，则Rear到0才会满，有 (0+1)%6==1,表示满了，即可得下满表达式
 */
bool IsFull(Queue Q) {
    return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool Add(Queue Q, ElementType X) {
    if (IsFull(Q)) {
        printf("队列满");
        return false;
    } else {
        // 还是那个假设，0 1 2 3 4 5 6-0 7-1 8-2 最大存6个
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

bool IsEmpty(Queue Q) {
    return (Q->Front == Q->Rear);
}

ElementType DeleteQ(Queue Q) {
    if (IsEmpty(Q)) {
        printf("队列空");
        return ERROR;
    } else {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}
