//
// Created by wujinxing on 2019/11/6.
//
/**
 * This time let us consider the situation in the movie "Live and Let Die" in which James Bond,
 * the world's most famous spy, was captured by a group of drug dealers.
 * He was sent to a small piece of land at the center of a lake filled with crocodiles.
 * There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile!
 * Before the animal realized what was happening, James jumped again onto the next big head...
 * Finally he reached the bank before the last crocodile could bite him
 * (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).
 *
 * Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at
 * (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0)
 * with the diameter of 15. A number of crocodiles are in the lake at various positions.
 * Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.
 *
 * Input Specification:
 * Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100),
 * the number of crocodiles, and D, the maximum distance that James could jump.
 * Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.
 *
 * Output Specification:
 * For each test case, print in a line "Yes" if James can escape, or "No" if not.
 * Sample Input 1:
 * 14 20
 * 25 -15
 * -25 28
 * 8 49
 * 29 15
 * -35 -2
 * 5 28
 * 27 -29
 * -8 -28
 * -20 -35
 * -25 -20
 * -13 29
 * -30 15
 * -35 40
 * 12 12
 * Sample Output 1:
 * Yes
 * Sample Input 2:
 * 4 13
 * -12 12
 * 12 12
 * -12 -12
 * 12 -12
 * Sample Output 2:
 * No
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>

#define MaxVertex 105

struct Node { // 存鳄鱼下标
    int hor;    // 横坐标
    int ver;    // 纵坐标
    bool visit; // 是否能被访问
    bool safe;  //  是否能上岸
    bool jump;  // 第一步能否跳上去
};

int N; // 鳄鱼数
int D; // 跳跃距离
bool isSafe; // 是否上岸
Node G[MaxVertex];

using namespace std;
const double diameter = 15;

// 计算两点距离
double getLen(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

// 计算该鳄鱼能否到岸边
bool ashore(int x, int y) {
    // 分布计算当前节点与岸边的距离
    // 即与(x, 50) (x, -50) (50, y) (-50, y)的距离
    return (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D);
}

//确认鳄鱼是否安全（“能上岸”）
void getSafe() {
    for (int i = 0; i < N; i++) {
        G[i].safe = ashore(G[i].hor, G[i].ver); // 鳄鱼是否和岸边相邻
    }
}

// 确认哪些鳄鱼是可以第一步跳上去的
void getJump() {
    for (int i = 0; i < N; ++i) {
        G[i].jump = (getLen(G[i].hor, G[i].ver, 0, 0) <= (D + diameter / 2));
    }
}

void Init() {
    cin >> N >> D;
    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        G[i].hor = x;
        G[i].ver = y;
        G[i].visit = false;
    }
    getSafe();
    getJump();
    isSafe = false;
}

void DFS(int v) {
    if (G[v].safe) {
        isSafe = true;
        return;
    }
    G[v].visit = true;
    for (int i = 0; i < N; i++) {
        // 如果距离小于D， 且为跳过，则能跳
        if (getLen(G[v].hor, G[v].ver, G[i].hor, G[i].ver) <= D && !G[i].visit)
            DFS(i);
    }
}

void BFS(int v) {
    queue<Node> q;
    Node tmp;
    G[v].visit = true;

    //  第一只鳄鱼入队
    q.push(G[v]);
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        // 能上岸
        if (tmp.safe) {
            isSafe = true;
            return;
        }
        for (int i = 0; i < N; i++) {// 距离如果小于 D，且未跳过，则能跳
            if (getLen(tmp.hor, tmp.ver, G[i].hor, G[v].ver) <= D && !G[i].visit) {
                G[i].visit = true;
                q.push(G[i]);
            }

        }
    }
}

// 遍历所有第一步能调到的鳄鱼
void listCompoent() {
    for (int i = 0; i < N; ++i) {
        if (G[i].jump) {
            // DFS(i);
            BFS(i);
        }
    }
    if (isSafe)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    Init();
    listCompoent();
    return 0;
}