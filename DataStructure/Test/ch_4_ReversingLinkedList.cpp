//
// Created by wujinxing on 2019/11/3.
// 程序有问题
//

#include <stdio.h>
//#include <iostream>

#define MaxSize 100005

//using namespace std;

int main() {
    int Data[MaxSize];
    int Next[MaxSize];
    int list[MaxSize];
    int FirstAdd, N, K;
    scanf("%d %d %d", &FirstAdd, &N, &K);
    for (int i = 0; i < N; ++i) {
        int tmpAdd, tmpData, tmpNext;
        scanf("%d %d %d", &tmpAdd, &tmpData, &tmpNext);
        Data[tmpData] = tmpData;
        Next[tmpNext] = tmpNext;
    }

    int sum = 0; // 累计有效节点
    while (FirstAdd != -1) {  //当尾结点为-1时结束
        list[sum++] = FirstAdd; // 记录所有的Address
        FirstAdd = Next[FirstAdd]; //找下一个节点
    }

    for (int i = 0; i < sum - sum % K; i += K) {
        for (int j = 0; j < K / 2; ++j) {
            int t = list[i + 1];
            list[i + j] = list[i + K - j - 1];
            list[i + K - j - 1] = t;
        }
    }

    for (int i = 0; i < sum - 1; i++) {
        printf("%05d %d %05d\n", list[i], Data[list[i]], list[i + 1]);
    }
    printf("%05d %d -1\n", list[sum - 1], Data[list[sum - 1]]);
    return 0;
}