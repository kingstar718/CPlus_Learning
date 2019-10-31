//
// Created by wujinxing on 2019/10/31.
//

#ifndef CPLUS_LEARNING_MYTIME0_H
#define CPLUS_LEARNING_MYTIME0_H

class Time {

private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void AddMin(int m);

    void AddHr(int h);

    void Reset(int h = 0, int m = 0);

    //Time Sum(const Time &t) const;
    //添加加法运算符
    Time operator+(const Time &t) const;

    void Show() const;
};

#endif //CPLUS_LEARNING_MYTIME0_H
