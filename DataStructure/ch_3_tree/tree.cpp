//
// Created by wujinxing on 2019/10/31.
// 树结构
//

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;    /* 二叉树类型 */
struct TNode{
    ElementType Data;   /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};

