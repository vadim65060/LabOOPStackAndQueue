//
// Created by vadim on 30.09.2022.
//

#ifndef LABSTACKANDQUEUE_QUEUE_H
#define LABSTACKANDQUEUE_QUEUE_H

#include "List.h"

template<class T>
class Queue : public List<T> {
    using List<T>::nodeTail;
public:
    Queue() = default;

    explicit Queue(T data) {
        Push(data);
    }

    Queue(const Queue<T> &queue) noexcept {
        QueueCopy(queue);
    }

    Queue<T>(Queue<T> &&queue) noexcept: nodeHead(queue.nodeHead) {
        nodeTail = queue.nodeTail;
        queue.nodeHead = nullptr;
        queue.nodeTail = nullptr;
    }

    virtual ~Queue() {
        Del();
    }

    void Push(T data) {
        if (nodeTail != nullptr) {
            nodeTail->connectedNode = new Node<T>(data);
            nodeTail = nodeTail->connectedNode;
        } else {
            nodeTail = new Node<T>(data);
            nodeHead = nodeTail;
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
            nodeTail = nullptr;

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
        nodeTail = queue.nodeTail;
        nodeHead = queue.nodeHead;
        queue.nodeHead = nullptr;
        queue.nodeTail = nullptr;
        return *this;
    }

    Queue<T> &operator=(const Queue<T> &queue) {
        if (&queue == this)
            return *this;
        this->Del();
        QueueCopy(queue);
        return *this;
    }

    using iterator = typename List<T>::iterator;
    using const_iterator = typename List<T>::const_iterator;

    iterator begin() { return iterator(nodeHead); }

    const_iterator begin() const { return const_iterator(nodeHead); }

    const_iterator cbegin() const { return const_iterator(nodeHead); }

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
        nodeTail = nullptr;
    }
};


#endif //LABSTACKANDQUEUE_QUEUE_H
