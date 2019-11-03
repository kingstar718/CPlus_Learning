//
// Created by wujinxing on 2019/11/1.
// 多项式 相加和相减
//
/**
 * 输入格式:
 * 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
 * 输出格式:
 * 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
 * 输入样例:
 * 4 3 4 -5 2  6 1  -2 0
 * 3 5 20  -7 4  3 1
 * 输出样例:
 * 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
 * 5 20 -4 4 -5 2 9 1 -2 0
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
typedef struct Node {
    List Next;
    int z; //指数
    int x;  // 系数
};

List Read() {
    List L = (List) malloc(sizeof(struct Node));
    List head = L;
    int n;
    int i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int x;
        int z;
        List t = (List) malloc(sizeof(struct Node));
        scanf("%d %d", &x, &z);
        t->x = x;
        t->z = z;
        L->Next = t;
        L = L->Next;
    }
    L->Next = NULL;
    return head->Next;
}

List Add(List L1, List L2) {
    List tmpL1 = L1;
    List tmpL2 = L2;
    List add = (List) malloc(sizeof(struct Node));
    add->Next = NULL;
    List head = add;
    List t;
    while (tmpL1 && tmpL2) {
        t = (List) malloc(sizeof(struct Node));
        if (tmpL1->z == tmpL2->z) {
            t->x = tmpL1->x + tmpL2->x;
            t->z = tmpL1->z;
            tmpL1 = tmpL1->Next;
            tmpL2 = tmpL2->Next;
        } else if (tmpL1->z < tmpL2->z) { //L2的节点指数更大
            t->x = tmpL2->x;
            t->z = tmpL2->z;
            tmpL2 = tmpL2->Next;
        } else if (tmpL1->z > tmpL2->z) { //L2的节点指数更大
            t->x = tmpL1->x;
            t->z = tmpL1->z;
            tmpL1 = tmpL1->Next;
        }
        add->Next = t;
        add = add->Next;
    }
    if (tmpL1) {
        add->Next = tmpL1;
    } else if (tmpL2) {
        add->Next = tmpL2;
    }
    return head->Next;
}

List Mult(List L1, List L2) {
    List tmpL1 = L1;
    List tmpL2 = L2;
    List mul = (List) malloc(sizeof(struct Node));
    mul->Next = NULL;
    List head = mul;
    List t;
    for (; tmpL1; tmpL1 = tmpL1->Next) {
        for (tmpL2 = L2; tmpL2; tmpL2 = tmpL2->Next) {
            t = (List) malloc(sizeof(struct Node));
            t->x = tmpL1->x * tmpL2->x; //系数相乘
            t->z = tmpL1->z + tmpL2->z; //指数相加
            t->Next = NULL;
            head = Add(t, mul);
            mul = head;
        }
    }
    return head;
}

void printList(List L) {
    List t = L;
    int flag = 1;
    for (; t; t = t->Next) {
        if (!flag && t->x) {
            printf(" ");
        }
        if (t->x) {
            printf("%d %d", t->x, t->z);
            flag = 0;
        }
    }
    if (flag) {
        printf("0 0");
    }
    printf("\n");
}

int main() {
    List L1, L2, add, mul;
    L1 = Read();
    L2 = Read();
    add = Add(L1, L2);
    mul = Mult(L1, L2);
    printList(mul);
    printList(add);
    return 0;
}