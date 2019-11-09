//
// Created by wujinxing on 2019/11/9.
//
#include <cstdlib>

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535  /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex; /* 用顶点下标表示顶点,为整型 */
typedef int WeightType; /* 边的权值设为整型 */
typedef char DataType;  /* 顶点存储的数据类型设为字符型 */

// 边的定义
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;   /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType  Data[MaxVertexNum];
};

typedef PtrToENode MGraph;  /* 以邻接矩阵存储的图类型 */

MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->N
}
