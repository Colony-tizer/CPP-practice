#ifndef DLIST_H_
#define DLIST_H_

#include "DItem.h"
#include <ostream>
#include <string>

template <class T> class DItem;

template <class T> 
class DList {
    private:
        typedef DItem<T> item_val;
        typedef item_val* item_ptr;
        typedef item_val& item_ref;
        typedef const item_val& const_item_ref;
    public:
        typedef typename item_val::value_type value_type;
        typedef typename item_val::ptr_type ptr_type;
        typedef typename item_val::ref_type ref_type;
        typedef typename item_val::const_ref_type const_ref_type;

        DList() : size(0), head(nullptr), tail(nullptr) {}
        DList(const_ref_type val);
        DList(const_item_ref obj);
        ~DList();

        bool isEmpty() const;
        int getSize() const;
        void popFront(); 
        //item_ptr popFront(); // it is not efficient to return removed value
        const_ref_type front() const;
        const_ref_type at(const int i) const;
        void addAt(const int i, const_ref_type val);
        void addAt(const int i, const_item_ref item);
        void removeAt(const int i);
        void addFront(const_ref_type val);
        void addFront(const_item_ref item);

        std::string toString() {
            return head->toString();
        }
        friend std::ostream& operator<<(std::ostream& os, DList& list) {
            item_ptr obj = list.head;
            if (obj)
                obj->print(os);
            else os<< "NULL";
            return os;
        }

    private:
        item_ptr getItemAt(const int i) const; 
    private:
        item_ptr head;
        item_ptr tail;
        int size;
};

#include "DList.tpp"

#endif