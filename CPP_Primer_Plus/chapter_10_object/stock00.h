//
// Created by wujinxing on 2019/10/30.
//

#ifndef CPLUS_LEARNING_STOCK00_H
#define CPLUS_LEARNING_STOCK00_H

#include <string>

class Stock {

private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    // 内联函数
    void set_tot() { total_val = shares * share_val; }

public:
    void acquire(const std::string &co, long n, double pr);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    void show();
};

#endif //CPLUS_LEARNING_STOCK00_H
