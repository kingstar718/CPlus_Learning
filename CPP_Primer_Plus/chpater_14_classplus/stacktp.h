//
// Created by wujinxing on 2019/11/6.
// stack 类模板
//

#ifndef CPLUS_LEARNING_STACKTP_H
#define CPLUS_LEARNING_STACKTP_H

template<class Type>
class Stack {

private:
    enum {
        MAX = 10
    };    // constant specific to class
    Type items[MAX];    // holds stack items
    int top;    // index for top stack item

public:
    Stack();

    bool isEmpty();

    bool isFull();

    bool push(const Type &item);   // add item to stack
    bool pop(Type &item);  // pop top into item
};

template<class Type>
bool Stack<Type>::isEmpty() {
    return top = 0;
}

template<class Type>
bool Stack<Type>::isFull() {
    return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}
#endif //CPLUS_LEARNING_STACKTP_H
