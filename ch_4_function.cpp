//
// Created by wujinxing on 2019/10/10.
// 函数
//
#include <iostream>

using namespace std;

int fact(int val) {
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

int parameter() {
    //传值参数
    int n = 0;
    int i = n; //i是n的值的副本
    i = 42; //i的值改变，n的值不变

    //指针形参
    int n2 = 0, i2 = 42;
    int *p = &n2, *q = &i2;
    *p = 42;  //n的值改变；p的值不变 *p的意思就是n2，改了*p等于改n2
    p = q; //p现在指向了q；但是i和n的值都不变
}

//传指针参数
void reset(int *ip) {
    *ip = 0; //改变指针ip所指对象的值
    ip = 0; // 只改变了ip的局部拷贝，实参未被改变
}

//传引用参数
void reset2(int &i) {
    i = 0;
}

//使用引用避免拷贝
bool isShorter(const string &s1, const string &s2) { //如果函数无需改变引用参数的值，最好将其声明为常量引用
    return s1.size() > s2.size();
}

//使用引用形参返回额外信息
/**
 *
 * @param s1
 * @param c
 * @param occurs
 * @return 返回s中c第一次出现的位置索引
 *         引用形参occurs负责统计c出现的总次数
 */
string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;  //设置表示出现次数的形参的值 疑问：为何occurs直接可以定义？
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i; //记录c第一次出现的位置
            ++occurs; //将出现的次数加1
        }
    }
    return ret;
}

int main() {

    int j = fact(5);
    cout << "5! is " << j << endl;

    //指针参数测试
    int i = 42;
    reset(&i); //改变i的值而非i的地址
    cout << "i = " << i << endl; //输出i=0

    //引用参数传递
    //对引用的操作实际上是作用在引用所引的对象上
    j = 42;
    reset2(j); //直接传入j
    cout << "j = " << j << endl; //输出j=0

    //避免直接拷贝
    string s1 = "abc33", s2 = "abcd";
    cout << isShorter(s1, s2) << endl; //返回1、0

    //使用引用形参返回额外的信息
    string s = "aossao2saowqowqowqsa";
    string::size_type ctr;
    auto index = find_char(s, 'o', ctr);
    cout << "index = " << index << " , ctr = " << ctr << endl;

    //6.2.3 继续


    return 0;
}