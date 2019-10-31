//
// Created by wujinxing on 2019/10/31.
// 多项式的加法与乘法实现
//
/**
 * 输入：
 * 4 3 4 -5 2 6 1 -2 0 //项数 系数 指数 系数 指数
 * 3 5 20 -7 4 3 1
 *
 * 输出： 系数 指数
 * 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
 * 5 20 -4 4 -5 2 9 1 -2 0
 */
/**
 * 求解思路
 * 1.多项式表示
 * 2.程序框架
 * 3.读多项式
 * 4.加法实现
 * 5.乘法实现
 * 6.多项式输出
 */
#include <iostream>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef; //系数
    int expon; // 指数
    Polynomial link;
};

Polynomial ReadPoly();

void Attach(int c, int e, Polynomial *pRear);

Polynomial ReadPoly() {
    Polynomial P, Rear, t;
    int N, c, e;
    scanf("%d", &N);

    P = (Polynomial) malloc(sizeof(struct PolyNode)); //链表头空节点
    P->link = NULL;
    Rear = P;

    while (N--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear); //将当前项插入多项式尾部
    }
    t = P; //删除临时生成的头结点
    P = P->link;
    free(t);
    return P;
}

void Attach(int c, int e, Polynomial *pRear) {

    Polynomial P;

    P = (Polynomial) malloc(sizeof(struct PolyNode));
    P->coef = c; // 对新节点复制
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P; // 修改pRear的值
}

Polynomial Add(Polynomial P1, Polynomial P2) {
    Polynomial t1, t2, P, Rear;
    t1 = P1;
    t2 = P2;
    P = (Polynomial) malloc(sizeof(struct PolyNode));
    Rear = P;

    while (t1 && t2) {
        if (t1->expon == t2->expon) {

        } else if (t1->expon > t2->expon) {

        } else {

        }
    }
    while (t1) {

    }
    while (t2) {

    }
    return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
    Polynomial P, Rear, t1, t2, t;
    int c, e;

    if (!P1 || !P2) return NULL;

    t1 = P1;
    t2 = P2;
    P = (Polynomial) malloc(sizeof(struct PolyNode));
    P->link = NULL;
    // 先用P1的第一项乘以P2，得到P
    while (t2) {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;

    // t1的每一项乘以t2的每一项
    while (t1) {
        t2 = P2;
        Rear = P;
        while (t2) {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            // 找到插入的点在哪里
            while (Rear->link && Rear->link->expon > e)
                Rear = Rear->link;
            //判断指数相等，合并
            if (Rear->link && Rear->link->expon == e) {
                // 系数相加为0就删除
                if (Rear->link->coef + c) {
                    Rear->link->coef += c;
                } else {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial) malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;

            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t2 = P;
    P = P->link;
    free(t2);

    return P;
}

void PrintPoly(Polynomial P) {
    int flag = 0;
    if (!P) {
        printf("0 0\n");
        return;
    }
    while (P) {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

int main() {

    Polynomial P1, P2, PP, PS;
    // 读入多项式1
    P1 = ReadPoly();
    // 读入多项式2
    P2 = ReadPoly();
    // 乘法运算并输出
    PP = Mult(P1, P2);
    PrintPoly(PP);
    // 加法运算并输出

    return 0;
}