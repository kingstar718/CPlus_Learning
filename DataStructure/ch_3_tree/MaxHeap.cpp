//
// Created by wujinxing on 2019/11/5.
// 最大堆实现及操作集
//

#include <cstdlib>
#include <cstdio>

typedef int ElementType;
#define MaxData 1000
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements; //存储堆元素的数组
    int Size; //堆的当前元素个数
    int Capacity;   //堆的最大容量
};

MaxHeap Create(int MaxSize) {
    MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType *) malloc((MaxSize + 1) * sizeof(ElementType)); // 下标从1开始
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData; //定义哨兵为大于堆中所有可能的元素值，便于后续操作
    return H;
}

bool IsFull(MaxHeap H) {
    return (H->Size == H->Capacity);
}

void Insert(MaxHeap H, ElementType item) {
    int i;
    if (IsFull(H)) {
        printf("最大堆已满");
        return;
    }
    i = ++H->Size; //i指向插入堆后中最后一个元素位置
    for (; H->Elements[i / 2] < item; i /= 2) { // i/=2表示父节点
        H->Elements[i] = H->Elements[i / 2]; //向下过滤节点
    }
    H->Elements[i] = item; //将item插入
}

bool IsEmpty(MaxHeap H) {
    return (H->Size == 0);
}

//最大值删除
ElementType DeleteMax(MaxHeap H) {

    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H)) {
        printf("最大堆已空");
        return 0;
    }
    MaxItem = H->Elements[1]; //取出最大值
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child]) < H->Elements[Child + 1])
            Child++; //Child指向左右子节点的较大者
        if (temp >= H->Elements[Child])
            break; //找到了何时的位置
        else // 移动temp元素到下一层
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}

// 建造最大堆
void PerDown(MaxHeap H, int p) {
    int Parent, Child;
    ElementType X;

    X = H->Elements[p];
    for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Elements[Child]) < H->Elements[Child + 1])
            Child++;
        if (X >= H->Elements[Child])
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}

void buildHeap(MaxHeap H) {
    /**
     * 调整H->Elements[]中的元素，使其满足最大堆的有序性，
     * 这里假设所有H->Size个元素已经存在H->Elements[]中
     */
    int i;
    // 从父节点到根节点1
    for (i = H->Size / 2; i > 0; i--) {
        PerDown(H, i);
    }
}

