#ifndef SLIST_H_
#define SLIST_H_

#include "SNode.h"

template <class T>
class SList {
    public:
        SList();
        ~SList();
        bool isEmpty() const;
        void addFront(const T& val);
        void popFront();
        const T& front() const;
    private:
        SNode<T>* head;
};

#endif