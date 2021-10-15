#ifndef NODELIST_H_
#define NODELIST_H_
#include "Iterator.h"

template <class T> class Iterator;
template <class T> class Node;

template <class T>
class NodeList {
    public:
        class Iterator<T>;
        struct Node<T>;
    private:
        typedef T value_type;
        typedef value_type* ptr_type;
        typedef value_type& ref_type;
        typedef value_type const& const_ref_type;

        typedef Iterator<T> iter_type;
        typedef Iterator<T> const& const_ref_iter_type;

        typedef Node<T> node_type;
        typedef node_type* ptr_node_type;
        typedef node_type& ref_node_type;
        typedef node_type const& const_ref_node_type;
    public:
        NodeList();
        NodeList(const NodeList& obj) : size(obj.size), head(obj.head), tail(obj.tail) {}
        ~NodeList();
        int getSize() const;
        bool isEmpty() const;
        iter_type begin() const;
        iter_type end() const;
        void insertFront(const_ref_type val);
        void insertBack(const_ref_type val);
        void insert(const_ref_iter_type it, const_ref_type val);
        void removeFront();
        void removeBack();
        void remove(const_ref_iter_type it);
    private:
        int size;
        ptr_node_type head;
        ptr_node_type tail;

};
#include "NodeList.tpp"
#endif