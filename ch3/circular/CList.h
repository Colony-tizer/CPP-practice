#ifndef CLIST_H_
#define CLIST_H_
#include "../single/SingleLinkedItem.h"
#include <string>
template <class T> class SingleLinkedItem;

template <class T>
class CList {
    private:
        typedef SingleLinkedItem<T> Single_link_item_t;
        typedef Single_link_item_t* Single_link_item_ptr_t;

        typedef typename Single_link_item_t::Value_t Value_t;
        typedef typename Single_link_item_t::Ptr_t Ptr_t;
        typedef typename Single_link_item_t::Ref_t Ref_t;
        typedef typename Single_link_item_t::Ref_const_t Ref_const_t;
        
    public:
        CList();
        ~CList();
        inline bool isEmpty() const;
        inline int getSize() const;

        Ref_const_t front() const; // returns value of the next item
        Ref_const_t back() const; // returns value of the current item
        void advance();

        void add(Ref_const_t val);
        void remove();
        
        std::string toString();

    private:
        Single_link_item_ptr_t cursor;
        int size;
};
#include "CList.tpp"

#endif