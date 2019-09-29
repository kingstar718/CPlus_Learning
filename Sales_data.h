//
// Created by wujinxing on 2019/9/29.
//

#ifndef CPLUS_LEARNING_SALES_DATA_H //当且仅当变量未定义时为真
#define CPLUS_LEARNING_SALES_DATA_H //把一个名字设定为预处理变量

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif //CPLUS_LEARNING_SALES_DATA_H
