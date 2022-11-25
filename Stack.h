//
// Created by vadim on 29.09.2022.
//

#ifndef LABSTACKANDQUEUE_STACK_H
#define LABSTACKANDQUEUE_STACK_H

#include "List.h"


template<class T>
class Stack : public List<T> {
    using List<T>::nodeTail;
public:
    Stack() = default;

    explicit Stack(T data) {
        Push(data);
    }

    Stack(const Stack<T> &stack) {
        StackCopy(stack);
    }

    Stack<T>(Stack<T> &&stack) noexcept: List<T>::node(stack.nodeTail) {
        stack.nodeTail = nullptr;
    }

    virtual ~Stack() {
        Del();
    }

    void Push(T data) {
        nodeTail = new Node<T>(data, nodeTail);
        List<T>::size++;
    }

    T Pop() {
        if (nodeTail == nullptr)
            throw List<T>::ERR_EMPTY;
        Node<T> *tempNode = nodeTail;
        T nodeData = nodeTail->data;
        nodeTail = nodeTail->connectedNode;
        delete tempNode;
        List<T>::size--;
        return nodeData;
    }

    const T &GetFront() const {
        if (nodeTail == nullptr)
            throw List<T>::ERR_EMPTY;
        return nodeTail->data;
    }

    Stack<T> &operator=(Stack<T> &&stack) noexcept {
        if (&stack == this)
            return *this;
        this->Del();
        nodeTail = stack.nodeTail;
        stack.nodeTail = nullptr;
        return *this;
    }

    Stack<T> &operator=(const Stack<T> &stack) {
        if (&stack == this)
            return *this;
        this->Del();
        StackCopy(stack);
        return *this;
    }

private:

    void StackCopy(const Stack &stack) {
        Node<T> *temp = stack.nodeTail;
        if (temp == nullptr) return;

        Push(temp->data);
        if (temp->connectedNode == nullptr) return;

        temp = temp->connectedNode;
        Node<T> *lastTrue = nodeTail;
        Push(temp->data);
        Node<T> *preLast = nodeTail;
        preLast->connectedNode = nullptr;
        lastTrue->connectedNode = preLast;
        nodeTail = lastTrue;

        while (temp->connectedNode) {
            temp = temp->connectedNode;
            Push(temp->data);
            nodeTail->connectedNode = nullptr;
            preLast->connectedNode = nodeTail;
            preLast = nodeTail;
            nodeTail = lastTrue;
        }
    }

    void Del() {
        while (nodeTail != nullptr) {
            this->Pop();
        }
    }
};


#endif //LABSTACKANDQUEUE_STACK_H
