//
// Created by wujinxing on 2019/10/31.
//

#ifndef CPLUS_LEARNING_STRINGBAD_H
#define CPLUS_LEARNING_STRINGBAD_H


#include <iostream>

class StringBad {

private:
    char *str; //pointer to string
    int len;
    static int num_strings; // number of objects

public:
    StringBad(const char *s);

    StringBad();

    ~StringBad();

    //friend function
    friend std::ostream &operator<<(std::ostream &os,
                                    const StringBad &st);
};


#endif //CPLUS_LEARNING_STRINGBAD_H
