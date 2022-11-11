//
// Created by vadim on 29.09.2022.
//

#ifndef LABSTACKANDQUEUE_STACK_H
#define LABSTACKANDQUEUE_STACK_H

#include "List.h"


template<class T>
class Stack : public List<T> {
    using List<T>::node;
public:
    Stack() = default;

    explicit Stack(T data) {
        Push(data);
    }

    Stack(const Stack<T> &stack) {
        StackCopy(stack);
    }

    Stack<T>(Stack<T> &&stack) noexcept: List<T>::node(stack.node) {
        stack.node = nullptr;
    }

    ~Stack() {
        Del();
    }

    void Push(T data) {
        node = new Node<T>(data, node);
        List<T>::size++;
    }

    T Pop() {
        if (node == nullptr)
            throw List<T>::ERR_EMPTY;
        Node<T> *tempNode = node;
        T nodeData = node->data;
        node = node->connectedNode;
        delete tempNode;
        List<T>::size--;
        return nodeData;
    }

    const T &GetFront() const {
        if (node == nullptr)
            throw List<T>::ERR_EMPTY;
        return node->data;
    }

    Stack<T> &operator=(Stack<T> &&stack) noexcept {
        if (&stack == this)
            return *this;
        this->Del();
        node = stack.node;
        stack.node = nullptr;
        return *this;
    }

    Stack<T> &operator=(const Stack<T> &stack) {
        if (&stack == this)
            return *this;
        this->Del();
        StackCopy(stack);
        return *this;
    }

protected:

    void Print(std::ostream &os) {
        Node<T> *itNode = node;
        os << "tail ";
        while (itNode) {
            os << itNode->data << ' ';
            itNode = itNode->connectedNode;
        }
        os << "\n";
    }

private:

    void StackCopy(const Stack<T> &stack) {
        Node<T> *itNode = stack.node;
        while (itNode) {
            this->Push(itNode->data);
            itNode = itNode->connectedNode;
        }
        Node<T> *lastNode = this->node;
        itNode = this->node->connectedNode;
        while (itNode->connectedNode != nullptr) {
            Node<T> *tempNode = itNode->connectedNode;
            itNode->connectedNode = lastNode;
            lastNode = itNode;
            itNode = tempNode;
        }
        itNode->connectedNode = lastNode;
        this->node->connectedNode = nullptr;
        this->node = itNode;
    }

    void Del() {
        while (node != nullptr) {
            this->Pop();
        }
    }
};


#endif //LABSTACKANDQUEUE_STACK_H
