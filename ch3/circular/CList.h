#ifndef CLIST_H_
#define CLIST_H_
#include "../single/SingleLinkedItem.h"
#include <string>
template <class T> class SingleLinkedItem;

template <class T>
class CList {
    private:
        typedef SingleLinkedItem<T> item_val;
        typedef item_val* item_ptr;
        typedef item_val& item_ref;
        typedef const item_val& const_item_ref;

        typedef typename item_val::value_type value_type;
        typedef typename item_val::ptr_type ptr_type;
        typedef typename item_val::ref_type ref_type;
        typedef typename item_val::const_ref_type const_ref_type;
    public:
        CList();
        ~CList();
        inline bool isEmpty() const;
        inline int getSize() const;
        const_ref_type front() const; // returns value of the next item
        const_ref_type back() const; // returns value of the current item
        std::string toString();
        void advance();
        void add(const_ref_type val);
        void remove();
    private:
        item_ptr cursor;
        int size;
};
#include "CList.tpp"

#endif