#ifndef ITERATOR_H_

#define ITERATOR_H_

#include "Node.h"

template <typename T> class Node;
template <typename T> class NodeList;

template <typename T>
class Iterator {
    private:
        typedef T Value_t;
        typedef Value_t* Ptr_t;
        typedef Value_t& Ref_t;
        typedef Value_t const& Ref_const_t;
        
        typedef Node<T> Node_value_t;
        typedef Node_value_t* Node_ptr_t;

    public:
        friend class NodeList<T>;

        inline Ref_t operator*();

        inline bool operator==(const Iterator& iter);
        inline bool operator!=(const Iterator& iter);

        inline Iterator& operator++();
        inline Iterator& operator++(int);
        inline Iterator& operator--();
        inline Iterator& operator--(int);

        inline Iterator& operator+(int num);
        inline Iterator& operator-(int num);

    private:
        inline Iterator(Node_ptr_t node);

        Node_ptr_t value;
};

#include "Iterator.tpp"

#endif