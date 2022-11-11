//
// Created by vadim on 11.11.2022.
//

#ifndef OOP_STACKANDQUEUE_LIST_H
#define OOP_STACKANDQUEUE_LIST_H

#include "Node.h"
#include <iostream>

template<class T>
class List {
public:
    enum ERR_CODE {
        ERR_EMPTY
    };

    virtual void Push(T data) = 0;

    virtual T Pop() = 0;

    virtual const T &GetFront() const = 0;

    bool IsEmpty() const {
        return node == nullptr;
    }

    int Size() const { return size; }

    friend std::ostream &operator<<(std::ostream &os, List<T> &list) {
        list.Print(os);
        return os;
    }

    friend std::istream &operator>>(std::istream &is, List<T> &list) {
        T temp;
        is >> temp;
        list.Push(temp);
        return is;
    }

protected:
    Node<T> *node = nullptr;
    int size = 0;

    virtual void Print(std::ostream &os) = 0;
};


#endif //OOP_STACKANDQUEUE_LIST_H
