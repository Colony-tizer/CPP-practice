#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "Node.h"
template <class T> class Node;
template <class T> class NodeList;

template <class T>
class Iterator {
    private:
        typedef T value_type;
        typedef value_type* ptr_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;
        
        typedef Node<T> node_value;
        typedef node_value* ptr_node_type;
        typedef node_value& ref_node_type;
        typedef node_value const& const_ref_node_type;
    public:
        inline ref_type operator*();
        inline bool operator==(const Iterator& iter);
        inline bool operator!=(const Iterator& iter);
        inline Iterator& operator++();
        inline Iterator& operator++(int);
        inline Iterator& operator--();
        inline Iterator& operator--(int);
        inline Iterator& operator+(int num);
        inline Iterator& operator-(int num);
        friend class NodeList<T>;
    private:
        ptr_node_type value;
        inline Iterator(ptr_node_type node);
};
#include "Iterator.tpp"
#endif