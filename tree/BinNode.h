//
// Created by wujinxing on 2019/10/11.
//

#ifndef CPLUS_LEARNING_BINNODE_H
#define CPLUS_LEARNING_BINNODE_H
#define BinNodePosi(T) BinNode<T>*; //节点位置
#define stature(p) ((p)?(p)->height:-1); //节点高度
typedef enum {
    RB_RED, RB_BLACK
} RBColor; //节点颜色

//二叉树节点模板类
template<template T>
struct BinNode {

    T data;
    BinNodePosi(T)
    parent;
    BinNodePosi(T)
    lChild;
    BinNodePosi(T)
    rChild; //父节点及左右孩子
    int height;
    int npl; //Null Path Length（左式堆，也可直接用height代替）
    RBColor color; //颜色（红黑树）

    //构造函数
    BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {}

    BinNode(T e, BinNodePosi(T)

    p = NULL, BinNodePosi(T)
    lc = NULL, BinNodePosi(T)
    rc = NULL,
    int h = 0,
    int l = 1, RBColor
    c = RB_RED
    )
    :

    data (e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}

    //操作接口
    int size();//统计弼前节点后代总数，亦即以其为根癿子树癿觃模

    BinNodePosi(T) insertAsLC(T const&);;//作为当前节点癿左孩子插入新节点
    BinNodePosi(T) insertAsRC(T const&);;//作为当前节点癿左孩子插入新节点
    BinNodePosi(T) succ(); //取当前节点直接后继

    template<typename VST> void travLevel(VST &); //子树局次遍历

    template<typename VST> void travPre(VST &); //子树先序遍历

    template<typename VST> void travIn(VST &); //子树中序遍历

    template<typename VST> void travPost(VST &); //子树后序遍历

    //比较器、判断其
    bool operator<(BinNode const &bn) { return data < bn.data; }

    bool operator==(BinNode const &bn) { return data == bn.data; }

};


#endif //CPLUS_LEARNING_BINNODE_H
