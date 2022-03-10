#ifndef NODELIST_H_

#define NODELIST_H_

#include "Iterator.h"

template <typename T> class Iterator;
template <typename T> class Node;

template <typename T>
class NodeList {
    private:
        typedef T Value_t;
        typedef Value_t* Ptr_t;
        typedef Value_t& Ref_t;
        typedef Value_t const& Ref_const_t;

        typedef Iterator<T> Iterator_t;
        typedef Iterator_t const& Iterator_const_ref;

        typedef Node<T> Node_value_t;
        typedef Node_value_t* Node_ptr_t;

    public:
        class Iterator<T>;
        struct Node<T>;

        NodeList();
        NodeList(const NodeList& obj) : size(obj.size), head(obj.head), tail(obj.tail) {}
        ~NodeList();

        int getSize() const;
        bool isEmpty() const;

        Iterator_t begin() const;
        Iterator_t end() const;

        void insertFront(Ref_const_t val);
        void insertBack(Ref_const_t val);
        void insert(Iterator_const_ref it, Ref_const_t val);

        void removeFront();
        void removeBack();
        void remove(Iterator_const_ref it);

    private:
        int size;
        Node_ptr_t head;
        Node_ptr_t tail;

};
#include "NodeList.tpp"
#endif