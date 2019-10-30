//
// Created by wujinxing on 2019/10/30.
//

#ifndef CPLUS_LEARNING_STOCK10_H
#define CPLUS_LEARNING_STOCK10_H


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
    // two constructors
    Stock();

    Stock(const std::string &co, long n = 0, double pr = 0);

    ~Stock();  // noisy constructor

    void acquire(const std::string &co, long n, double pr);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    void show();
};

#endif //CPLUS_LEARNING_STOCK10_H
