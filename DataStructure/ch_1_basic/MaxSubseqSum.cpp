//
// Created by wujinxing on 2019/10/27.
// 最大连续子列和
//
#include <iostream>
#include "MaxSubseqSum3.cpp"
using namespace std;


/**
 * O(N^3)
 */
int MaxSubseqSum1(int A[], int N) {
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for (i = 0; i < N; i++) {   /* i是子列左端位置 */
        for (j = i; j < N; j++) {    /* j是子列右端位置 */
            ThisSum = 0;     /* ThisSum是从A[i]到A[j]的子列和 */
            for (k = i; k <= j; k++)
                ThisSum += A[k];     /* 如果刚得到的这个子列和更大,更新结果 */
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }    /* j循环结束 */
    }    /* i循环结束 */
    return MaxSum;
}

/**
 * O(N^2)
 */
int MaxSubseqSum2(int A[], int N) {
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i < N; i++) {   /* i是子列左端位置 */
        ThisSum = 0;
        for (j = i; j < N; j++) {    /* j是子列右端位置 */
            ThisSum += A[j];
            /*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }    /* j循环结束 */
    }    /* i循环结束 */
    return MaxSum;
}

/**
 * O(N)
 */
int MaxSubseqSum4(int A[], int N) {
    int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for (i = 0; i < N; i++) {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main() {
    int A1[10] = {4, -3, 5, -2, -1, 2, 6, -2};
    int A2[10] = {4, -3, 5, -2, -1, 2, 6, -2};
    int A3[10] = {4, -3, 5, -2, -1, 2, 6, -2};
    int A4[10] = {4, -3, 5, -2, -1, 2, 6, -2};

    int sum1 = MaxSubseqSum1(A1, 8);
    int sum2 = MaxSubseqSum2(A2, 8);
    int sum3 = MaxSubseqSum3(A3, 8);
    int sum4 = MaxSubseqSum4(A4, 8);

    cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
    return 0;
}