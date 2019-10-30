//
// Created by wujinxing on 2019/10/30.
// Stock 实现类
//
#include <iostream>
#include "stock00.h"

// 管理对某个公司股票的首次购买
void Stock::acquire(const std::string &co, long n, double pr) {

    company = co;
    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

// 加持股票
void Stock::buy(long num, double price) {

    if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

// 减少股票
void Stock::sell(long num, double price) {

    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {

    share_val = price;
    set_tot();
}

void Stock::show() {

    using std::cout;
    using std::ios_base;
    //避免使用科学计数法
    ios_base::fmtflags orig =
            cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision();

    cout << "Company: " << company
         << " Shares: " << shares << '\n';

    cout << " Share Price: $" << share_val;
    cout.precision(2); //设置cout对象的一个标记，命令cout使用定点表示法，只显示三位小数
    cout << " Total Worth: $" << total_val << '\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}