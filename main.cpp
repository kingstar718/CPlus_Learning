#include <iostream>
#include "ch_1_reference.cpp"
#include "ch_2_string.cpp"
#include "ch_3_vector.cpp"
#include "ch_4_function.cpp"

using namespace std;

int main() {
    //ch_1
    //reference();
    //refer2();
    //defStruct();

    //ch_2
    //def();
    //getLine();

    //ch_3
    //demo1();
    //iter();

    //ch_4 函数
    /*int j = fact(5);
    cout << "5! is " << j << endl;*/

    //指针参数测试
    int i =42;
    reset(&i); //改变i的值而非i的地址
    cout << "i = " << i << endl; //输出i=0

    //引用参数传递
    //对引用的操作实际上是作用在引用所引的对象上
    int j = 42;
    reset2(j); //直接传入j
    cout << "j = " << j << endl; //输出j=0
    return 0;
}