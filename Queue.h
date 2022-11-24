//
// Created by vadim on 30.09.2022.
//

#ifndef LABSTACKANDQUEUE_QUEUE_H
#define LABSTACKANDQUEUE_QUEUE_H

#include "List.h"

template<class T>
class Queue : public List<T> {
    using List<T>::node;
public:
    Queue() = default;

    explicit Queue(T data) {
        Push(data);
    }

    Queue(const Queue<T> &queue) noexcept {
        QueueCopy(queue);
    }

    Queue<T>(Queue<T> &&queue) noexcept: nodeHead(queue.nodeHead) {
        node = queue.node;
        queue.nodeHead = nullptr;
        queue.node = nullptr;
    }

    virtual ~Queue() {
        Del();
    }

    void Push(T data) {
        if (node != nullptr) {
            node->connectedNode = new Node<T>(data);
            node = node->connectedNode;
        } else {
            node = new Node<T>(data);
            nodeHead = node;
        }
        List<T>::size++;
    }

    T Pop() {
        if (nodeHead == nullptr)
            throw List<T>::ERR_EMPTY;
        Node<T> *tempNode = nodeHead;
        T nodeData;
        nodeData = nodeHead->data;
        nodeHead = nodeHead->connectedNode;
        if (nodeHead == nullptr)
            node = nullptr;

        delete tempNode;
        List<T>::size--;
        return nodeData;
    }

    const T &GetFront() const {
        if (nodeHead == nullptr)
            throw List<T>::ERR_EMPTY;
        return nodeHead->data;
    }

    Queue<T> &operator=(Queue<T> &&queue) noexcept {
        if (&queue == this)
            return *this;
        this->Del();
        node = queue.node;
        nodeHead = queue.nodeHead;
        queue.nodeHead = nullptr;
        queue.node = nullptr;
        return *this;
    }

    Queue<T> &operator=(const Queue<T> &queue) {
        if (&queue == this)
            return *this;
        this->Del();
        QueueCopy(queue);
        return *this;
    }

protected:

    void Print(std::ostream &os) {
        Node<T> *itNode = nodeHead;
        while (itNode) {
            os << itNode->data << ' ';
            itNode = itNode->connectedNode;
        }
        os << "\n";
    }

private:
    Node<T> *nodeHead = nullptr;

    void QueueCopy(const Queue<T> &queue) {
        Node<T> *itNode = queue.nodeHead;
        while (itNode) {
            this->Push(itNode->data);
            itNode = itNode->connectedNode;
        }
    }

    void Del() {
        while (nodeHead != nullptr) {
            this->Pop();
        }
        node = nullptr;
    }
};


#endif //LABSTACKANDQUEUE_QUEUE_H
