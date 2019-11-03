//
// Created by wujinxing on 2019/11/3.
//

#include <cstdio>
#include <cstdlib>

//按题目的意思，存储树的是静态链表
//即建一个结构，里面三个变量char型结点字母，int型的左右孩子的位置

#define MaxTree 10 //题目的意思：最多十个结点
#define ElementType char
#define Tree int
#define Null -1

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

//建一个二叉树的结构，并用数组的元素指向该结构
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];
//这样就可以直接按题目要求进行逐行读入了

//程序的整体框架
int main()
{
    Tree R1, R2;

    R1 = BuildTree(T1);
    //printf("%d\n", R1);
    R2 = BuildTree(T2);
    //printf("%d\n", R2);
    if (Isomorphic(R1, R2)) // 返回1说明同构，返回0说明不同构
        printf("Yes\n");
    else
        printf("No\n");

    return 0;

}

//建二叉树
//1、将结点、左右孩子的位置读入数组结构
//2、通过遍历数组，找出头结点
//没有其他结点指向的就是头结点，所以可以用一个标志

Tree BuildTree(struct TreeNode T[])
{
    int N;
    int Isnode[MaxTree] = {0};
    char cl, cr; //因为有'-'存在，所以先用char型变量暂存，然后再放到结构里
    scanf("%d\n", &N);
    if (N) {
        for (int i = 0; i < N; i++) {
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr); //'-'在结构里用-1表示
            if (cl != '-') {
                T[i].Left = cl - '0'; //在这里可以同时加入对于根结点的判断
                Isnode[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;
            if (cr != '-') {
                T[i].Right = cr - '0';
                Isnode[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;
        }
        //最后遍历一遍结构数组，Isnode为0的就是头结点
        for (int m = 0; m < N; m++) {
            if (!Isnode[m])
                return m;
        }
    }
    return Null;
}

//下面来判断是否为同构
//都为空树，直接返回1；一个空一个不空，直接返回0
//都不空：结点不同，直接0；结点相同，再看子树
//左子树同不存在，就递归调用右子树
//左子树存在，看是否相等，不相等就交换左右子树，再递归调用
int Isomorphic(Tree R1, Tree R2)
{
    if ((R1 == Null) && (R2 == Null))
        return 1;
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
        return 0;
    if (T1[R1].Element != T2[R2].Element)
        return 0;
    if ((T1[R1].Left == Null) &&(T2[R2].Left) == Null)
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    //下面开始判断左右子树是否需要交换判断
    if (((T1[R1].Left != Null) && (T2[R2].Left) != Null) &&
        ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
    else
        return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));

}