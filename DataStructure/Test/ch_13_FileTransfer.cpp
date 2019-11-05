//
// Created by wujinxing on 2019/11/5.

//

#include <cstdio>

#define MaxSize 10005

typedef int SetType;
using namespace std;

void Init(SetType s[], int n) {
    for (int i = 0; i < n; ++i) {
        s[i] = -1;
    }
}

int Find(SetType s[], int x) {
    if (s[x] < 0) //本身是根
        return x;
    else  // 1、找到根 2、把根变成x的父结点 3、再返回
        return s[x] = Find(s, s[x]);
}

void Union(SetType s[], int x1, int x2) {
    if (s[x1] < s[x2]) {
        s[x1] += s[x2]; //两树合并，规模相加
        s[x2] = x1; //x2挂到x1上
    } else {
        s[x2] += s[x1];
        s[x1] = x2;
    }
}

// 连接
void Input_connection(SetType s[]) {
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    int root1 = Find(s, x1 - 1); //以数组下标存值，下标与值差1
    int root2 = Find(s, x2 - 1);
    if (root1 != root2) {
        Union(s, root1, root2);
    }
}

// 检查连接
void check_connection(SetType s[]) {
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    int root1 = Find(s, x1 - 1); //以数组下标存值，下标与值差1
    int root2 = Find(s, x2 - 1);
    if (root1 == root2) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}

// 检查网络
void check_network(SetType s[], int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < 0) counter++;
    }
    if (counter == 1) {
        printf("The network is connected.");
    } else {
        printf("The network %d components.", counter);
    }
}

// 代码有问题
int main() {
    int n;
    char in;
    scanf("%d ", &n);
    SetType s[MaxSize];
    Init(s, n);
    do {
        getchar();  // 接受每次多出来的回车
        scanf("%c", &in);
        switch (in) {
            case 'I': Input_connection(s);break;
            case 'C': check_connection(s);break;
            case 'S': check_network(s, n);break;
        }
    } while (in != 'S');

    return 0;
}