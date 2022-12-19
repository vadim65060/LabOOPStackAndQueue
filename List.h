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
    virtual ~List() = default;

    enum ERR_CODE {
        ERR_EMPTY
    };

    virtual void Push(T data) = 0;

    virtual T Pop() = 0;

    virtual const T &GetFront() const = 0;

    bool IsEmpty() const {
        return nodeTail == nullptr;
    }

    int Size() const { return size; }

    friend std::ostream &operator<<(std::ostream &os, List<T> &list) {
        for (auto node: list) {
            os << node << ' ';
        }
        os << '\n';
        return os;
    }

    friend std::istream &operator>>(std::istream &is, List<T> &list) {
        T temp;
        is >> temp;
        list.Push(temp);
        return is;
    }

    struct const_iterator;

    struct iterator {

        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Node<T>;
        using pointer = Node<T> *;
        using reference = Node<T> &;

        explicit iterator(pointer ptr = nullptr) : _ptr(ptr) {}

        T & operator*() const { return _ptr->data; }

        T * operator->() { return _ptr->data; }

        iterator &operator++() {
            _ptr = _ptr->connectedNode;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator &it) { return _ptr == it._ptr; };

        bool operator==(const const_iterator &it) { return const_iterator(_ptr) == it; };

        bool operator!=(const iterator &it) { return _ptr != it._ptr; };

        bool operator!=(const const_iterator &it) { return const_iterator(_ptr) != it; };

        friend const_iterator;
    private:
        pointer _ptr;
    };

    virtual iterator begin() { return iterator(nodeTail); }

    virtual iterator end() { return iterator(); }

    struct const_iterator {

        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Node<T>;
        using pointer = const Node<T> *;
        using reference = const Node<T> &;

        explicit const_iterator(pointer ptr = nullptr) : _ptr(ptr) {}

        explicit const_iterator(const iterator &ptr) : _ptr(ptr._ptr) {};

        T & operator*() const { return _ptr->data; }

        T * operator->() { return _ptr->data; }

        const_iterator &operator++() {
            _ptr = _ptr->connectedNode;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const const_iterator &it) const { return _ptr == it.m_ptr; };

        bool operator==(const iterator &it) { return _ptr == const_iterator(it)._ptr; };

        bool operator!=(const const_iterator &it) const { return _ptr != it.m_ptr; };

        bool operator!=(const iterator &it) { return _ptr != const_iterator(it)._ptr; };

    private:
        pointer _ptr;
    };

    virtual const_iterator begin() const { return const_iterator(nodeTail); }

    virtual const_iterator end() const { return const_iterator(); }

    virtual const_iterator cbegin() const { return const_iterator(nodeTail); }

    virtual const_iterator cend() const { return const_iterator(); }

protected:
    Node<T> *nodeTail = nullptr;
    int size = 0;

};


#endif //OOP_STACKANDQUEUE_LIST_H
