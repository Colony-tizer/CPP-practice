#ifndef SINGLE_LINKED_LIST_H_

#define SINGLE_LINKED_LIST_H_

#include <ostream>
#include "SingleLinkedItem.h"

template <typename T> class SingleLinkedItem;
template <typename T> class SingleLinkedList;

template<typename T>
std::ostream& operator<<(std::ostream&, const SingleLinkedList<T>&);

template <typename T>
class SingleLinkedList {
    private:
        typedef SingleLinkedItem<T> Single_link_item_t;
        typedef Single_link_item_t* Single_link_item_ptr_t;
        typedef Single_link_item_t& Single_link_item_ref_t;
        typedef Single_link_item_t const& Single_link_item_ref_const_t;

    public:
        SingleLinkedList();
        ~SingleLinkedList();
        bool isEmpty();
        void removeFront();

        Single_link_item_ref_const_t front() const;
        typename Single_link_item_t::Ref_const_t frontVal() const;
        void addFront(Single_link_item_ref_const_t obj);
        void addFront(typename Single_link_item_t::Ref_t val);
        friend std::ostream& operator<< <>(std::ostream& os, const SingleLinkedList<T>& obj);

    private:
        Single_link_item_ptr_t head;
};

#include "SingleLinkedList.tpp"

#endif