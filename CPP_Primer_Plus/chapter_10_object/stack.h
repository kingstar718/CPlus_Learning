//
// Created by wujinxing on 2019/10/30.
//

#ifndef CPLUS_LEARNING_STACK_H
#define CPLUS_LEARNING_STACK_H

typedef unsigned long Item;

class Stack {

private:
    enum {
        MAX = 10
    };
    Item items[MAX];
    int top;

public:
    Stack();

    bool isempty() const;

    bool isfull() const;

    bool push(const Item &item);

    bool pop(Item &item);
};

#endif //CPLUS_LEARNING_STACK_H
