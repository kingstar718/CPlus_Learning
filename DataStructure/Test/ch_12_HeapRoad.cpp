//
// Created by wujinxing on 2019/11/5.
// 堆中的路径
//
/**
 * 将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。
 * 输入格式:
 * 每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。
 * 下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。
 *
 * 输出格式:
 * 对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。
 * 输入样例:
 * 5 3
 * 46 23 26 24 10
 * 5 4 3
 * 输出样例:
 * 24 23 10
 * 46 23 10
 * 26 10
 */

#include <iostream>
#include <cstdio>

const int MinData = -100005;
const int MaxSize = 10005;

using namespace std;
typedef struct HeapStruct *Heap;
struct HeapStruct {
    int *data;  // 存值的数组
    int size;   // 当前元素个数
    int capacity;   // 最大容量
};

Heap Create();

void Insert(Heap H, int X);

// 遍历
void Traversal(Heap H);

// 程序有问题 AC不了全部
int main() {
    /**
     * 读入n和m
     * 根据输入序列建堆
     * 对m个要求：打印到根的路径
     */
    Heap H;
    H = Create();
    int n, m, x, i, j;
    //scanf("%d %d", &n, &m);
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> x;
        Insert(H, x);
    }

    for (i = 0; i < m; i++) {
        cin >> j;
        printf("%d ", H->data[j]);
        while (j > 1) {
            j /= 2;//找父节点
            if (j != 1)
                printf("%d ", H->data[j]);
            else
                printf("%d", H->data[j]);
        }
        if (i != m - 1) {
            printf("\n");
        }
    }

    //Traversal(H);
    return 0;
}

Heap Create() {
    Heap H;
    H = (Heap) malloc(sizeof(HeapStruct));
    H->data = (int *) malloc(sizeof(int) * (MaxSize + 1)); //生成数组
    H->size = 0;
    H->capacity = MaxSize;
    H->data[0] = MinData; // 哨兵设置
    return H;
}

void Insert(Heap H, int X) {
    int i = ++H->size; // 指向数组最后一个
    //寻找插入位置 比父节点大就互换
    for (; H->data[i / 2] > X; i /= 2) {
        H->data[i] = H->data[i / 2];
    }
    H->data[i] = X;
}

// 遍历
void Traversal(Heap H) {
    for (int i = 1; i < H->size; i++) {
        cout << H->data[i];
    }
}