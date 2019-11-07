//
// Created by wujinxing on 2019/11/7.
// 列出连通集
//
/**
 * 给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。
 * 假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
 *
 * 输入格式:
 * 输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。
 * 每行中的数字之间用1空格分隔。
 *
 * 输出格式:
 * 按照"{ v​1​​  v​2​​  ... v​k​​  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。
 * 输入样例:
 * 8 6
 * 0 7
 * 0 1
 * 2 0
 * 4 1
 * 2 4
 * 3 5
 * 输出样例:
 * { 0 1 4 2 7 }
 * { 3 5 }
 * { 6 }
 * { 0 1 2 7 4 }
 * { 3 5 }
 * { 6 }
 */

#include <iostream>
#include <cstdlib>
#include <queue>

#define MaxVertex 100
typedef int Vertex;

int G[MaxVertex][MaxVertex];
bool visit[MaxVertex];
int Ne, Nv;

using namespace std;

// 建图
void buildMap() {
    cin >> Nv;
    for (int i = 0; i < Nv; ++i) {
        visit[i] = false; // 置为为访问
        for (int j = 0; j < Nv; ++j) {
            G[i][j] = 0;
        }
    }
    cin >> Ne;
    for (int i = 0; i < Ne; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
}

void DFS(Vertex v) {
    // 标记已访问
    visit[v] = true;
    cout << " " << v;
    for (Vertex i = 0; i < Nv; ++i) {
        if (!visit[i] && G[v][i]) // 并未访问过且v-i连通
            DFS(i); // 递归代表着去与返回
    }
}

void BFS(Vertex v) {
    queue<Vertex> q;
    // 改变状态
    visit[v] = true;
    cout << " " << v;
    // 入队
    q.push(v);
    while (!q.empty()) {
        // 出队队的第一个元素
        Vertex tmp = q.front();
        q.pop();
        for (Vertex i = 0; i < Nv; ++i) {
            // 如果未被访问过，且和刚出队元素相邻
            if (!visit[i] && G[i][tmp]) {
                visit[i] = true;
                cout << " " << i;
                q.push(i);
            }
        }
    }
}

// 遍历连通集
void listComponent() {
    for (Vertex i = 0; i < Nv; ++i) {
        if (!visit[i]) {
            cout << "{";
            DFS(i);
            cout << " }\n";
        }
    }

    // 初始访问状态
    for (Vertex i = 0; i < Nv; ++i) {
        visit[i] = false;
    }
    for (Vertex i = 0; i < Nv; ++i) {
        if (!visit[i]) {
            cout << "{";
            BFS(i);
            cout << " }\n";
        }
    }
}

int main() {
    buildMap();
    listComponent();
    return 0;
}
