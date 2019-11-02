//
// Created by wujinxing on 2019/11/1.
//

#ifndef CPLUS_LEARNING_STUDENT_H
#define CPLUS_LEARNING_STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

class Student {

private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;
    // private methed for scores output
    std::ostream & arr_out(std::ostream &os) const;

public:
    Student():name("Null Student"),scores(){}

};


#endif //CPLUS_LEARNING_STUDENT_H
