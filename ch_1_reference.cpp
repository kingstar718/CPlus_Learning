//
// Created by wujinxing on 2019/9/29.
//
#include <iostream>
#include "Sales_data.h"

using namespace std;

void reference() {

    int iVal = 1024;
    int &refVal = iVal;
    //int &refVal; //引用必须被初始化
    refVal = 2;
    cout << iVal << endl;

    //指针本身就是一个对象，指针无需在定义时赋初始值

    int *ip1, *ip2; //都是指向int型对象的指针
    double dp, *dp2; //dp2是指向double型对象的指针，dp是double型对象

    //获取对象的地址 指针存放着某个对象的地址，要想获取该地址，需要使用取地址符&
    int *p = &iVal; //p存放变量iVal的地址，或者说p是指向变量iVal的指针
    cout << "iVal的地址" << &iVal << endl;

    //利用指针访问对象
    cout << "使用指针访问对象即*p：" << *p << endl;

    //直接输出指针则为地址
    cout << "直接输出指针则为地址即p：" << p << endl;

    //指针再取&就是当前指针对象的地址，即&p：
    cout << "指针再取&就是当前指针对象的地址，即&p：" << &p << endl;

    /**
     * 相同点：指针和引用都能提供对其他对象的间接访问。
     * 区别点：1.引用本身并不是对象
     *        2.一旦定义引用，无法再将其绑定到另外的对象上了
     *        3.指针无上述限制，给指针赋值就是令他存放一个新的地址，从而指向一个新的对象
     */
    int i = 42;
    int *pi = 0;   //pi被初始化，但没有指向任何对象
    int *pi2 = &i; //pi2被初始化，存有i的地址
    int *pi3;   // 如果pi3定义于块内，则pi3的值是无法确定的

    pi3 = pi2;  // pi3和pi2指向同一个对象
    pi2 = 0;    //现在pi2不指向任何对象了

    /**
     * 如何弄清一条赋值语句是改变了指针的值还是改变了指针所指对象的值不太容易
     * 办法：记住赋值永远改变的是等号左侧的对象
     */
    pi = &iVal;  //pi的值被改变，现在pi指向了iVal
    *pi = 0;  // iVal的值被改变，指针pi并没有改变

    // void* 指针
    double obj = 3.14, *pd = &obj;

    void *pv = &obj;
    pv = pd;

    //理解复合类型的声明
    int ip = 1024, *ipp = &i, &r = i;
}

void refer2() {
    //指向指针的指针
    int iVal = 1024;
    int *pi = &iVal;  //pi指向一个int型的数
    int **ppi = &pi;  //ppi指向一个int型的指针
    // ppi->pi->iVal(1024)
    cout << "The value of iVal\n"
         << "direct value: " << iVal << "\n"
         << "indirect value: " << *pi << "\n"
         << "doubly indirect value: " << **ppi
         << endl;

    //指向指针的引用
    int i = 42;
    int *p;  //p是一个int型指针
    int *&r = p; // r是一个对指针p的引用

    r = &i; //r引用了一个指针，因此给r赋值&i就是令p指向i
    *r = 0; //解引用r得到i，也就是p指向的对象，将i的值改为0

    //const
    const int ci = 1024;
    const int &r1 = ci; //引用及其对应的对象都是常量

    //别名
    typedef double wages; //wages是double的同义词
    typedef wages base, *p1; //base是double的同义词， p1是double*的同义词
}

int defStruct() {

    Sales_data data1, data2;

    //读入data1和data2的代码
    double price = 0;
    //读入第一笔交易：ISBN、销售数量、单价
    cin >> data1.bookNo >> data1.units_sold >> price;
    //计算销售收入
    data1.revenue = data1.units_sold * price;

    //读入第二笔交易
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    //检查data1和data2的ISBN是否相同的代码
    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        //输出：ISBN、总销售量、总销售额、平均价格
        cout << data1.bookNo << " " << totalCnt
             << " " << totalRevenue << " ";

        if (totalCnt != 0) {
            cout << totalRevenue / totalCnt << endl;
        } else {
            cout << "(no sales)" << endl;
        }
        return 0;
    } else{
        cerr << "Data must refer to the same ISBN"
             << endl;
        return -1;
    }
}


